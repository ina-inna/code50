#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt user for an input
    string text = get_string("Text: ");

    // count and print letters
    count_letters(text);
    // count and print words
    count_words(text);
    // count and print sentences
    count_sentences(text);


  // compute a grade using the given formula
        int letters = count_letters(text);
        int words = count_words(text);
        int sentences = count_sentences(text);


        int l = (letters/ words)*100;
        printf("%d\n", l);
        int s = (sentences / words)*100;
        printf("%d\n", s);
        float index = 0.0588 * l - 0.296 * s - 15.8;
        printf("%f\n", index);
        if (index > 16)
        {
            printf("Grade 16+\n");
        }
        else if(index < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {

            int rounded = (int)round(index);
            printf("Grade %d\n", rounded);
        }
}



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
        printf("%d", count);
         return count;
    }