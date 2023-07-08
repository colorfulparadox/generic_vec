#pragma once
#ifndef _VECTOR_HEADER_
#define _VECTOR_HEADER_

#define VEC_GROW_SIZE 10

#include <stddef.h>

typedef struct Vec {
    int length;
    int capacity;
    int expand_length;
    size_t element_size;
    void* array;
} Vec;

Vec vec_new(int init_size, size_t element_size);
Vec vec_from_array(void* array, int array_size, size_t element_size);
void vec_expand(Vec* vec);
void vec_push(Vec* vec, void* element);
void vec_reduce(Vec *vec, int new_length);
void vec_pop_back(Vec* vec);
void vec_pop_at(Vec* vec, int index);
void* vec_at(Vec* vec, int index);
void vec_free(Vec* vec);

#endif