#include <cs50.h>
#include <stdio.h>

int main(void)
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
    printf("x equals y\n");
    
   }
}