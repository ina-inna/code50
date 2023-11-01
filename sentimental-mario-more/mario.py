while True:
    n = input("Height: ")
    if not n.isdigit():
        print("Invalid input. Please enter an integer between 1 and 8.")
    elif int(n) < 1 or int(n) > 8:
        print("Invalid input. Please enter an integer between 1 and 8.")
    elif int(n) >= 1 or int(n) <= 8:
        n = int(n)
        break


for row in range(n):
    print(" " * (n - row - 1) + "#" * (row + 1) + "  " + "#" * (row + 1))
