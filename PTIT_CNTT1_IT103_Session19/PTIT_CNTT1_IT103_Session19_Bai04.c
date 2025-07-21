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

// duyet inOrder
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
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

    inOrder(root);

    return 0;
}