#include <cs50.h>
#include <stdio.h>
#include <string.h>

void draw(int n);
void draww(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
    draww(height);
}

void draw(int n)

{
   if (n <= 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    draw(n - 1);

}
void draww(int n)
{
   if (n <= 0)
    {
        return;
    }
    draww(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
