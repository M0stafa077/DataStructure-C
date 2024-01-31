#define  DONE    1
#if      !DONE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void* data;       // Pointer to the data
    size_t size;      // Size of the data type
    size_t capacity;  // Capacity of the stack
    size_t top;       // Index of the top element
} Stack;

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

void BracketMatcher(char * str) {
    bool flag = false, occuranceFlag = false;

    Stack stack;
    stack_init(&stack, sizeof(char), strlen(str));

    for(int l_counter = 0; l_counter < strlen(str); ++l_counter)
    {
        if ('(' == str[l_counter])
        {
            occuranceFlag = true;
            stack_push(&stack, &str[l_counter]);
        }
        else if (')' == str[l_counter])
        {
            if(stack_isEmpty(&stack))
            {
                flag = false;
                break;
            }
            else
            {
                char temp;
                stack_pop(&stack, &temp);
                flag = true;
            }
        }
    }

    if(occuranceFlag)
    {
        if (flag)
        {
            if(stack_isEmpty(&stack))
                printf("1");
            else
                printf("0");
        }
        else
            printf("0");
    }
    else
        printf("1");
}

int main(void)
{
    char *str = "((((((((((((((";
    BracketMatcher(str);
}

#endif
