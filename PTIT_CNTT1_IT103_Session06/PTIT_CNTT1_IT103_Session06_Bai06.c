#include <stdio.h>

int stepsCount(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    return stepsCount(n - 1) + stepsCount(n - 2);
}

int main()
{
    int n;
    printf("Nhap vao so bac cua cau thang:");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("khong hop le!");
        return 0;
    }

    printf("%d", stepsCount(n));
    return 0;
}