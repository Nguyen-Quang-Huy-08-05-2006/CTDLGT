#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int main()
{
    Stack *myStack = createStack();
    int x;

    printf("Nhap so nguyen duong: ");
    scanf("%d", &x);

    if (x > 0)
    {
        push(myStack, x);
        printf("Da them %d vao ngan xep\n", x);
    }
    else
    {
        printf("Chi duoc nhap so nguyen duong\n");
    }

    free(myStack);
    return 0;
}
