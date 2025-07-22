#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Khoi tao node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct Queue
{
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Node **)malloc(capacity * sizeof(Node *));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue *queue, Node *node)
{
    if (queue->rear == queue->capacity - 1)
    {
        printf("Hang doin day.\n");
        return;
    }
    queue->arr[++queue->rear] = node;
}

int isEmpty(Queue *queue)
{
    return queue->front > queue->rear;
}

// duyet levelOrder
int levelOrder(Node *root)
{
    int leafCount = 0;
    // b1 kiem tra cay
    if (root == NULL)
        return 0;

    // b2 khoi tao hang doi
    Queue *queue = createQueue(100);

    // b3 dua node root vap hang doi
    enqueue(queue, root);

    // b4 trien khai vong lap
    while (!isEmpty(queue))
    {
        // b5 lay Node dau hang doi
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);

        if (node->left == NULL && node->right == NULL)
        {
            leafCount++;
        }

        // b6 kiem tra Node con con khong
        if (node->left != NULL)
        {
            enqueue(queue, node->left);
        }
        if (node->right != NULL)
        {
            enqueue(queue, node->right);
        }
    }
    return leafCount;
}

int main(void)
{
    Node *root = NULL;
    root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

    int n = levelOrder(root);

    if (n == 0)
    {
        printf("Cay rong.");
        return 0;
    }
    else
    {

        printf("\nSo la cay la: %d\n", n);
    }

    return 0;
}