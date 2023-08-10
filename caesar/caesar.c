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
    // only digits
    int only_digits(argv[1]);
    

    // prompt user to type a phrase

    //

}