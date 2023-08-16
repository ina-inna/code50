#include <cs50.h>
#include <stdio.h>
#include <string.h>

int collatz(int number);


int main(void)
{
    int i = 0;
    int number = get_int("Number: ");
    collatz(number);
    printf("%i ", i);
}


int collatz(int number)

{
{
    i++;
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
    return i;
}