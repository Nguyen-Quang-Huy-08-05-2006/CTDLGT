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

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void findMax(Node *root)
{

    if (root == NULL)
        return;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->data;
    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;

    printf("Max value: %d", max);
}

int main(void)
{
    int n;
    printf("Nhap so nguyen bat ky: ");
    scanf("%d", &n);
    Node *root = NULL;
    root = createNode(n);
    Node *node1 = createNode(n + 1);
    Node *node2 = createNode(n + 2);
    Node *node3 = createNode(n + 3);
    Node *node4 = createNode(n + 4);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

    preOrder(root);
    printf("\n");
    findMax(root);

    return 0;
}