/* Section: Includes */
#include <stdio.h>
#include <stdlib.h>

/* Section: Macro Declarations */
#define STACK_EMPTY         1
#define STACK_FULL          1
#define STACK_NOT_EMPTY     0
#define STACK_NOT_FULL      0
#define ERROR               -1

/* Section: Data Type Declarations */
typedef struct Stack {
    int *data;
    int top;
    int stack_size;
} Stack;

/* Section: Function Declarations */
void stack_initialize(Stack *stack, int size);  // Initializes a new stack object;
void stack_reSize(Stack *stack, int new_size);  // Resizes the stack object;
int  stack_isEmpty(Stack *stack);               // Checks if the stack is empty;
int  stack_isFull(Stack *stack);                // Checks if the stack is full;
void stack_push(Stack *stack, int num);         // Push a number on top of stack;
int  stack_pop  (Stack *stack);                 // Pop the top number stack;
int  stack_top  (Stack *stack);                 // Read the top number stack without deleting;
int  stack_getSize (Stack *stack);               // Returns size of the stack;
void stack_print(Stack *stack);                 // Prints the stack content;
void stack_free(Stack* stack);                  // Deletes the stack object;


