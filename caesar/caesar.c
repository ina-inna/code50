#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


bool only_digits(string input);

int main(int argc, string argv[])
{
    // check the number of command lines

    if (argc != 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    bool check_usage = only_digits(argv[1]);

    if (check_usage == true)
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}


    // check the key - function only_digits


    // convert argv to an integer


    // prompt the user for a text


    // function rotate: rotates characters by that many positions


    // print the cipher text

bool only_digits(string input)

{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    else
    {
    return true;
    }
}

