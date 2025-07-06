#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("<->");
        head = head->next;
    }
    printf("->NULL\n");
}
int search(Node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return 1;
        head = head->next;
    }
    return 0;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 1; i <= 5; i++)
    {
        Node *newNode = createNode(i);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    printf("Danh sach lien ket doi:\n");
    printList(head);
    int x;
    printf("\nNhap so can tim: ");
    scanf("%d", &x);
    if (search(head, x))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}