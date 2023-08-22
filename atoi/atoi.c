#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO

    // define last character in a string
    int n = strlen(input);
    char c = input[n-1];
    int num = c - '0';
    while (n > 0)
    {
        input[n - 1] = '\0';
    }

    // transform it into integer

    // recursive function to transform every char into integer
}