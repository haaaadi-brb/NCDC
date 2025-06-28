/***************************************************************
 * 🖊️ Author: Abdul Hadi Afzal
 * File: lab1b.c
 * Task: Main program for Conway's Game of Life
 ***************************************************************/

#include "lifegame.h"
#include <stdio.h>
#include <stdlib.h>

void next_generation(void);
int get_next_state(int x, int y);
int num_neighbors(int x, int y);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        initialize_world_from_file(argv[1]);
    } else {
        initialize_world();
    }

    printf("Initial Generation:\n");
    output_world();  

    for (int i = 0; i < 50; i++) {  
        next_generation();
    }

    printf("Generation %d:\n", 50);
    output_world();

    save_world_to_file("world.txt");
    return 0;
}

int get_next_state(int x, int y) {
    int live_neighbors = num_neighbors(x, y);
    int current_state = get_cell_state(x, y);

    if (current_state == ALIVE) {
        return (live_neighbors < 2 || live_neighbors > 3) ? DEAD : ALIVE;
    } else {
        return (live_neighbors == 3) ? ALIVE : DEAD;
    }
}

int num_neighbors(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;

            int neighbor_x = x + dx;
            int neighbor_y = y + dy;

            if (neighbor_x >= 0 && neighbor_x < WORLDWIDTH && 
                neighbor_y >= 0 && neighbor_y < WORLDHEIGHT) {
                if (get_cell_state(neighbor_x, neighbor_y) == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}
