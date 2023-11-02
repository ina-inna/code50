def main()

    #prompt user for an input
    text = input("Text: ")

    #count and print letters
    count_letters(text);
    #count and print words
    count_words(text);
    #count and print sentences
    count_sentences(text);

    #compute a grade using the given formula
    float letters = (float) count_letters(text)
    float words = (float) count_words(text)
    float sentences = (float) count_sentences(text)

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


def count_words(user_text)

    int count = 0
    for i in range len(user_text)
        if user_text[i] == ' ' or (text[i] == '\0'))
           count += 1
    return count


int count_sentences(string text)
{
    int count = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            count++;
        }
    }
    printf("%d", count);
    return count;
}