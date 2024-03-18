/* --------------- Section : Includes --------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* --------------- Section: Data Type Declarations --------------- */
typedef struct
{
    void* data;         // Pointer to the data
    size_t type_size;   // Size of the data type
    size_t capacity;    // Capacity of the stack
    size_t back;        // Pointer to the last element.
} Vector_t;
/*---------------  Section: Function Declarations --------------- */
void vector_init(Vector_t* vector, size_t type_size, size_t capacity);
bool vector_isEmpty(const Vector_t* vector);
bool vector_isFull(const Vector_t* vector);
bool vector_pushBack(Vector_t* vector, const void* element);
bool vector_popBack(Vector_t* vector, void* element);
void vector_back(Vector_t* vector, void* element);
void vector_get_at(Vector_t* vector, size_t index, void* element);
void vector_write_at(Vector_t* vector, size_t index, void* element);
size_t vector_getSize(const Vector_t* vector);
void vector_free(Vector_t* vector);
