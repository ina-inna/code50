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

    if (n >= 0 && n <= 1)
    {
        int num = input[n - 1] - '0';
        return num;
    }
    else
    {
    int num = input[n - 1] - '0';

        // convert(input[n-1]);
        input[n - 1] = '\0';
        int last = (input[n - 2] - '0') * 10;

    return num + last;
    }

}