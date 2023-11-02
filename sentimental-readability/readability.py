def main():
    #prompt user for an input
    text = input("Text: ")

    #compute a grade using the given formula
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    l = (letters / words) * 100
    s = (sentences / words) * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    if index > 16:
        printf("Grade 16+\n")

    elif index < 1:
        print("Before Grade 1\n")

    else:
        rounded = (int) round(index)
        printf(f"Grade {rounded}\n")


def count_letters(user_text):

    count = 0
    for i in range len(user_text)
        if user_text[i] >= 'a' and user_text[i] <= 'z' or user_text[i] >= 'A' and user_text[i] <= 'Z'
        count += 1
    return count


def count_words(user_text):
    int count = 0
    for i in range len(user_text)
        if user_text[i] == ' ' or text[i] == '\0'
           count += 1
    return count


def count_sentences(user_text):
    int count = 0
    for i in range len(user_text)
        if user_text[i] == '.' or user_text[i] == '!' or user_text[i] == '?'
            count += 1
    return count

main()
