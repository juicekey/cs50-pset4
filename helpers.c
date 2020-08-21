#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gs = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = gs;
        }
    }

    return;
    //for each pixel, take average of RGB values
    //change pixel to average for R G and B
    //round
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][width - (j + 1)];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
    //temp function using swap
    //if odd num values, middle stays same
    //switch from i to length/width - (i + 1)
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalr = 0;
            int totalg = 0;
            int totalb = 0;

            if ((i == 0) && (j == 0))
            //top left
            {
                for (int k = i; k < (i + 2); k++)
                {
                    for (int l = j; l < (j + 2); l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;

                    }
                }
                temp[i][j].rgbtRed = round(totalr/4.0);
                temp[i][j].rgbtGreen = round(totalg/4.0);
                temp[i][j].rgbtBlue = round(totalb/4.0);
            }

             else if ((i == 0) && (j == (width - 1)))
            //top right
            {
                for (int k = i; k < (i + 2); k++)
                {
                    for (int l = (j-1); l < (j+1); l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/4.0);
                temp[i][j].rgbtGreen = round(totalg/4.0);
                temp[i][j].rgbtBlue = round(totalb/4.0);
            }

            else if ((i == (height - 1)) && (j == 0))
            //bottom left
            {
                for (int k = (i-1); k < (i+1); k++)
                {
                    for (int l = j; l < (j+2); l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/4.0);
                temp[i][j].rgbtGreen = round(totalg/4.0);
                temp[i][j].rgbtBlue = round(totalb/4.0);
            }

            else if ((i == (height - 1)) && (j == (width - 1)))
            //bottom right
            {
                for (int k = (i-1); k < (i+1); k++)
                {
                    for (int l = (j-1); l < (j+1); l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/4.0);
                temp[i][j].rgbtGreen = round(totalg/4.0);
                temp[i][j].rgbtBlue = round(totalb/4.0);

            }

            else if ((i > 0) && (i < height - 1) && (j == 0))
            //left
            {
                for (int k = i-1; k < i+2; k++)
                {
                    for (int l = j; l < j+2; l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/6.0);
                temp[i][j].rgbtGreen = round(totalg/6.0);
                temp[i][j].rgbtBlue = round(totalb/6.0);
            }

            else if ((i == 0) && (j > 0) && (j < width - 1))
            //top
            {
                for (int k = i; k < i+2; k++)
                {
                    for (int l = j-1; l < j+2; l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/6.0);
                temp[i][j].rgbtGreen = round(totalg/6.0);
                temp[i][j].rgbtBlue = round(totalb/6.0);
            }
            else if ((i > 0) && (i < height - 1) && (j == width - 1))
            //right
            {
                for (int k = i-1; k < i+2; k++)
                {
                    for (int l = j-1; l < j+1; l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/6.0);
                temp[i][j].rgbtGreen = round(totalg/6.0);
                temp[i][j].rgbtBlue = round(totalb/6.0);
            }
            else if ((i == height - 1) && (j > 0) && (j < width - 1))
            //bottom
            {
                for (int k = i-1; k < i+1; k++)
                {
                    for (int l = j-1; l < j+2; l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/6.0);
                temp[i][j].rgbtGreen = round(totalg/6.0);
                temp[i][j].rgbtBlue = round(totalb/6.0);
            }

            else
            {
                for (int k = (i-1); k < (i+2); k++)
                {
                    for (int l = (j-1); l < (j+2); l++)
                    {
                        totalr += image[k][l].rgbtRed;
                        totalg += image[k][l].rgbtGreen;
                        totalb += image[k][l].rgbtBlue;
                    }
                }
                temp[i][j].rgbtRed = round(totalr/9.0);
                temp[i][j].rgbtGreen = round(totalg/9.0);
                temp[i][j].rgbtBlue = round(totalb/9.0);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
    //new image same size
    //corner and edge cases
    //all else iterate between i - 1 and i + 1
    //round
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int x[3][3] =
    // x kernel
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int y[3][3] =
    // y kernel
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    int  GxR[height][width];
    int  GyR[height][width];
    int  GxG[height][width];
    int  GyG[height][width];
    int  GxB[height][width];
    int  GyB[height][width];
    // Gx and Gy sums

    RGBTRIPLE temp[height + 2][width + 2];
    // temp image

    for (int i = 0; i < (height + 2); i++)
    {
        for (int j = 0; j < (width + 2); j++)
        {
            //initialize temp image
            temp[i][j].rgbtRed = 0;

            temp[i][j].rgbtGreen = 0;

            temp[i][j].rgbtBlue = 0;
        }
    }

    int tempR[height][width];
    int tempG[height][width];
    int tempB[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set middle of temp to be original image
            temp[i + 1][j + 1].rgbtRed = image[i][j].rgbtRed;

            temp[i + 1][j + 1].rgbtGreen = image[i][j].rgbtGreen;

            temp[i + 1][j + 1].rgbtBlue = image[i][j].rgbtBlue;

            // initialize G images

            GxR[i][j] = 0;
            GyR[i][j] = 0;
            GxG[i][j] = 0;
            GyG[i][j] = 0;
            GxB[i][j] = 0;
            GyB[i][j] = 0;

            tempR[i][j] = 0;
            tempG[i][j] = 0;
            tempB[i][j] = 0;


        }
    }

    for (int i = 1; i < (height+1); i++)
    {
        for (int j = 1; j < (width+1); j++)
        {
            //iterate over middle of temp
            for (int k = (i-1); k < (i+2); k++)
            {
                for (int l = (j-1); l < (j+2); l++)
                {
                    //set kernel, -1 to +1

                    GxR[i-1][j-1] += ((temp[k][l].rgbtRed * y[k - (i-1)][l - (j-1)]));
                    GyR[i-1][j-1] += ((temp[k][l].rgbtRed * x[k - (i-1)][l - (j-1)]));
                    GxG[i-1][j-1] += ((temp[k][l].rgbtGreen * x[k - (i-1)][l - (j-1)]));
                    GyG[i-1][j-1] += ((temp[k][l].rgbtGreen * y[k - (i-1)][l - (j-1)]));
                    GxB[i-1][j-1] += ((temp[k][l].rgbtBlue * x[k - (i-1)][l - (j-1)]));
                    GyB[i-1][j-1] += ((temp[k][l].rgbtBlue * y[k - (i-1)][l - (j-1)]));


                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        //square root of sum of squares
        {
            tempR[i][j] = round(sqrt( pow( 1.0*GxR[i][j], 2.0) + pow( 1.0*GyR[i][j], 2.0) ));

            if (tempR[i][j] > 255.0)
            {
                tempR[i][j] = 255;
            }
            image[i][j].rgbtRed = tempR[i][j];

            tempG[i][j] = round(sqrt( pow( 1.0*GxG[i][j], 2.0) + pow( 1.0*GyG[i][j], 2.0) ));

            if (tempG[i][j] > 255.0)
            {
                tempG[i][j] = 255;
            }
            image[i][j].rgbtGreen = tempG[i][j];

            tempB[i][j] = round(sqrt( pow( 1.0*GxB[i][j], 2.0) + pow( 1.0*GyB[i][j], 2.0) ));

            if (tempB[i][j] > 255.0)
            {
               tempB[i][j] = 255;
            }
            image[i][j].rgbtBlue = tempB[i][j];

        }
    }

    return;

    //
    //
    //
    //
    //
    //
}
