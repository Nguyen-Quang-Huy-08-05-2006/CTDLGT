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

void addToHead(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

int main()
{
    struct Node *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printfList(head);

    int n;
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Khong hop le.");
        return 1;
    }
    addToHead(&head, n);
    printList(head);

    return 0;
}
