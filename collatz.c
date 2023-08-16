#include <cs50.h>
#include <stdio.h>
#include <string.h>

int collatz(int number);

int main(void)
{
    int number = get_int("Number: ");
    collatz(number);
}


int collatz(int number)
{
    int i = 0;
    i++;
    {
    if (number == 1)
    {
        printf("%i", i+1);
        return 0;
    }
    else if (number%2 == 0)
    {
        number = number/2;
    }
    else
    {
        number = 3 * number + 1;
    }
    collatz(number);
    }
    printf("%i ", i);
    return i;
}