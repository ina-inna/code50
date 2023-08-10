#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // let user input just 1 number
    if (argc <= 2)
    {
        printf("%s\n", argv[1]);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");\
        return 1;
    }
    // check if argv[1] is only digits
    bool only_digits(argv[1]);
    int length = strlen(argv[1]);

    // convert argv[1] from a string to an int

    // prompt user to type a phrase

    // for each character in the phrase

        // rotate the character if it's a letter

}