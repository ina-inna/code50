#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int convert_helper(string input, int original_length);

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
    int n = strlen(input);
    // base case;
    if (n == 0)
    {
        return 0;
    }
    int num = (input[n - 1] - '0');
    // shortening the string
    input[n - 1] = '\0';

    int remainingValue = convert(input);
    int result = remainingValue * 10 + num;

    return result;

}
