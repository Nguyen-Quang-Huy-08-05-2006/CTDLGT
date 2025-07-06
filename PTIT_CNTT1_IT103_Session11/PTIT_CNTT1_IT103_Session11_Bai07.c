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

void insertAtPosition(struct Node **headRef, int data, int position)
{
    if (position < 1)
    {
        printf("Vị trí không hợp lệ.\n");
        return;
    }

    struct Node *newNode = createNode(data);

    if (position == 1)
    {
        newNode->next = *headRef;
        if (*headRef != NULL)
        {
            (*headRef)->previous = newNode;
        }
        *headRef = newNode;
        return;
    }

    struct Node *temp = *headRef;
    int index = 1;

    while (temp != NULL && index < position - 1)
    {
        temp = temp->next;
        index++;
    }

    if (temp == NULL)
    {
        printf("Vị trí vượt quá độ dài danh sách.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->previous = temp;

    if (temp->next != NULL)
    {
        temp->next->previous = newNode;
    }

    temp->next = newNode;
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
    int value, position;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    traverseForward(head);

    printf("Nhập giá trị muốn thêm: ");
    scanf("%d", &value);
    printf("Nhập vị trí muốn thêm (bắt đầu từ 1): ");
    scanf("%d", &position);

    insertAtPosition(&head, value, position);

    printf("\nDanh sách sau khi thêm:\n");
    traverseForward(head);

    return 0;
}
