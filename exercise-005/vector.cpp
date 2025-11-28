#include <stdlib.h>
#include "vector.hpp"
#define START_CAPACITY 4

void vector_init(Vector_t* vec){
    vec->capacity = START_CAPACITY;
    vec->data = (unsigned int*)malloc(START_CAPACITY * sizeof(int));
    vec->size = 0;
}
void vector_clear(Vector_t* vec){
    free(vec->data);
    free(vec);
}

int vector_push_back(Vector_t* vec, unsigned int value)
{
    if (vec->size >= vec->capacity)
    {
        unsigned int* old_data = vec->data;
        vec->capacity *= 2;

        unsigned int* new_data = (unsigned int*)malloc(vec->capacity * sizeof(old_data));
        if (!new_data) return -1; // allocation failure

        for (int i = 0; i < vec->size; i++)
            new_data[i] = old_data[i];

        vec->data = new_data;
        free(old_data);
    }

    vec->data[vec->size++] = value;
    return 0;
}
int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue){
    if(!vec||!index||!outValue) return -1;
    *outValue = vec->data[index];
    return 0;
}

void vector_print(const Vector_t* vec){

}
