#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main(void)
{
    // prompt user for an input
    string text = get_string("Text: ");

    // count and print letters


            int length = strlen(text);

            for (int i = 0; i < length; i++)
            {
                 char c = text[i];
                 int count = 0;
                 if (c == ' ')

            {
                count++;
            }
            }
            return 0;
            printf("%d", count);


    // count and print words
    //    int count_words(string text);


    // count and print sentences

    // compute a grade using the given formula



}