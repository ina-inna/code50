#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    RGBTRIPLE pixel = image[0][0];

    if (pixel.rgbtBlue == 255 && pixel.rgbtGreen == 255 && pixel.rgbtRed == 255)
    {
        pixel.rgbtBlue = 0;
        pixel.rgbtGreen = 0;
    }

}
