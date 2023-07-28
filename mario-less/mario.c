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
  while ( n < 1 || n > 8);

  // Print grid of bricks

    for (int row = 0; row < n; row++)
    { printf("#");
        for (int column = 1; column < n; column++)
{
    printf(" ");
}

{

    printf("#\n");
}
}

}