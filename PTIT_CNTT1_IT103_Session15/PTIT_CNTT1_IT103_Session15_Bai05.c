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

int dequeue(struct Queue *queue)
{
    if (queue->rear < queue->front)
    {
        printf("queue is empty\n\n");
        printf("queue = {\n");
        printf("   array = [],\n");
        printf("   front = %d,\n", queue->front);
        printf("   rear = %d,\n", queue->rear);
        printf("   capacity = %d\n", queue->maxSize);
        printf("}\n");
        return -1;
    }

    int value = queue->array[queue->front];
    queue->front++;

    printf("return value = %d;\n\n", value);
    printf("queue = {\n");
    printf("   array = [");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d", queue->array[i]);
        if (i < queue->rear)
            printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", queue->front);
    printf("   rear = %d,\n", queue->rear);
    printf("   capacity = %d\n", queue->maxSize);
    printf("}\n");

    return value;
}

int main()
{
    int size = 5;
    struct Queue *myQueue = createQueue(size);

    enqueue(myQueue, 10);
    enqueue(myQueue, 5);
    enqueue(myQueue, 2);

    dequeue(myQueue);

    free(myQueue->array);
    free(myQueue);

    return 0;
}
