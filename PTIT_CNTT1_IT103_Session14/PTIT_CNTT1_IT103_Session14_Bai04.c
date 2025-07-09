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

int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Ngan xep trong\n");
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void duyetStack(Stack *stack)
{
    Node *current = stack->top;
    if (current == NULL)
    {
        printf("Ngan xep trong\n");
        return;
    }
    printf("Stack = { ");
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
            printf("->");
        current = current->next;
    }
    printf("->NULL }\n");
}

int main()
{
    Stack *myStack = createStack();

    push(myStack, 5);
    push(myStack, 4);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 1);

    duyetStack(myStack);

    int layRa = pop(myStack);
    if (layRa != -1)
    {
        printf("Da lay ra phan tu: %d\n", layRa);
        duyetStack(myStack);
    }

    while (pop(myStack) != -1)
        ;

    duyetStack(myStack);

    free(myStack);
    return 0;
}
