#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
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
            BYTE originalRed = image[i][j].rgbtRed;
            BYTE originalGreen = image[i][j].rgbtGreen;
            BYTE originalBlue = image[i][j].rgbtBlue;
            
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtGreen = sepiaGreen;
            
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
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
            RGBTRIPLE pxa = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = pxa;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    memcpy(copy, image, sizeof(RGBTRIPLE[height][width]));
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red = 0;
            int sum_blue = 0;
            int sum_green = 0;
            int count = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        sum_red += copy[k][l].rgbtRed;
                        sum_green += copy[k][l].rgbtGreen;
                        sum_blue += copy[k][l].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round((float) sum_red / (float) count);
            image[i][j].rgbtGreen = round((float) sum_green / (float) count);
            image[i][j].rgbtBlue = round((float) sum_blue / (float) count);
        }
    }
    return;
}
