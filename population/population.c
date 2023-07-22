#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int n;
  do
  {
    n = get_int("Start size: ");
  }
  while (n < 9);

    // TODO: Prompt for end size
    int z;
  do
  {
    z = get_int("End size: ");
  }
  while (z > n);


    // TODO: Calculate number of years until we reach threshold

do
{
    n = n + (n/3) - (n/4);
}
while (n == z);
    // TODO: Print number of years
    printf("Years: %i\n", n);
}
