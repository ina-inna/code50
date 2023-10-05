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
    char *output = argv[2];

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
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, inptr);


    // Use check_format to ensure WAV format
    // DONE #4
    check_format(header);

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
    // Done#6

    fwrite(&header, sizeof(WAVHEADER), 1, outptr);


    // Use get_block_size to calculate size of block
    // Done #7
    get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    int num = header.subchunk2Size / get_block_size;

     for (int i = num; i < 0; i--)
    {
        // write blocks to outfile
        fwrite(image[i], sizeof(WAVHEADER), num, outptr);

    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;

}

int check_format(WAVHEADER header)
{
    // TODO #4

    if (header.format[0] == 'W' && header.format[0] == 'A' && header.format[0] == 'V' && header.format[0] == 'E')
    {
    return 0;
    }

    else
    {
        return 4;
    }
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.bitsPerSample * header.numChannels;

    return block_size;
}