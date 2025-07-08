#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *stack;
    int top;
    int cap;
} Stack;

Stack *createStack(int cap)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->top = -1;
    stack->cap = cap;
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->cap - 1;
}

int push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        return 0;
    }
    stack->top += 1;
    stack->stack[stack->top] = value;
    return 1;
}

void printStack(Stack *stack)
{
    printf("Stack (top -> bottom): ");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->stack[i]);
    }
    printf("\n");
}

int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("No element in stack\n");
        return -1;
    }
    int value = stack->stack[stack->top];
    stack->top--;
    return value;
}

void printStackLIFO(Stack *stack)
{
    printf("Stack theo LIFO:\n");
    while (stack->top != -1)
    {
        int val = pop(stack);
        printf("%d ", val);
    }
    printf("\n");
}

int main(void)
{
    int max = 5;
    int value;
    Stack *stack = createStack(max);

    for (int i = 0; i < max; i++)
    {
        printf("Moi ban nhap vao phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        push(stack, value);
    }

    printStackLIFO(stack);
    free(stack->stack);
    free(stack);
    return 0;
}