#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    // get users input
    string message = get_string("Message: ");

    // get the length of the message
    int length = strlen(message);

    // convert user's input into binary
    for (int i = 0; i < length; i++)
    {
      
    }

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
