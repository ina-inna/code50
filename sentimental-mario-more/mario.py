
n = input("Height:\n")
n = int(n)
if n < 1 or n > 8:
    n = input("Height:\n")

for row in range (n+1):
    #for space in range (row):
    print(" " * (n - row) + "#" * row + " " + "#" * row)


