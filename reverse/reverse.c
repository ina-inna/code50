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

    long int position = ftell(inptr);
    if (position == -1L) {
        printf("Error getting file %s position\n", input);
        return 3;
    }


    // Use check_format to ensure WAV format
    // DONE #4
   int result = check_format(header);
   if (result == 0)
   {
        return 0;
   }
   else
   {
        return 4;
   }

    // Open output file for writing
    // DONE #5

    FILE *outptr = fopen(output, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", output);
        return 3;
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
    int block_size = (header.bitsPerSample * header.numChannels)/8;

    return block_size;
}