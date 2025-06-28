/***************************************************************
 * 🖊️ Author: Abdul Hadi Afzal
 * File: lifegame.c
 * Task: Game logic for Conway's Game of Life
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lifegame.h"

#define MAX_LINE_LENGTH 256
#define CHAR_ALIVE '*'
#define CHAR_DEAD ' '

static int world[WORLDWIDTH][WORLDHEIGHT];
static int nextstates[WORLDWIDTH][WORLDHEIGHT];

void next_generation(void) {
    int width = get_world_width();
    int height = get_world_height();

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            nextstates[x][y] = get_next_state(x, y);
        }
    }

    finalize_evolution();
}

void initialize_world_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int y = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) && y < WORLDHEIGHT) {
        int x = 0;
        for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++) {
            if (line[i] == '*') {
                set_cell_state(x, y, ALIVE);
            }
            x++;
        }
        y++;
    }

    fclose(file);
}

void save_world_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < get_world_height(); y++) {
        for (int x = 0; x < get_world_width(); x++) {
            fputc(get_cell_state(x, y) == ALIVE ? '*' : ' ', file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

void initialize_world(void) {
    for (int i = 0; i < WORLDWIDTH; i++)
        for (int j = 0; j < WORLDHEIGHT; j++)
            world[i][j] = nextstates[i][j] = DEAD;

    world[2][4] = ALIVE;
    world[4][4] = ALIVE;
    world[5][5] = ALIVE;
    world[2][6] = ALIVE;
    world[5][6] = ALIVE;
    world[3][7] = ALIVE;
    world[4][7] = ALIVE;
    world[5][7] = ALIVE;
    world[6][7] = ALIVE;
}

int get_world_width(void) {
    return WORLDWIDTH;
}

int get_world_height(void) {
    return WORLDHEIGHT;
}

int get_cell_state(int x, int y) {
    return (x >= 0 && x < WORLDWIDTH && y >= 0 && y < WORLDHEIGHT) ? world[x][y] : DEAD;
}

void set_cell_state(int x, int y, int state) {
    if (x >= 0 && x < WORLDWIDTH && y >= 0 && y < WORLDHEIGHT) {
        world[x][y] = state;
        nextstates[x][y] = state;
    }
}

void finalize_evolution(void) {
    for (int x = 0; x < WORLDWIDTH; x++) {
        for (int y = 0; y < WORLDHEIGHT; y++) {
            world[x][y] = nextstates[x][y];
            nextstates[x][y] = DEAD;
        }
    }
}

void output_world(void) {
    printf("+");
    for (int i = 0; i < 2 * WORLDWIDTH; i++) printf("-");
    printf("+\n");

    for (int y = 0; y < WORLDHEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WORLDWIDTH; x++) {
            printf("%c", world[x][y] == ALIVE ? '*' : ' ');
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < 2 * WORLDWIDTH; i++) printf("-");
    printf("+\n");
}
