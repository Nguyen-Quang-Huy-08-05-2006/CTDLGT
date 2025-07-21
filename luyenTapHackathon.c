#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 10

typedef struct Call
{
    char phoneNumber[MAX_LEN];
    int time;
} Call;

typedef struct Stack
{
    Call *call;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

typedef struct Queue
{
    Call *call;
    int front;
    int rear;
    int capacity;
}

struct Queue *
createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;

    return queue;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void push(Stack *backStack, Call call)
{
    if (isFull(stack))
    {
        printf("Stack overflow");
        return 0;
    }
    stack->data[stack->top] = call;
    return 1;
}

int queueFull(struct Queue *queue)
{
    return queue->rear == queue->capacity - 1;
};

int enqueue(struct Queue *queue, int value)
{
    if (queueFull(queue))
    {
        printf("Queue's full.");
        return 0;
    }
    queue->call[++queue->rear] = call;
    return 1;
}

int main(void)
{
    
    int answer;
    do
    {
        printf("----MENU----\n");
        printf("1.CALL.\n");
        printf("2.BACK.\n");
        printf("3.REDIAL.\n");
        printf("4.HISTORY.\n");
        printf("5.THOAT.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Dang ket thuc chuong trinh...");
            return 0;

        default:
            printf("Sai cu phap.");
            break;
        }

    } while (answer != 5);
}