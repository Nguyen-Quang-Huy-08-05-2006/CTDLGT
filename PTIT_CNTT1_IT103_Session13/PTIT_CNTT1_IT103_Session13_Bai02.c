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

    printStack(stack);
    printf("Cap: %d\n", max);
    printf("Top: %d\n", stack->top);

    free(stack->stack);
    free(stack);
    return 0;
}