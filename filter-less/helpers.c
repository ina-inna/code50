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
                image[i][j].rgbtRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }

                image[i][j].rgbtGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);

                 if (image[i][j].rgbtGreen > 255)
                {

                    image[i][j].rgbtGreen = 255;

                }
                image[i][j].rgbtBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

                 if (image[i][j].rgbtBlue > 255)
                {

                    image[i][j].rgbtBlue = 255;
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
        int newWidth = width / 2;
        for (int j = 0; j < newWidth; j++)


            {
                    RGBTRIPLE pixel0 = image[i][j];
                    RGBTRIPLE pixel00 = image[i][width - j];

                    RGBTRIPLE *pixel = &image[i][j];
                    RGBTRIPLE *pixel2 = &image[i][width - j];

                    *pixel = pixel00;
                    *pixel2 = pixel0;
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

    return;
}
