#include "image_processing.h"

// Function to find pixel type (0 - Black, 1 - White, 2 - Yellow)
void findPixelType(int r, int g, int b) {
    if (r == 0 && g == 0 && b == 0) {
        printf("Pixel is Black\n");
    } else if (r == 255 && g == 255 && b == 255) {
        printf("Pixel is White\n");
    } else if (r == 255 && g == 255 && b == 0) {
        printf("Pixel is Yellow\n");
    } else {
        printf("Pixel is of an unknown type\n");
    }
}

// Convert RGB image to Grayscale using a weighted average
void rgbToGrayscale(int image[HEIGHT][WIDTH][3], int grayscale[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int r = image[i][j][0];
            int g = image[i][j][1];
            int b = image[i][j][2];
            grayscale[i][j] = (0.299 * r + 0.587 * g + 0.114 * b);  // Weighted average
        }
    }
}

// Perform 2D Convolution using an averaging filter
void applyConvolution(int grayscale[HEIGHT][WIDTH], int output[HEIGHT][WIDTH]) {
    int filter[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int filterSize = 3;
    int sum, x, y;

    // Initialize output array to zero
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            output[i][j] = 0;
        }
    }

    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            sum = 0;
            for (x = 0; x < filterSize; x++) {
                for (y = 0; y < filterSize; y++) {
                    sum += grayscale[i + x - 1][j + y - 1] * filter[x][y];
                }
            }
            output[i][j] = sum / 9;  // Normalize with filter sum (9)
        }
    }
}