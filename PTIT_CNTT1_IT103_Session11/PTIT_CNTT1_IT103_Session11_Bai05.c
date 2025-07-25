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

void prepend(struct Node **headRef, int data)
{
    struct Node *newNode = createNode(data);

    newNode->next = *headRef;
    if (*headRef != NULL)
    {
        (*headRef)->previous = newNode;
    }

    *headRef = newNode;

    while (newNode->next != NULL)
    {
        newNode = newNode->next;
    }
}

void traverseForward(struct Node *head)
{
    struct Node *temp = head;
    int index = 1;
    while (temp != NULL)
    {
        printf("Node %d: %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
}

int main()
{
    int n;
    struct Node *head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Danh sach truoc khi them: \n");
    traverseForward(head);

    printf("Nhap gia tri muonthem: ");
    scanf("%d", &n);
    prepend(&head, n);

    printf("Danh sach sau khi them: \n");
    traverseForward(head);

    return 0;
}
