while True:
    n = input("Height: ")
    if not n.isdigit():
        n = input("Height: ")
    elif n.isdigit() and int(n) < 1 or int(n) > 8:
        n = input("Height: ")
    else:
        n = int(n)
        for row in range (n+1):
            print(" " * (n - row) + "#" * row + " " + "#" * row)
            break



