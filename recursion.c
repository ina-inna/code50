#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    draw(1);
}

void draw(int n)
{
    draw(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}