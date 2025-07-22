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

    printf("Node {\n\tdata: %d,\n\tLeft: %d,\n\tRight: %d\n}", root->data, root->left->data, root->right->data);

    return 0;
}