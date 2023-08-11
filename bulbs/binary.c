#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
int number = get_int("your number: ");

int binary[32];
int i = 0;

while (number > 0)
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

    int length = strlen(binary)

    for (int bit; bit < length; bit++)

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

