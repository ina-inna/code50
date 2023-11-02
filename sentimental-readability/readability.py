import re

def main():
    #prompt user for an input
    text = input("Text: ")

    #compute a grade using the given formula
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    l = round((letters / words) * 100)
    print(l)
    s = round((sentences / words) * 100)
    print(s)
    index = 0.0588 * l - 0.296 * s - 15.8
    print(index)
    if index > 16:
        print("Grade 16+\n")

    elif index < 1:
        print("Before Grade 1\n")

    else:
        rounded = round(index)
        print(f"Grade {rounded}")


def count_letters(user_text):

    count = 0
    for i in range (len(user_text)):
        if user_text[i] >= 'a' and user_text[i] <= 'z' or user_text[i] >= 'A' and user_text[i] <= 'Z':
            count += 1
    print(count)
    return count


def count_words(user_text):
    count = 0
    for i in range (len(user_text)):
        if user_text[i] == ' ' or user_text[i] == 'U+0027ve':
            count += 1
    print(count)
    return count


def count_sentences(user_text):
    count = 0
    for i in range (len(user_text)):
        if user_text[i] == '.' or user_text[i] == '!' or user_text[i] == '?':
            count += 1
    print(count)
    return count

main()
