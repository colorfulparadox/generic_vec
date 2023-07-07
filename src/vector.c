#include "../includes/vector.h"

Vec vec_new(int init_size, size_t element_size) {
    Vec vec;
    vec.length = init_size;
    vec.capacity = 0;
    vec.element_size = element_size;
    vec.array = malloc(element_size * vec.length);
    return vec;
}

Vec vec_from_array(void* array, int array_size, size_t element_size) {
    Vec vec;
    vec.length = array_size + VEC_GROW_SIZE;
    vec.capacity = 0;
    vec.element_size = element_size;
    vec.array = malloc(element_size * vec.length);

    char* ptr_array = (char*)array;
    for(int i = 0; i < array_size; i++) {
        vec_push(&vec, ptr_array);
        ptr_array += element_size;
    }
    return vec;
}

void vec_expand(Vec* vec) {
    vec->length += VEC_GROW_SIZE;
    
    void* result = realloc(vec->array, vec->element_size * vec->length);
    if (result == NULL) {
        printf("ERROR: Unable to REALLOC mem to expand vec!\n");
        exit(1);
    }
}

void vec_push(Vec* vec, void* element) {
    if (vec->length == vec->capacity) {
        vec_expand(vec);
    }
    memmove((char*)vec->array + vec->capacity * vec->element_size, element, vec->element_size);
    vec->capacity += 1;
}

void vec_reduce(Vec *vec, int new_length) {
    vec->length = new_length;
    void* result = realloc(vec->array, vec->element_size * vec->length);
    if (result == NULL) {
        printf("ERROR: Unable to REALLOC mem to decrease vec!\n");
        exit(1);
    }
}

void vec_pop_back(Vec* vec) {
    vec->capacity -= 1;
    if(vec->capacity >= vec->length/2) {
        return;
    }
    vec_reduce(vec, vec->length / 2);
}

void vec_pop_at(Vec* vec, int index) {
    if (index == vec->capacity) {
        vec_pop_back(vec);
        return;
    }
    vec->capacity -= 1;
    char* back = (char*)vec->array + vec->capacity * vec->element_size;
    char* at = (char*)vec->array + index * vec->element_size;
    memcpy(at, back, vec->element_size);

    if(vec->capacity >= vec->length/2) {
        return;
    }
    vec_reduce(vec, vec->length / 2);
}

void* vec_at(Vec* vec, int index) {
    if (index > vec->length) {
        printf("ERROR: Tried to access mem in vec that is out of bounds!\n");
        exit(1);
        return NULL;
    }
    return (void*)((char*)vec->array + index * vec->element_size);
}

void vec_free(Vec* vec) {
    free(vec->array);
}