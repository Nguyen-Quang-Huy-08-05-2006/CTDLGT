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

int searchNode(Node *root, int n)
{
    if (root == NULL)
        return 0;
    if (root->data == n)
        return 1;
    return searchNode(root->left, n) || searchNode(root->right, n);
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

    preOrder(root);

    int n;
    printf("\nNhap so nguyen can tim: ");
    scanf("%d", &n);

    if (searchNode(root, n))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}