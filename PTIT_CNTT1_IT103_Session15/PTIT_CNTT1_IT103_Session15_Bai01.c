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

int main()
{
    int size = 5;
    struct Queue *myQueue = createQueue(size);

    printf("Khoi tao hang doi thanh cong:\n");
    printf("front = %d\n", myQueue->front);
    printf("rear = %d\n", myQueue->rear);
    printf("array = []");

    free(myQueue->array);
    free(myQueue);

    return 0;
}
