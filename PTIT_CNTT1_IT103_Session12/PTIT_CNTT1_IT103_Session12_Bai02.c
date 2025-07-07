#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
};

void append(struct Node **headRef, int data)
{
    struct Node *newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    struct Node *temp = *headRef;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
}

void traverseForward(struct Node *head)
{
    struct Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("Node %d: %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

int main()
{
    struct Node *head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    traverseForward(head);
    printListForward(head);

    return 0;
}
