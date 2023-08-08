#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    do
   {
        length = get_int("Length:");
   }
    while (length < 1);

    int array[length] = {1, };
    for (int i = 0; i < length; i++)
    {
            printf("%i", array[length]);

    }
    printf("\n");
}