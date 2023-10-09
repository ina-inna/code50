#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check the number of command lines

    if (argc != 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    int check_usage = int only_digits(string argv[1]);

}


    // check the key - function only_digits


    // convert argv to an integer


    // prompt the user for a text


    // function rotate: rotates characters by that many positions


    // print the cipher text

only_digits(argv[1])

{
    string input = argv[1];
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}

