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
    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Queue *q = createQueue();
    int n, val;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &val);
        enqueue(q, val);
    }
    printQueue(q);
    return 0;
}