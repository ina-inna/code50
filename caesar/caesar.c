#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


bool only_digits(string input);
char rotate(char letter, int number);

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

    if (check_usage != true)
    {
        printf("Usage: ./caesar key2\n");
        return 1;
    }


    // convert argv to an integer
    string input = argv[1];
    int key = atoi(input);

    // prompt the user for a text

    string text = get_string("plaintext: ");

    printf("Ciphertext: ");

    // function rotate: rotates characters by that many positions
    // print the cipher text

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c", rotate(text[i], key));
    }
     printf("\n");

    return 0;

}


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

char rotate(char letter, int number)
{
    if (letter >= 'A' && letter <= 'Z')
        {
            letter += number;
            //letter = (letter) % 26;
        }
    else if (letter >= 'a' && letter <= 'z')
        {
            letter += number;
            //letter = (letter) % 26;
        }
    else
        {
            return letter;
        }
    return letter;
}

