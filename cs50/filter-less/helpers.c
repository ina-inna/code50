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

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;

            int count = 0;

            for (int newI = -1; newI <= 1; newI++)

            {
                for (int newJ = -1; newJ <= 1; newJ++)

                {
                    int row = newI + i;
                    int col = newJ + j;

                    if (row >= 0 && col >= 0 && row < height && col < width)

                    {
                        sumBlue += image[row][col].rgbtBlue;
                        sumGreen += image[row][col].rgbtGreen;
                        sumRed += image[row][col].rgbtRed;
                        count++;
                    }
                }
            }

            copy[i][j].rgbtBlue = round((float) sumBlue / count);
            copy[i][j].rgbtGreen = round((float) sumGreen / count);
            copy[i][j].rgbtRed = round((float) sumRed / count);
        }
    }

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)

        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}
