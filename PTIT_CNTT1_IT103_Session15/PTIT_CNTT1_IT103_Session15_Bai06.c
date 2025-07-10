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

int isOrdered(struct Queue *queue)
{
    for (int i = queue->front; i < queue->rear; i++)
    {
        if (queue->array[i] > queue->array[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int size;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &size);
    struct Queue *myQueue = createQueue(size);

    for (int i = 0; i < size; i++)
    {
        int n;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &n);
        enqueue(myQueue, n);
    }

    if (!isOrdered(myQueue))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    free(myQueue->array);
    free(myQueue);

    return 0;
}
