#include <cs50.h>
#include <stdio.h>
#include <string.h>

int collatz(int number);


int main(void)
{
    int number = get_int("Number: ");
    int res = collatz(number, i);
    printf("%i\n", i);
}



int collatz(int number)
{
    if (number == 1)
    {
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

    return 1 + collatz(number, i);
}
