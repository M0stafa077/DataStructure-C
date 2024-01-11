/* Section : Includes */
#include "stack.h"

/* Section: Function Definitions */

void stack_init(Stack* stack, size_t size, size_t capacity) 
{
    stack->data = malloc(size * capacity);
    if (stack->data == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }
    stack->size = size;
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
        // Stack overflow
        return false;
    }

    // Copy the element to the stack
    memcpy((char*)stack->data + stack->top * stack->size, element, stack->size);
    stack->top++;
    return true;
}

bool stack_pop(Stack* stack, void* element) 
{
    if (stack_isEmpty(stack)) 
    {
        // Stack underflow
        return false;
    }

    stack->top--;
    // Copy the element from the stack
    memcpy(element, (char*)stack->data + stack->top * stack->size, stack->size);
    return true;
}

void stack_top(const Stack* stack, void* element) 
{
    if (!stack_isEmpty(stack)) {
        // Copy the top element without removing it
        memcpy(element, (char*)stack->data + (stack->top - 1) * stack->size, stack->size);
    }
}
size_t stack_getSize(const Stack* stack) {
    return stack->top;
}

void stack_free(Stack* stack) {
    free(stack->data);
}