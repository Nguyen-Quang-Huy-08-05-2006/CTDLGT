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

void deleteAtPosition(struct Node **headRef, int position)
{
    if (*headRef == NULL || position < 1)
    {
        printf("Danh sách rỗng hoặc vị trí không hợp lệ.\n");
        return;
    }

    struct Node *temp = *headRef;
    int index = 1;

    if (position == 1)
    {
        *headRef = temp->next;
        if (*headRef != NULL)
        {
            (*headRef)->previous = NULL;
        }
        free(temp);
        return;
    }

    while (temp != NULL && index < position)
    {
        temp = temp->next;
        index++;
    }

    if (temp == NULL)
    {
        printf("Vị trí vượt quá độ dài danh sách.\n");
        return;
    }

    if (temp->previous != NULL)
    {
        temp->previous->next = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->previous = temp->previous;
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
    int position;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    traverseForward(head);

    printf("Nhập vị trí muốn xoá : ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("\nDanh sách sau khi xoá:\n");
    traverseForward(head);

    return 0;
}
