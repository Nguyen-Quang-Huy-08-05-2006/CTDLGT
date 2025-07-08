#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *data;
    int top;
    int cap;
} Stack;

Stack *createStack(int cap)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (char *)malloc(cap * sizeof(char));
    stack->top = -1;
    stack->cap = cap;
    return stack;
}

void push(Stack *stack, char val)
{
    if (stack->top >= stack->cap - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++(stack->top)] = val;
}

char pop(Stack *stack)
{
    if (stack->top == -1)
        return '\0';
    return stack->data[(stack->top)--];
}

bool brackets(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValidBrackets(char *str)
{
    int len = strlen(str);
    Stack *stack = createStack(len);

    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{')
        {
            push(stack, c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            char top = pop(stack);
            if (!brackets(top, c))
            {
                free(stack->data);
                free(stack);
                return false;
            }
        }
    }

    bool valid = (stack->top == -1);
    free(stack->data);
    free(stack);
    return valid;
}

int main()
{
    char str[100];
    printf("Nhap bieu thuc: ");
    fgets(str, sizeof(str), stdin);

    if (isValidBrackets(str))
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }

    return 0;
}