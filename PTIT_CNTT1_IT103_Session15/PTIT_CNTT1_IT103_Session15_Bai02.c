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

int full(struct Queue *queue)
{
    return queue->rear == queue->maxSize - 1;
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

void print(struct Queue *queue)
{
    printf("Queue = {\n");
    printf("Array = [");
    for (int i = 0; i <= queue->rear; i++)
    {
        printf("%d", queue->array[i]);
        if (i < queue->rear)
            printf(", ");
    }
    printf("Front = %d\n", queue->front);
    printf("Rear = %d\n", queue->rear);
    printf("Capacity = %d\n", queue->maxSize);
    printf("}\n");
}

int main()
{
    int size = 5;
    struct Queue *myQueue = createQueue(size);

    for (int i = 0; i < size; i++)
    {
        int n;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &n);
        enqueue(myQueue, n);
        print(myQueue);
    }

    free(myQueue->array);
    free(myQueue);

    return 0;
}
