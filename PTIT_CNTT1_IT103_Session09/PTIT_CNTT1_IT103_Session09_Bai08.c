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

void deleteNode(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("Danh sach rong. Khong the xoa.\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        printf("Da xoa phan tu o vi tri 0.\n");
        return;
    }

    int index = 0;
    while (temp != NULL && index < position - 1)
    {
        temp = temp->next;
        index++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Vi tri khong hop le. Khong the xoa.\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
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

    int n;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &n);
    deleteNode(&head, n);
    printList(head);

    return 0;
}
