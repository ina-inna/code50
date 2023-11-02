# prompt for user input
card_number = input("Number: ")

# check if it's valid for mastercard
if len(card_number) is not (13, 15, 16):
    print("INVALID")

# or for visa
elif len(card_number) is 16 and card_number[0] + card_number[1] is (51, 52, 53, 54, 55):
    for i in range (0, len(card_number), 2):
        

# or for american express

# write Luhn's algorithms

# print card's name