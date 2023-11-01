
n = input("Height:\n")
n = int(n)
if n < 1 or n > 8:
    n = input("Height:\n")

for row in range (0, n):
    #for space in range (row):
    print(" " * (n - row) + "#" * row + " " + "#" * row)


