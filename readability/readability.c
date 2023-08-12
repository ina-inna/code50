#include <cs50.h>
#include <stdio.h>
#include <string.h>



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
            printf("%d", count);

        }
        printf("%d", count);

    }


        // char c = text[i];
        // int count = 0;

        //     for (int j = 0; j != '\0'; j++)
        //     {
        //          if (text[i] = char)

        //     {
        //         count++;
        //     }
        //     }
        //     return 0;
        //     printf("%d", count);


    // count and print words
    //    int count_words(string text);


    // count and print sentences

    // compute a grade using the given formula



}