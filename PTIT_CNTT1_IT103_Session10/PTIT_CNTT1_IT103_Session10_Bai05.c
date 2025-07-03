#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
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
    return newNode;
}

void appendNode(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    printf("Danh sach lien ket: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteByValue(struct Node **head, int target)
{
    while (*head != NULL && (*head)->data == target)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL)
        return;

    struct Node *current = *head;
    while (current->next != NULL)
    {
        if (current->next->data == target)
        {
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    struct Node *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 2);
    appendNode(&head, 4);
    appendNode(&head, 2);
    appendNode(&head, 5);

    printf("Danh sach ban dau:\n");
    printList(head);

    int value;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &value);

    deleteByValue(&head, value);

    printf("Danh sach sau khi xoa %d:\n", value);
    printList(head);

    return 0;
}
