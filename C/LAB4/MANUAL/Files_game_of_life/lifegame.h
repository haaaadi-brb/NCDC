/***************************************************************
 * 🖊️ Author: Abdul Hadi Afzal
 * File: lifegame.h
 * Task: Header file for Conway's Game of Life
 ***************************************************************/

#ifndef LIFEGAME_H_
#define LIFEGAME_H_

#define DEAD 0
#define ALIVE 1

#define WORLDWIDTH 39
#define WORLDHEIGHT 20

int get_next_state(int x, int y);
void initialize_world(void);
void initialize_world_from_file(const char *filename);
void save_world_to_file(const char *filename);
int get_world_width(void);
int get_world_height(void);
int get_cell_state(int x, int y);
void set_cell_state(int x, int y, int state);
void finalize_evolution(void);
void output_world(void);

#endif /* LIFEGAME_H_ */
