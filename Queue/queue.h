/* -------------- Section: Includes -------------- */
#include <stdio.h>
#include <stdlib.h>

/* -------------- Section: Data Type Declarations -------------- */
typedef struct Queue{
    int *data;
    int front;
    int rear;
    int queue_size;
} Queue;

/* -------------- Section: Function Declarations -------------- */
void queue_initialize(Queue *queue, int size);        // Initializes a queue object;
void queue_reSize(Queue *queue, int new_size);       // Resizes the queue;
int queue_isFull(Queue *queue);             // Checks if a queue is full;
int queue_isEmpty(Queue *queue);            // Checks if a queue is empty;
void queue_enqueue(Queue *queue, int num);  // Insert a number at rear of queue;
int queue_dequeue(Queue *queue);            // Deletes and returns number at front of queue;
int queue_front(Queue *queue);              // Returns number at front of queue without deleting;
int queue_getSize(Queue *queue);               // Returns the size of the queue;
void queue_print(Queue *queue);             // Prints  the queue's content;
void queue_free(Queue *queue);              // Deletes the queue's content;

