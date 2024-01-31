/* Section : Includes */
#include "stack.h"

/* Section: Function Definitions */

void stack_init(Stack* stack, size_t type_size, size_t capacity)
{
    stack->data = malloc(type_size * capacity);
    if (stack->data == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }
    stack->type_size = type_size;
    stack->capacity = capacity;
    stack->top = 0;
}

bool stack_isEmpty(const Stack* stack)
{
    return stack->top == 0;
}

bool stack_isFull(const Stack* stack)
{
    return stack->top == stack->capacity;
}

bool stack_push(Stack* stack, const void* element)
 {
    if (stack_isFull(stack))
    {
        return false;
    }

    memcpy((char*)stack->data + stack->top * stack->type_size, element, stack->type_size);
    stack->top++;
    return true;
}

bool stack_pop(Stack* stack, void* element)
{
    if (stack_isEmpty(stack))
    {
        return false;
    }

    stack->top--;
    memcpy(element, (char*)stack->data + stack->top * stack->type_size, stack->type_size);
    return true;
}

void stack_top(const Stack* stack, void* element)
{
    if (!stack_isEmpty(stack)) {
        // Copy the top element without removing it
        memcpy(element, (char*)stack->data + (stack->top - 1) * stack->type_size, stack->type_size);
    }
}

size_t stack_getSize(const Stack* stack) {
    return stack->top;
}

void stack_free(Stack* stack) {
    free(stack->data);
}
