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

// int convert_helper(string input, int original_length)
// {
// int n = strlen(input);
// int position = original_length - n;
//     // if (n >= 0 && n <= 1)
//     // {
//     //     int num = input[n - 1] - '0';
//     //     return num;
//     // }
//     // // if it's >1 digit string
//     // else
//     // {
//     int num = input[n - 1] - '0';   // define last digit


//         input[n - 1] = '\0';        // truncate the string by 1
//         // int last = (input[n - 2] - '0') * 10;       // value of the n - 2 digit
//         // int sum = num + last;
//         return num + (input[n - 2] - '0') * 10;
// }