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

    {
        for (int i = 0; i < length; i++)
        int binary[32];
            int x = 0;

            while (word[i] > 0)
        {
            binary[x] = number % 2;
            number /= 2;
            x++;
        }
             printf("%d", binary[x]);
            }
            printf("\n");


}

    






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
