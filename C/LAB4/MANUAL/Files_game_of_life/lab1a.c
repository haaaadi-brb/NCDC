#include "lifegame.h"
#include <stdio.h>

/***************************************************************
 * 🖊️ Author: *** Abdul Hadi Afzal *** 
 * -= Task: Main program for Conway's Game of Life =-
 ***************************************************************/

void next_generation(void);
int get_next_state(int x, int y);
int num_neighbors(int x, int y);

int main(void) {
    initialize_world();

    printf("Generation 0:\n");
    output_world();
for(int i=0;i<=50;i++){
next_generation();
}
    
    printf("Generation 1:\n");
    output_world();

  

    return 0;
}

void next_generation(void) {
    int x, y;
    int width = get_world_width();
    int height = get_world_height();

    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            set_cell_state(x, y, get_next_state(x, y));
        }
    }

    finalize_evolution();
}

int get_next_state(int x, int y) {
    int live_neighbors = num_neighbors(x, y);
    int current_state = get_cell_state(x, y);

    if (current_state == ALIVE) {
        if (live_neighbors < 2 || live_neighbors > 3) {
            return DEAD;  
        } else {
            return ALIVE; 
        }
    } else {
        if (live_neighbors == 3) {
            return ALIVE; 
        } else {
            return DEAD;  
        }
    }
}

int num_neighbors(int x, int y) {
    int dx, dy;
    int count = 0;

    /* Count live neighbors in the 8 surrounding cells */
    for (dx = -1; dx <= 1; dx++) {
        for (dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;  
            if (get_cell_state(x + dx, y + dy) == ALIVE) {
                count++;
            }
        }
    }

    return count;
}
