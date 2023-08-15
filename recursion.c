#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    draw(n + 1);
}