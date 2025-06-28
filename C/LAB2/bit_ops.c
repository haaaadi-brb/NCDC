#include "bit_ops.h"

/* Returns the Nth bit of X */
unsigned get_bit(unsigned x, unsigned n) {
    return (x >> n) & 1;  // Shift right and mask with 1
}

/* Sets the Nth bit of X to V */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    if (v == 1)
        *x |= (1 << n);  // Set bit to 1 using OR
    else
        *x &= ~(1 << n); // Set bit to 0 using AND with NOT
}

/* Flips the Nth bit in X */
void flip_bit(unsigned *x, unsigned n) {
    *x ^= (1 << n);  // XOR to toggle bit
}
