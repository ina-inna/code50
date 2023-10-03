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
        // add the code to cap the values - max 255

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

 for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {

            {
               int blur1 = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9);
               int blur2 = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9);
               int blur3 = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9);


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;

            }
        }
    }

    for (int i = 0; i < 2; i++)

    {
            for (int j = 1; j < width; j++)

        {
                int blur1 = round((image[0][j].rgbtBlue + image[0][j-1].rgbtBlue + image[0][j+1].rgbtBlue + image[1][j-1].rgbtBlue + image[1][j].rgbtBlue + image[1][j+1].rgbtBlue) / 6);
               int blur2 = round((image[0][j].rgbtGreen + image[0][j-1].rgbtGreen + image[0][j+1].rgbtGreen + image[1][j-1].rgbtGreen + image[1][j].rgbtGreen + image[1][j+1].rgbtGreen) / 6);
               int blur3 = round((image[0][j].rgbtRed + image[0][j-1].rgbtRed + image[0][j+1].rgbtRed + image[1][j-1].rgbtRed + image[1][j].rgbtRed + image[1][j+1].rgbtRed) / 6);


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;


        }
    }
    return;
}
