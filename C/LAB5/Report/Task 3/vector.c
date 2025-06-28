#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

struct vector_t {
    size_t size;
    int *data;
};

static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    vector_t *retval, v;
    retval = &v;

    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
vector_t also_bad_vector_new() {
    vector_t v;

    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Good implementation of vector_new */
vector_t *vector_new() {
    vector_t *retval = malloc(sizeof(vector_t));
    if (retval == NULL) {
        allocation_failed();
    }

    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        free(retval);  // free struct if data allocation fails
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Get a value from the vector */
int vector_get(vector_t *v, size_t loc) {
    if (v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    if (loc >= v->size) {
        return 0;
    }

    return v->data[loc];
}

/* Free vector memory */
void vector_delete(vector_t *v) {
    if (v == NULL) return;

    free(v->data);
    free(v);
}

/* Set a value in the vector */
void vector_set(vector_t *v, size_t loc, int value) {
    if (v == NULL) {
        fprintf(stderr, "vector_set: passed a NULL vector.\n");
        abort();
    }

    if (loc >= v->size) {
        size_t new_size = loc + 1;
        int *new_data = malloc(new_size * sizeof(int));
        if (new_data == NULL) {
            allocation_failed();
        }

        // Copy old data and initialize new elements to 0
        for (size_t i = 0; i < new_size; i++) {
            if (i < v->size) {
                new_data[i] = v->data[i];
            } else {
                new_data[i] = 0;
            }
        }

        free(v->data);
        v->data = new_data;
        v->size = new_size;
    }

    v->data[loc] = value;
}

