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

// duyet preOrder
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
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
void levelOrder(Node *root)
{
    // b1 kiem tra cay
    if (root == NULL)
        return;

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
}

int findLevel(Node *root, int value, int level)
{
    if (root == NULL)
        return 0;

    if (root->data == value)
        return level;

    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != 0)
        return leftLevel;

    return findLevel(root->right, value, level + 1);
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

    levelOrder(root);
    printf("\n");

    int n;
    printf("Nhap gia tri cua tang can tim: ");
    scanf("%d", &n);

    int level = findLevel(root, n, 1);

    if (level == 0)
        printf("Gia tri %d khong ton tai.\n", n);
    else
        printf("Node level: %d", level);

    return 0;
}