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
struct Node *findMiddle(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    struct Node *head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("Danh sach hien tai:\n");
    traverseForward(head);

    struct Node *mid = findMiddle(head);
    if (mid != NULL)
        printf("Phan tu o giua danh sach la: %d\n", mid->data);
    else
        printf("Danh sach rong!\n");

    return 0;
}
