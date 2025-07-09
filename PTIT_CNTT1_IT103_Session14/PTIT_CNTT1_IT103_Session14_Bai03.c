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

void duyetStack(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Ngan xep rong\n");
        return;
    }

    printf("Cac phan tu trong ngan xep:\n");
    Node *current = stack->top;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    Stack *myStack = createStack();

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    duyetStack(myStack);

    free(myStack);
    return 0;
}
