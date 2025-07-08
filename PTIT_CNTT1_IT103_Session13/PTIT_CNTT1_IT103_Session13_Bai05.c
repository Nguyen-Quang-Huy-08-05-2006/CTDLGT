#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *data;
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
    stack->data[stack->top] = value;
    return 1;
}

int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("No element in stack\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int arr[], int size)
{
    Stack *stack = createStack(size);

    for (int i = 0; i < size; i++)
    {
        push(stack, arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = pop(stack);
    }

    free(stack->data);
    free(stack);
}

int main()
{
    int n;
    printf("Moi ban nhap vao so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("So luong phan tu khong hop le!\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Khong the cap phat bo nho cho mang!\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Moi ban nhap phan tu tai vi tri thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Mang sau khi dao nguoc: ");
    printArray(arr, n);

    free(arr);
    return 0;
}