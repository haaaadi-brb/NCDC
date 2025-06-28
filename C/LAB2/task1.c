#include <stdio.h>
#include <stdlib.h>  // For rand() function
#include <time.h>    // For seeding random numbers

int main() {
    int xt, yt; // Treasure coordinates

    // Seed the random number generator
    srand(time(0));

    // Generate random coordinates for the treasure (between 1 and 4)
    xt = (rand() % 4) + 1;
    yt = (rand() % 4) + 1;

    printf("Searching for treasure...\n");

    // Searching the grid
    for (int x = 1; x <= 4; x++) {
        for (int y = 1; y <= 4; y++) {
            printf("Checking location (%d, %d)...\n", x, y);
            if (x == xt && y == yt) {
                printf("Hurrah! I have found the hidden treasure at (%d, %d)!\n", xt, yt);
                return 0;
            }
        }
    }

    return 0;
}
