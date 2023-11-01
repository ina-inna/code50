while True:
    n = input("Height: ")
    if not n.isdigit():
        n = input("Height: ")
    elif int(n) >= 1 or int(n) <= 8:
        n = int(n)
        break
    else:
       n = input("Height: ")

for row in range(n):
    print(" " * (n - row - 1) + "#" * (row + 1) + "  " + "#" * (row + 1))

