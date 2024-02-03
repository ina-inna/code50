# prompt for user input
def main():
    card_number = input("Number: ")

    # check if it's valid for mastercard
    if len(card_number) not in (13, 15, 16):
        print("INVALID")

    # or for mastercard
    elif (
        len(card_number) == 16
        and card_number[0] == "5"
        and card_number[1] in ("1", "2", "3", "4", "5")
    ):
        final_sum = calculate_sum(card_number)
        if final_sum % 10 == 0:
            print("MASTERCARD")
        else:
            print("INVALID")

    elif (
        len(card_number) == 15
        and card_number[0] == "3"
        and card_number[1] in ("4", "7")
    ):
        final_sum = calculate_sum(card_number)
        if final_sum % 10 == 0:
            print("AMEX")
        else:
            print("INVALID")

    elif len(card_number) in (13, 16) and card_number[0] == "4":
        final_sum = calculate_sum(card_number)
        if final_sum % 10 == 0:
            print("VISA")
        else:
            print("INVALID")

    else:
        print("INVALID")


# function for sum calculation


def calculate_sum(number):
    n = len(number)
    sum_of_numbers_1 = 0
    for i in range(n - 2, -1, -2):
        digit = int(number[i])
        x = digit * 2
        if x > 9:
            sum_of_numbers_1 += x // 10 + x % 10
        else:
            sum_of_numbers_1 += x
        print(f"{sum_of_numbers_1}")

    sum_of_numbers_2 = 0
    for i in range(n - 1, -1, -2):
        digit = int(number[i])
        sum_of_numbers_2 += digit
        print(f"{sum_of_numbers_2}")

    result = sum_of_numbers_1 + sum_of_numbers_2
    return result


main()

# or for american express

# write Luhn's algorithms

# print card's name