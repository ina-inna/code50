#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
int number = get_int("your number: ")

int binary[32];
int i = 0

while (number > 0)
{
    binary[i] = number % 2;
    number /= 2;
    i++;
}

 for (int j = i - 1; j >= 0; j--)
 {
        printf("%d", binary[j]);
    }
    printf("\n");

}