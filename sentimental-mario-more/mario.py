n = input("Height: ")
n = int(n)
if n < 1 or n > 8:
    n = input("Height: ")
for row in range (n+1):
    print(" "*(n - row) + "#"*row + " " + "#" * row)


