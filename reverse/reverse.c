#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);
long int position;

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

    position = ftell(inptr);
    if (position == -1L) {
        printf("Error getting file %s position\n", input);
        return 3;
    }
    printf("%li\n", position);

    // Use check_format to ensure WAV format
    // DONE #4
   int result = check_format(header);


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
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8

    int end = fseek(inptr, 0, SEEK_END);

    {

        if (end == 0)
        {
            long int file_size = ftell(inptr);

            int16_t audioData;
            long int current_position = file_size;
            printf("%li\n", current_position);

            // write blocks to outfile

                fseek(inptr, -block_size, SEEK_END);
                for (int i = current_position; i >= position; i--)

                {
                    if (fread(&audioData, 2, 1, inptr) == 1)
                    {
                            int16_t buffer = audioData;
                        fwrite(&buffer, sizeof(int16_t), 1, outptr);
                    }

                    else
                    {
                        printf("Error when reading file %s\n", input);
                    }
                    fseek(inptr, -2 * block_size, SEEK_CUR);
                }


                // close infile
                fclose(inptr);

                // close outfile
                fclose(outptr);

                return 0;
            }


        else

            {
                printf("Error when reaching end of file %s\n", input);
            }

    }




}

int check_format(WAVHEADER header)
{
    // TODO #4

    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
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
    int block_size = ((header.bitsPerSample/8) * header.numChannels);
    printf("%i %i %i\n", block_size, header.bitsPerSample, header.numChannels);

    return block_size;
}