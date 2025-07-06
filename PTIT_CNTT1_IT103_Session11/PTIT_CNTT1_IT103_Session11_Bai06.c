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

void deleteHead(struct Node **headRef)
{
    if (*headRef == NULL)
    {
        printf("Danh sách rỗng. Không có gì để xóa.\n");
        return;
    }

    struct Node *temp = *headRef;
    *headRef = temp->next;

    if (*headRef != NULL)
    {
        (*headRef)->previous = NULL;
    }

    free(temp);
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

    printf("Danh sach truoc khi xoa: \n");
    deleteHead(&head);

    printf("Danh sach sau khi xoa: \n");
    deleteHead(head);

    return 0;
}
