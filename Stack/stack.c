/* Section : Includes */
#include "stack.h"

/* Section: Function Definitions */

void stack_initialize(Stack *stack, int size)
{
    stack->data = (int *) calloc(size, sizeof(int));
    stack->top = -1;
    stack->stack_size = size;
}

void stack_reSize(Stack *stack, int new_size)
{
    int i, j = 0;
    /* Create a temporary array and save the content of the stack into it */
    int *new_array = (int *) calloc(new_size, sizeof(int));

    for(i = 0; i < stack_getSize(stack); ++i)
        new_array[j++] = stack->data[i];

    /* Reallocate the new size of the stack*/
    stack->data = (int *) realloc(stack->data, new_size * sizeof(int));

    /* Restore the content from the temporary array */
    j = 0;
    for(i = 0; i < stack_getSize(stack); ++i)
         stack->data[i] = new_array[j++];

    /* Assign the new size to the stack object */
    stack->stack_size = new_size;
}

int stack_isEmpty(Stack *stack)
{
    return ((stack->top) <= -1) ? (STACK_EMPTY) : (STACK_NOT_EMPTY);
}

int stack_isFull(Stack *stack)
{
    return ((stack->stack_size - 1) == (stack->top)) ? (STACK_FULL) : (STACK_NOT_FULL);
}

void stack_push(Stack *stack, int num)
{
    if(stack_isFull(stack))
    {
        printf("Stack Overflow.\n");
        return;
    }

    else
        stack->data[++(stack->top)] = num;
}

int stack_pop (Stack *stack)
{
    int ret = ERROR;

    if(stack_isEmpty(stack))
        printf("Stack is Empty.\n");

    else
        ret = stack->data[(stack->top)--];

    return ret;
}

int stack_top(Stack *stack)
{
    int ret = ERROR;

    if(stack_isEmpty(stack))
        printf("Stack is Empty.\n");
    else
        ret = stack->data[(stack->top)];

    return ret;
}

int stack_getSize(Stack *stack)
{
    int ret = ERROR;

    if(stack_isEmpty(stack))
        printf("Stack is Empty.");
    else
        ret = (stack->top) + 1;

    return ret;
}

void stack_print(Stack *stack)
{
    if (stack_isEmpty(stack))
        printf("Stack is Empty.\n");
    else
    {
        int l_counter = 0;
        for(l_counter = 0; l_counter < stack_getSize(stack); ++l_counter)
            printf("%d ", stack->data[l_counter]);

        printf("\n");
    }
}

void stack_free(Stack *stack)
{
    stack_initialize(stack, 0);
    free(stack->data);
    stack = NULL;
}






