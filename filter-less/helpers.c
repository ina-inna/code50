#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            {
                int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);

                image[i][j].rgbtBlue = avg;
                image[i][j].rgbtGreen = avg;
                image[i][j].rgbtRed = avg;

            }
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

   for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            {
                RGBTRIPLE pixel = image[i][j];
                int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
                if (sepiaRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = sepiaRed;
                }

                int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);

                 if (sepiaGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                 else
                {
                    image[i][j].rgbtGreen = sepiaGreen;
                }

                int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

                 if (sepiaBlue > 255)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = sepiaBlue;
                }
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width / 2; j++)


            {
                    RGBTRIPLE *pixel = &image[i][j];
                    RGBTRIPLE *pixel2 = &image[i][width - 1 - j];
                    RGBTRIPLE temp = *pixel;

                    *pixel = *pixel2;
                    *pixel2 = temp;
            }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
 RGBTRIPLE copy[height][width] = image[height][width];
 for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {

            {
               int blur1 = round((copy[i][j].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue) / 9.0);
               int blur2 = round((copy[i][j].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen) / 9.0);
               int blur3 = round((copy[i][j].rgbtRed + copy[i][j-1].rgbtRed + copy[i][j+1].rgbtRed + copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed) / 9.0);


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;

            }
        }
    }


        for (int j = 1; j < width; j++)

        {
            int i = 0;
            int blur1 = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
            int blur2 = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);
            int blur3 = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;
        }

         for (int j = 1; j < width; j++)

        {
            int i = height;
            int blur1 = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue) / 6.0);
            int blur2 = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen) / 6.0);
            int blur3 = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed) / 6.0);


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;
        }

                 for (int i = 1; i < height; i++)

        {
            int j = 0;
            int blur1 = round((image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
            int blur2 = round((image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);
            int blur3 = round((image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;
        }


                for (int i = 1; i < height; i++)

        {
            int j = width;
            int blur1 = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue) / 6.0);
            int blur2 = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen) / 6.0);
            int blur3 = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed) / 6.0);


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;
        }

    int blur01 = round((image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][1].rgbtBlue + image[1][0].rgbtBlue) / 4.0);
    int blur02 = round((image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][1].rgbtGreen + image[1][0].rgbtGreen) / 4.0);
    int blur03 = round((image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][1].rgbtRed + image[1][0].rgbtRed) / 4.0);

    image[0][0].rgbtBlue = blur01;
    image[0][0].rgbtGreen = blur02;
    image[0][0].rgbtRed = blur03;



    int blur1 = round((image[height][0].rgbtBlue + image[height][1].rgbtBlue + image[height-1][1].rgbtBlue + image[height-1][0].rgbtBlue) / 4.0);
    int blur2 = round((image[height][0].rgbtGreen + image[height][1].rgbtGreen + image[height-1][1].rgbtGreen + image[height-1][0].rgbtGreen) / 4.0);
    int blur3 = round((image[height][0].rgbtRed + image[height][1].rgbtRed + image[height-1][1].rgbtRed + image[height-1][0].rgbtRed) / 4.0);

    image[height][0].rgbtBlue = blur1;
    image[height][0].rgbtGreen = blur2;
    image[height][0].rgbtRed = blur3;

    int blur11 = round((image[0][width].rgbtBlue + image[0][width-1].rgbtBlue + image[1][width].rgbtBlue + image[1][width-1].rgbtBlue) / 4.0);
    int blur12 = round((image[0][width].rgbtGreen + image[0][width-1].rgbtGreen + image[1][width].rgbtGreen + image[1][width-1].rgbtGreen) / 4.0);
    int blur13 = round((image[0][width].rgbtRed + image[0][width-1].rgbtRed + image[1][width].rgbtRed + image[1][width-1].rgbtRed) / 4.0);

    image[0][width].rgbtBlue = blur11;
    image[0][width].rgbtGreen = blur12;
    image[0][width].rgbtRed = blur13;


    int blur10 = round((image[height][width].rgbtBlue + image[height][width-1].rgbtBlue + image[height-1][width].rgbtBlue + image[height-1][width-1].rgbtBlue) / 4.0);
    int blur20 = round((image[height][width].rgbtGreen + image[height][width-1].rgbtGreen + image[height-1][width].rgbtGreen + image[height-1][width-1].rgbtGreen) / 4.0);
    int blur30 = round((image[height][width].rgbtRed + image[height][width-1].rgbtRed + image[height-1][width].rgbtRed + image[height-1][width-1].rgbtRed) / 4.0);

    image[height][width].rgbtBlue = blur10;
    image[height][width].rgbtGreen = blur20;
    image[height][width].rgbtRed = blur30;



    return;
}
