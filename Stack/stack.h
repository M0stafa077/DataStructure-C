/* Section: Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Section: Macro Declarations */
#define STACK_EMPTY         1
#define STACK_FULL          1
#define STACK_NOT_EMPTY     0
#define STACK_NOT_FULL      0
#define ERROR               -1

/* Section: Data Type Declarations */
typedef struct {
    void* data;       // Pointer to the data
    size_t size;      // Size of the data type
    size_t capacity;  // Capacity of the stack
    size_t top;       // Index of the top element
} Stack;

/* Section: Function Declarations */
void stack_init(Stack* stack, size_t size, size_t capacity);    // Initializes a new stack object;
void stack_reSize(Stack *stack, int new_size);                  // Resizes the stack object;
bool stack_isEmpty(const Stack* stack);                         // Checks if the stack is empty;
bool stack_isFull(const Stack* stack);                          // Checks if the stack is full;
bool stack_push(Stack* stack, const void* element);             // Push a number on top of stack;
bool stack_pop(Stack* stack, void* element);                    // Pop the top number stack;
void stack_top(const Stack* stack, void* element);              // Read the top number stack without deleting;
size_t stack_getSize(const Stack* stack);                       // Returns size of the stack;
void stack_print(Stack *stack);                                 // Prints the stack content;
void stack_free(Stack* stack);                                  // Deletes the stack object;


