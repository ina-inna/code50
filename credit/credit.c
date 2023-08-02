#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

// Number is ok, print VISA

    if (number % 10 = 0)
   {
    printf("VISA\n");
   }

// Number is not ok, print Invalid
    else
    {
     printf("Invalid\n");
    }
}