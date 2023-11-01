
n = input("Height:\n")
n = int(n)
if n < 1 or n > 8:
    n = input("Height:\n")

for row in range (n):
    for space in range (n-1, n, -1):
        print(" ")
    for block in range (1, n):
        print("#")
