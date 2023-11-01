
while n < 1 or answer > 8:
    answer = input("Height:\n")
n = int(answer)

for row in range (n):
    for space in range (n-1, n, -1):
        print(" ")
    for block in range (1, n):
        print("#")
