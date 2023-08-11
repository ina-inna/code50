#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);



int main(void)
{

    // get users input
    string word = get_string("Message: ");

    // get the length of the message
    int length = strlen(word);

    // convert the message into ascii
    for (int i = 0; i < length; i++)
    {
        char c = word[i];
        int bit = (int)c;
        int binary[8];
            int x = 0;

            while (bit > 0)
        {
            binary[x] = bit % 2;
            bit /= 2;
            x++;
        }
            for (int j = x - 1; j >=0; j--)
            {
             printf("%d", binary[j]);
            }
            printf("\n");
    }
            printf("\n");
            return 0;
}



    // {
    //     for (int i = 0; i < length; i++)
    //     int binary[32];
    //         int x = 0;

    //         while (word[i] > 0)
    //     {
    //         binary[x] = number % 2;
    //         number /= 2;
    //         x++;
    //     }
    //          printf("%d", binary[x]);
    //         }
    //         printf("\n");











    // // convert user's input into binary
    // for (int i = 0; i < length; i++)
    // {
    //   printf("%d", word[i]);

    //   printf("\n");
    // }



void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
