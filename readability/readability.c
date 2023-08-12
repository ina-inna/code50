#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt user for an input
    string text = get_string("Text: ");

    // count and print letters
    count_letters(text);
    count_words(text);
    count_sentences(text);

    int l = count_letters / count_words;
    int s = count_words / count_sentences;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    if (index > 16)
    {
        printf("Grade 16+");
    }
    else if(index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %d\n", round(index));
    }
}

    // count and print words

    // count and print sentences

    // compute a grade using the given formula


    //    int count_words(string text);

    int count_letters(string text)
    {
         int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count++;
        }
    }
         printf("Letters: %d\n", count);
         return count;
    }

    int count_words(string text)
    {
         int count = 0;
         int length = strlen(text);
         for (int i = 0; i <= length; i++)
    {
        if ((text[i] == ' ') || (text[i] == '\0'))
        {
            count++;
        }
    }
         printf("Words: %d\n", count);
         return count;
    }


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
         printf("Sentences: %d\n", count);
         return count;
    }