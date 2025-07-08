#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char *stack;
    int top;
    int cap;
} Stack;

Stack *createStack(int cap)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->top = -1;
    stack->cap = cap;

    stack->stack = (char *)malloc(sizeof(char) * cap);

    return stack;
}

int isfull(Stack *stack)
{
    if (stack->top == stack->cap - 1)
    {
        return 1;
    }
    return 0;
}

int push(Stack *stack, int value)
{
    if (isfull(stack))
    {
        printf("Stack overflow");
        return 0;
    }
    stack->top += 1;
    stack->stack[stack->top] = value;

    return 1;
}

int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow");
        return -1;
    }
    int temp = stack->stack[stack->top];
    stack->top--;
    return temp;
}

void isPalindrome(char str[])
{
    int length = strlen(str);
    Stack *stack = createStack(length);

    for (int i = 0; i < length; i++)
    {
        push(stack, str[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (str[i] != pop(stack))
        {
            printf("FALSE");
            free(stack->stack);
            return;
        }
    }
    printf("TRUE");
    free(stack->stack);
}

int main()
{
    char str[100];
    printf("Moi ban nhap vao chuoi can kiem tra: ");

    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    isPalindrome(str);
    return 0;
}