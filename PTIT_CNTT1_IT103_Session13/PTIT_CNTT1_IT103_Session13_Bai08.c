#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int *arr;
    int maxSize;
};

struct Stack *createStack(int maxSize)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->arr = (int *)malloc(maxSize * sizeof(int));
    stack->top = -1;
    stack->maxSize = maxSize;
    return stack;
}

void printStack(struct Stack *stack)
{
    printf("Stack (top = %d, maxSize = %d): ", stack->top, stack->maxSize);
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->maxSize - 1;
}

void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack day! Khong the push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rong! Khong the pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int main()
{
    struct Stack *myStack = createStack(5);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printStack(myStack);

    int popped = pop(myStack);
    printf("Pop: %d\n", popped);

    printStack(myStack);

    return 0;
}
