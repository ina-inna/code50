while True:
    n = input("Height: ")
    if not n.isdigit():
        n = input("Height: ")
    elif int(n) >= 1 or int(n) <= 8:
        n = int(n)
        for row in range (n+1):
            print(" " * (n - row) + "#" * row + " " + "#" * row)
            break
    else:
       n = input("Height: ")



