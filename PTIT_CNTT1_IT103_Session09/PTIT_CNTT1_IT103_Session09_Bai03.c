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

void browseList(struct Node *head)
{
    struct Node *current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void searcheNode(struct Node *head, int target)
{
    struct Node *current = head;
    int found = 0;
    int index = 0;

    while (current != NULL)
    {
        if (current->data == target)
        {
            printf("TRUE\n");
            found = 1;
            break;
        }
        current = current->next;
        index++;
    }

    if (!found)
    {
        printf("FALSE\n", target);
    }
}

int main()
{
    struct Node *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    browseList(head);

    int n;
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Khong hop le.\n");
        return 1;
    }
    appendNode(&head, n);
    browseList(head);

    return 0;
}
