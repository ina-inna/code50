#include <cs50.h>
#include <stdio.h>

int main() {
    printf("x equals y\n");
    return 0;
}

int main1(void)
{
   int x = get_int("What's x?\n ");
   int y = get_int("what's y?\n ");

   if (x < y)
   {
    printf("x is less than y\n");
   }
   else if (x > y)
   {
    printf("x is greater than y\n");
   }
   else if (x == y)
   {
      main();
   }
   return 0;
}