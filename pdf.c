#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.");
        return 1;
    }

    // open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // check if file exists
    if (file == NULL)
    {
        print("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4];
    fread(buffer, 1, 4, )
}