#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count(string text);

int main(void)
{
    // prompt user for an input
    string text = get_string("Text: ");

    // count and print letters
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z' )
        {
            count++;
        }
    }
         printf("%d", count);


    // count and print words

    // count and print sentences

    // compute a grade using the given formula


    //    int count_words(string text);

    int count_letters(string text)
}