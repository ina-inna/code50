#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);




int main(void)
{
    // TODO
    // get users input
    string word = get_string("Message: ");

    // get the length of the message
    int length = strlen(word);
    int byte = word[i]


    int binary[32];
    int i = 0;

    while (byte > 0)
{
    binary[i] = number % 2;
    number /= 2;
    i++;
}

 for (int j = i - 1; j >= 0; j--)
 {
        printf("%d", binary[j]);
    }
    printf("\n");
}


    // convert user's input into binary
    for (int i = 0; i < length; i++)
    {
      printf("%d", word[i]);

      printf("\n");
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
