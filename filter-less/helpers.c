#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
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
                image[i][j].rgbtBlue = 0;
                image[i][j].rgbtGreen = 0;
                image[i][j].rgbtRed = 255;
            }
        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
