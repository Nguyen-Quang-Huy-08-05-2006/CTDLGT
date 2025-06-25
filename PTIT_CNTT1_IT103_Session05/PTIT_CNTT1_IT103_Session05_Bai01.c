#include <stdio.h>

void print(int n)
{
    if (n > 0)
    {
        print(n - 1);
        printf("%d ", n);
    }
}

int main()
{
    int n;
    printf("Nhap so bat ky: ");
    scanf("%d", &n);
    print(n);
    return 0;
}