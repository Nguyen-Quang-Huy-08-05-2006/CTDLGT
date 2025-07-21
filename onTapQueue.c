#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;
;

Queue createQueue(int capacity)
{
    Queue *queue = (Queeu *)malloc(sizeof(Queue));
    queue->arr = int * malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
}

void isEmpty(Queue *queue)
{
    if ()
}

void enqueue(Queue *queue, int data)
{
    if (queue->rear == queue->capacity - 1)
    {
        printf("Hang doi day.\n");
        reuturn;
    }
}