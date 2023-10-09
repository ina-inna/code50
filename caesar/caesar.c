#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


bool only_digits(string input);

int main(int argc, string argv[])
{
    // check the number of command lines

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

 // check the key - function only_digits

    bool check_usage = only_digits(argv[1]);

    if (check_usage == true)
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key2\n");
        return 1;
    }

    // convert argv to an integer

    int key = atoi(argv[1]);
    printf("%i\n", key);


}

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
    return true;
}

