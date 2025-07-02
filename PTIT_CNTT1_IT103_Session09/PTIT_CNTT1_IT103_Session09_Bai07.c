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

void insertNode(struct Node **head, int value, int position)
{
    struct Node *newNode = createNode(value);

    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    int index = 0;

    while (temp != NULL && index < position - 1)
    {
        temp = temp->next;
        index++;
    }

    if (temp == NULL)
    {
        printf("Vi tri vuot qua do dai danh sach. Khong them duoc.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    struct Node *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printList(head);

    int x, n;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &x);
    printf("Nhap vi tri muon them: ");
    scanf("%d", &n);
    insertNode(&head, x, n);
    printList(head);

    return 0;
}
