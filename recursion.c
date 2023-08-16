#include <cs50.h>
#include <stdio.h>
#include <string.h>

void draw(int n);
void draww(int m);

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
void draww(int m)
{
   if (m <= 0)
    {
        return;
    }
    draw1(m - 1);
    for (int i = 0; i < m; i++)
    {
        printf("#");
    }
    printf("\n");
}
