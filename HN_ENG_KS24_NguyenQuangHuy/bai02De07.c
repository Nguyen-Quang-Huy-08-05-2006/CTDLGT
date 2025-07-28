#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct
{
    char url[100];
    char timeStamp[100];
} Operation;

typedef struct
{
    Operation data[MAX];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, Operation op)
{
    if (isFull(s))
    {
        printf("Stack đầy!\n");
        return;
    }
    s->data[++(s->top)] = op;
}

Operation pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack rỗng!\n");
        Operation empty = {"", ""};
        return empty;
    }
    return s->data[(s->top)--];
}

Operation peek(Stack *s)
{
    if (isEmpty(s))
    {
        Operation empty = {"", ""};
        return empty;
    }
    return s->data[s->top];
}

char *getTimeStamp()
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    static char buffer[100];
    strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}

void visit(Stack *backStack, Stack *forwardStack, char url[])
{
    Operation newOp;
    strcpy(newOp.url, url);
    strcpy(newOp.timeStamp, getTimeStamp());

    push(backStack, newOp);

    init(forwardStack);

    printf("Đã truy cập: %s\n", url);
}

void backward(Stack *backStack, Stack *forwardStack)
{
    if (backStack->top <= 0)
    {
        printf("Không thể quay lại!\n");
        return;
    }

    Operation current = pop(backStack);
    push(forwardStack, current);

    Operation now = peek(backStack);
    printf("Quay lại: %s (thời gian: %s)\n", now.url, now.timeStamp);
}

void forward(Stack *backStack, Stack *forwardStack)
{
    if (isEmpty(forwardStack))
    {
        printf("Không có trang nào để tiến tới!\n");
        return;
    }

    Operation next = pop(forwardStack);
    push(backStack, next);

    printf("Tiến tới: %s (thời gian: %s)\n", next.url, next.timeStamp);
}

void current(Stack *backStack)
{
    if (isEmpty(backStack))
    {
        printf("Không có trang web nào đang mở!\n");
        return;
    }

    Operation now = peek(backStack);
    printf("Trang hiện tại: %s (truy cập lúc: %s)\n", now.url, now.timeStamp);
}

int main()
{
    Stack backStack, forwardStack;
    init(&backStack);
    init(&forwardStack);

    int choice;
    char url[100];

    do
    {
        printf("\n——————————— WEB HISTORY ———————————\n");
        printf("1. VISIT url\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENT\n");
        printf("5. THOÁT\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Nhập URL cần truy cập: ");
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = '\0';
            visit(&backStack, &forwardStack, url);
            break;
        case 2:
            backward(&backStack, &forwardStack);
            break;
        case 3:
            forward(&backStack, &forwardStack);
            break;
        case 4:
            current(&backStack);
            break;
        case 5:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 5);

    return 0;
}
