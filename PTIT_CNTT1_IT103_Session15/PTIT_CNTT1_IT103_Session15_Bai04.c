#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *array;
    int front;
    int rear;
    int maxSize;
};

struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->array = (int *)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->maxSize = size;

    return queue;
}

void enqueue(struct Queue *queue, int value)
{
    if (full(queue))
    {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

void printAll(struct Queue *queue)
{
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
}

int main()
{
    int size = 5;
    struct Queue *myQueue = createQueue(size);

    enqueue(myQueue, 10);
    enqueue(myQueue, 5);
    enqueue(myQueue, 2);

    printAll(myQueue);

    free(myQueue->array);
    free(myQueue);

    return 0;
}
