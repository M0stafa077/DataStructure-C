
/* Section : Includes */
 #include "queue.h"

/* Section: Function Definitions */

void queue_initialize(Queue *queue, int size)
{
    queue->queue_size = size;
    queue->data = (int *) calloc(queue->queue_size, sizeof(int));
    queue->front = -1;
    queue->rear = -1;
}

void queue_reSize(Queue *queue, int new_size)
{
    int i, j = 0;
    /* Create a temporary array and save the content of the queue into it */
    int *new_array = (int *) calloc(new_size, sizeof(int));

    for (i = queue->front; i != ((queue->rear + 1) % queue->queue_size); i = (i + 1) % queue->queue_size)
        new_array[j++] = queue->data[i];

    /* Reallocate the new size of the queue*/
    queue->data = (int *) realloc(queue->data, new_size * sizeof(int));

    /* Restore the content from the temporary array */
    j = 0;
    for (i = queue->front; i != ((queue->rear + 1) % queue->queue_size); i = (i + 1) % queue->queue_size)
         queue->data[i] = new_array[j++];

    /* Assign the new size to the queue object */
    queue->queue_size = new_size;
}

int queue_isFull(Queue *queue)
{
    return (queue->rear + 1) % queue->queue_size == queue->front;
}

int queue_isEmpty(Queue *queue)
{
    return (-1 == queue->front);
}

void queue_enqueue(Queue *queue, int num)
{
    if (queue_isFull(queue))
    {
        printf("Queue overflow.\n");
        return;
    }

    if(queue_isEmpty(queue))
            queue->front = 0;

    queue->rear = ((queue->rear) + 1) % queue->queue_size;
    queue->data[queue->rear] = num;
}

int queue_dequeue(Queue *queue)
{
    int ret;
    if (queue_isEmpty(queue))
    {
        printf("Queue is Empty.\n");
        return -1;
    }
    else
    {
        ret = queue->data[queue->front];

        /* Check if the last element is dequeued */
        if (queue->front == queue->rear)
            queue_initialize(queue, queue->queue_size);

        else
            queue->front = (queue->front + 1) % queue->queue_size; // Circular increment
    }
    return ret;
}

int queue_front(Queue *queue)
{
    if (queue_isEmpty(queue)){
        printf("Queue is Empty.\n");
        return -1;
    }
    else
    {
        return queue->data[queue->front];
    }
}

int queue_getSize(Queue *queue)
{
    return (queue->queue_size - queue->front + queue->rear) % queue->queue_size;
}

void queue_print(Queue *queue)
{
    if (queue_isEmpty(queue))
        printf("Queue is Empty.\n");

    else
    {
        int i;
        for (i = queue->front; i != queue->rear; i = (i + 1) % queue->queue_size)
            printf("%d ", queue->data[i]);

        printf("%d\n", queue->data[i]);
    }
}

void queue_free(Queue *queue)
{
    free(queue->data);
}
