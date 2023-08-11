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
        int binary[BITS_IN_BYTE];
            int x = 0;

            while (number > 0)
        {
            binary[x] = number % 2;
            number /= 2;
            x++;
        }
            for (int j = x - 1; j >=0; j--)
            {
            if (binaryj == 0)
            printf("\U000026AB");
            }
            {
            else
            printf("\U0001F7E1");
            }

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
