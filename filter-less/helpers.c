#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            {
                int avg = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;

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
                image[i][j].rgbtRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
                if (image[i][j].rgbtRed > 255)
                {
                    image[i][j].rgbtRed = 255;
                }

                image[i][j].rgbtGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;

                 if (image[i][j].rgbtGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                }
                image[i][j].rgbtBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

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
        for (int j = 0; j < width / 2; j++)


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
               int blur1 = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9;
               int blur2 = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9;
               int blur3 = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9;


                image[i][j].rgbtBlue = blur1;
                image[i][j].rgbtGreen = blur2;
                image[i][j].rgbtRed = blur3;

            }
        }
    }

    return;
}
