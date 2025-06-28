#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5   // Example width
#define HEIGHT 5  // Example height

// Function Prototypes
void findPixelType(int r, int g, int b);
void rgbToGrayscale(int image[HEIGHT][WIDTH][3], int grayscale[HEIGHT][WIDTH]);
void applyConvolution(int grayscale[HEIGHT][WIDTH], int output[HEIGHT][WIDTH]);

#endif