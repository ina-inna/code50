#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get size of grid
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    // Print grid of bricks

    for (int row = 0; row < n; row++)
    {
        for (int space = 0; space < n - row; space++)
        {
            printf(" ");
        }

        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf(" ");

        for (int column2 = 0; column2 <= row; column2++)
        {
            printf("#");
        }
        printf("\n");
    }
}