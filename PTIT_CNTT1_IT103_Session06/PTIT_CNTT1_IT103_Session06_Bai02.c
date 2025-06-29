#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Khong hop le");
        return 0;
    }
    int fibonacciArray[100];
    for (int i = 1; i <= n; i++)
    {
        fibonacciArray[i - 1] = fibonacci(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", fibonacciArray[i]);
    }
}