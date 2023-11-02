# prompt for user input
card_number = input("Number: ")

# check if it's valid for mastercard
if len(card_number) not in (13, 15, 16):
    print("INVALID")

# or for visa
elif len(card_number) == 16 and card_number[0] == '5' and card_number[1] in ('1', '2', '3', '4', '5'):
    n = len(card_number)
    sum_of_numbers_1 = 0
    card_number = int(card_number)
    for i in range (n-1, 0, -2):
        x = card_number[i] * 2
        if x > 9:
            sum_of_numbers += x
        else:
            sum_of_numbers = x/10 + x % 10

    sum_of_numbers_2 = 0
    for i in range (n, 0, -2):
        sum_of_numbers_2 += card_number[i]

    final_sum = sum_of_numbers_1 + sum_of_numbers_2
    if final_sum % 10 == 0:
        print("MASTERCARD\n")



# or for american express

# write Luhn's algorithms

# print card's name