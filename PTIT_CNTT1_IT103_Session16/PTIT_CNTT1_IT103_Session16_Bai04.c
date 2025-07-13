#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void enqueue(Queue *q, int value)
{
    Node *newNode = createNode(value);
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
void printQueue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("empty queue\n");
    }
    else
    {
        printf("%d\n", q->front->data);
    }
}
int main()
{
    Queue *myQueue = createQueue();
    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(myQueue, value);
    }
    printQueue(myQueue);
    Node *temp;
    free(myQueue);

    return 0;
}