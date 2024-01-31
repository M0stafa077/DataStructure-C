/* --------------- Section : Includes --------------- */
#include "vector.h"
/*---------------  Section: Function Definitions --------------- */

void vector_init(Vector_t* vector, size_t type_size, size_t capacity)
{
    vector->data = malloc(type_size * capacity);
    if (vector->data == NULL)
    {
        printf("Failed to allocate required memory!!\n");
        exit(EXIT_FAILURE);
    }
    vector->type_size = type_size;
    vector->capacity = capacity;
    vector->back = 0;
}

bool vector_isEmpty(const Vector_t* vector)
{
    return (0 == vector->back);
}

bool vector_isFull(const Vector_t* vector)
{
    return (vector->back == vector->capacity);
}

bool vector_pushBack(Vector_t* vector, const void* element)
{
    if (vector_isFull(vector))
    {
        return false;
    }

    memcpy((char*)vector->data + vector->back * vector->type_size, element, vector->type_size);
    vector->back++;
    return true;
}

bool vector_popBack(Vector_t* vector, void* element)
{
    if (vector_isEmpty(vector))
    {
        return false;
    }

    vector->back--;
    memcpy(element, (char*)vector->data + vector->back * vector->type_size, vector->type_size);
    return true;
}

void vector_back(Vector_t* vector, void* element)
{
    if (!vector_isEmpty(vector))
    {
        memcpy(element, (char*)vector->data + (vector->back - 1) * vector->type_size, vector->type_size);
    }
}

void vector_get_at(Vector_t* vector, size_t index, void* element)
{
    if (vector_isEmpty(vector))
    {
        return false;
    }
    memcpy(element, (char*)vector->data + index * vector->type_size, vector->type_size);
}

void vector_write_at(Vector_t* vector, size_t index, void* element)
{
    if (vector_isFull(vector))
    {
        return false;
    }
    memcpy((char*)vector->data + index * vector->type_size, element, vector->type_size);
}

size_t vector_getSize(const Vector_t* vector)
{
    return vector->back;
}

void vector_free(Vector_t* vector)
{

}
