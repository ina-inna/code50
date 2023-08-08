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

    int array[length];
    array[0] = 1;
    for (int i = 0; i < length; i++)
    array[0] = 1;

    {
            printf("%i\n", array[length]);

    }
    printf("\n");
}