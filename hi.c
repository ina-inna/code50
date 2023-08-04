#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%c%c%c\n", words[0]);
    printf("%c%c%c%c\n", words[1]);
}