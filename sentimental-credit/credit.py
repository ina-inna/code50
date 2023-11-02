# prompt for user input
card_number = input("Number: ")

# check if it's valid for mastercard
if len(card_number) is not (13, 15, 16):
    print("INVALID")

# or for visa
elif len(card_number) is 16 and card_number[0] + card_number[1] is (51, 52, 53, 54, 55):
    n = len(card_number)
    list_of_numbers = []
    for i in range (n-1, 0, -2):
        card_number[i] = card_number[i] * 2
        list_of_numbers.append(card_number[i])
        for n

# or for american express

# write Luhn's algorithms

# print card's name