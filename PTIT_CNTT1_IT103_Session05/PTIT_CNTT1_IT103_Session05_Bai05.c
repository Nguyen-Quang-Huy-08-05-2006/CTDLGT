#include <stdio.h>

int sum(int char, int n)
{
    if (n < m)
    {
        return 0;
    }
    else
    {
        return n + sum(m, n - 1);
    }
}

int main()
{
    int char[1000];
    printf("Nhap so thu nhat: ");
    scanf("%d", &m);
    printf("Nhap so thu hai: ");
    scanf("%d", &n);
    if (m < 0 || n < 0 || m > n)
    {
        printf("Khong hop le.\n");
        return 1;
    }
    printf("%d", sum(m, n));
    return 0;
}