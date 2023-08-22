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

        int numbers(int last)
        {
        input[n - 1] = '\0';
        char last_char = input[n - 2];
        int last = (last_char - '0') * 10;
        return last + numbers(last)
        }

    return num + numbers;

    // transform it into integer

    // recursive function to transform every char into integer
}