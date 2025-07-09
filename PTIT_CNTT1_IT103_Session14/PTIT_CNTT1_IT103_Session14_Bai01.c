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

int main()
{
    Stack *myStack = createStack();

    if (myStack->top == NULL)
    {
        printf("Ngăn xếp đã được khởi tạo và hiện đang rỗng.\n");
    }

    free(myStack);
    return 0;
}
