#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // DONE #1

    if (argc != 3)
    {
        printf("Usage: reverse input output\n");
        return 1;
    }

      // remember filenames
    char *input = argv[1];
    char *outout = argv[2];

    // Open input file for reading
    // DONE #2

    FILE *inptr = fopen(input, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", input);
        return 2;
    }


    // Read header
    // DONE #3
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, inptr);


    // Use check_format to ensure WAV format
    // TODO #4

    // Open output file for writing
    // DONE #5

    FILE *outptr = fopen(output, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", output);
        return 3;
    }

    // Write header to file
    // TODO #6

    fwrite(&wh, sizeof(WAVHEADER), 1, outptr);


    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}