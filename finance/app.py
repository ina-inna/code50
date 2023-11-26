import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_stocks = db.execute("SELECT stock, SUM (number_shares) AS total_shares FROM purchases WHERE id_user = ? GROUP BY stock HAVING SUM (number_shares) > 0", session.get("user_id"))
    if not user_stocks:
        return apology("no stocks in your portfolio", 403)
    else:

        for stock in user_stocks:
            request_for_stock = lookup(stock["stock"])
            current_price = request_for_stock["price"]
            total_value = current_price * stock['total_shares']
            stock.update({
                "current_price": current_price,
                "total_value": total_value
            })
        raw_cash = db.execute("SELECT cash FROM users where id = ?", session.get("user_id"))
        float_cash = raw_cash[0]['cash']
        current_cash = usd(raw_cash[0]['cash'])
        grand_total = usd(float_cash + sum(stock['total_value'] for stock in user_stocks))
        return render_template("index.html", user_stocks = user_stocks, current_cash = current_cash,  grand_total = grand_total)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("must provide stock's symbol", 403)
        elif not lookup(request.form.get("symbol")):
            return apology("stock symbol doesn't exist", 403)

        # Ensure number of shares was submitted
        elif request.form.get("shares") is None or int(request.form.get("shares")) < 0:
            return apology("must provide number of shares", 403)

        # check if cash is enough
        stock = lookup(request.form.get("symbol"))
        cost = stock["price"]*int(request.form.get("shares"))
        user = db.execute("SELECT * FROM users WHERE id = ?", session.get("user_id"))

        if cost > user[0]["cash"]:
            return apology("not enough cash", 403)
        else:
            # update cash remaining in the database users
            new_cash = user[0]["cash"] - cost
            db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session.get("user_id"))

            # if enough insert information about a purchase into a database
            db.execute("INSERT INTO purchases (id_user, stock, number_shares, price_per_share, timestamp_column) VALUES(?, ?, ?, ?, CURRENT_TIMESTAMP)", session.get("user_id"), request.form.get("symbol"), int(request.form.get("shares")), stock["price"])


        return redirect("/")

    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_purchases = db.execute("SELECT * FROM purchases WHERE id_user = ?", session.get("user_id"))
    if not user_purchases:
        return apology("there are no transactions to display", 403)
    else:
        return render_template("history.html", user_purchases = user_purchases)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not lookup(request.form.get("symbol")):
            return apology("stock symbol doesn't exist", 403)
        else:
            stock = lookup(request.form.get("symbol"))
            return render_template("quoted.html", name = stock["name"], price = stock["price"], symbol = stock["symbol"])
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

         # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password was submitted
        elif not request.form.get("confirmation"):
            return apology("must retype password", 400)

         # Ensure passwords match
        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("passwords should match", 400)


        # Query database for username
        existing_user = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if existing_user:
            return apology("username already taken", 200)

        # Add the user to the database
        username = request.form.get("username")
        hashed_password = generate_password_hash(request.form.get("password"))


        # Remember registrant
        user_id = db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hashed_password)

        # Remember which user has logged in
        session["user_id"] = user_id

        return redirect("/")

    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        if not request.form.get("share_to_sell"):
            return apology("must provide stock's symbol", 403)
        if not request.form.get("shares"):
            return apology("must provide quantity of shares", 403)

        # Ensure number of shares is correct
        user_stocks = db.execute("SELECT stock, SUM (number_shares) AS total_shares FROM purchases WHERE id_user = ? AND stock = 'share_to_sell' GROUP BY stock HAVING SUM (number_shares) > 0", session.get("user_id"))
        if int(request.form.get("shares")) > int(user_stocks[0]['total.shares']):
            return apology("insufficient funds", 403)
        else:
            # update cash remaining in the database users
            stock = lookup(request.form.get("share_to_sell"))
            cost = stock["price"]*int(request.form.get("shares"))
            user = db.execute("SELECT * FROM users WHERE id = ?", session.get("user_id"))

            new_cash = user[0]["cash"] + cost
            db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session.get("user_id"))

            # if enough insert information about a purchase into a database
            db.execute("INSERT INTO purchases (id_user, stock, number_shares, price_per_share, timestamp_column) VALUES(?, ?, ?, ?, CURRENT_TIMESTAMP)", session.get("user_id"), request.form.get("symbol"), int(request.form.get("shares")), stock["price"])


        return redirect("/")


    else:
        stocks = db.execute("SELECT DISTINCT stock FROM purchases WHERE id_user = ?", session.get("user_id"))
        return render_template("sell.html", stocks = stocks)