#include <cs50.h>
#include <stdio.h>
#include <string.h>

int collatz(int number, int i);


int main(void)
{
    int i = 0;
    int number = get_int("Number: ");
    i = collatz(number, i);
    printf("%i", i);
}



int collatz(int number, int &i)
{

    i++;

    if (number == 1)
    {
        return i;
    }
    else if (number%2 == 0)
    {
        number = number/2;
    }
    else
    {
        number = 3 * number + 1;
    }

    collatz(number, i);
    return i;
}
