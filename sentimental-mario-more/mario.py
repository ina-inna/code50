n = input("Height: ")
while int(n) < 1 or int(n) > 8:
    n = input("Height: ")
for row in range (n+1):
    print(" "*(n - row) + "#"*row + " " + "#" * row)


