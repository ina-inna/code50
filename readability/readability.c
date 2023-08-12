#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for an input
    string text = get_string("Text: ");

    // count and print letters
    int count_letters(string text);

    // count and print words
       int count_words(string text);


    // count and print sentences

    // compute a grade using the given formula



        int count_letters(string text)
        {
            int count = 0;
            for (int = 0; text[i] != '\0'; i++)
            {
                if (text[i] == " ")
                {
                    count++;
                }
            }
            return count;
            printf(" ", count);
        }
}