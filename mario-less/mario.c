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
  while ( n < 1 && n > 8);

  // Print grid of bricks
    for (int i = 0; i < n; i++)
    { printf("#");

{
        for (int j = i + j; j < n; j++)
{
    printf(".");
}
    printf("\n");
}
}

}