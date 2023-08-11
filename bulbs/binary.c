#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
int number = get_int("your number: ");

int binary[32];
int i = 0;


   if (number == 0) {
        printf("Binary representation: 0b0\n");
        return;
    }

while (number > 0)
{
    binary[i] = number % 2;
    number /= 2;
    i++;
}

    printf("Binary representation: 0b");
 for (int j = i - 1; j >= 0; j--)
 {
    if (binary[j] == 0)
    {
          printf("\U000026AB");
    }
       else if (binary[j] == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }

    }
    printf("\n");



}

