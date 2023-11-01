
n = input("Height:\n")
n = int(n)
if n < 1 or n > 8:
    n = input("Height:\n")

for row in range (n):
    for space in range (0, n - row, -1):
        print(" ")
    for block in range (0, n):
        print("#")
    print("")
