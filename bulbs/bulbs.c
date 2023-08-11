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
        int number = (int)c;
        int bit[BITS_IN_BYTE] = {0};
            int x = 0;

            while (number > 0)
        {
            bit[x] = number % 2;
            number /= 2;
            x++;


        }
            for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
           {
                print_bulb(bit[j]);
           }
            printf("\n");
    }
            printf("\n");
            return 0;
}


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
