#include "image_processing.h"

int main() {
    int image[HEIGHT][WIDTH][3] = {
        {{0, 0, 0}, {255, 255, 255}, {255, 255, 0}, {128, 128, 128}, {100, 200, 50}},
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0}},
        {{255, 255, 0}, {255, 255, 255}, {0, 0, 0}, {128, 128, 128}, {50, 100, 200}},
        {{0, 255, 255}, {255, 0, 255}, {255, 255, 0}, {0, 0, 0}, {255, 255, 255}},
        {{100, 100, 100}, {50, 50, 50}, {200, 200, 200}, {0, 0, 0}, {255, 255, 255}}
    };

    int grayscale[HEIGHT][WIDTH];
    int output[HEIGHT][WIDTH];

    printf("Finding Pixel Types:\n");
    findPixelType(0, 0, 0);         // Black
    findPixelType(255, 255, 255);   // White
    findPixelType(255, 255, 0);     // Yellow
    findPixelType(0,0,0);   // Unknown

    printf("\nConverting to Grayscale...\n");
    rgbToGrayscale(image, grayscale);

    printf("\nApplying Convolution...\n");
    applyConvolution(grayscale, output);

    printf("\nGrayscale Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", grayscale[i][j]);
        }
        printf("\n");
    }

    printf("\nFiltered Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}