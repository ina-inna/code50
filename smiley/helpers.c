#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    height = 0;
    width = 0;
    RGBTRIPLE pixel = image[height][width];

    if (pixel.rgbtBlue == 255 && pixel.rgbtGreen == 255 && pixel.rgbtRed == 255)
    {
        pixel.rgbtBlue = 0;
        pixel.rgbtGreen = 0;
        pixel.rgbtRed = 255;
    }

}

int main (colorize)

