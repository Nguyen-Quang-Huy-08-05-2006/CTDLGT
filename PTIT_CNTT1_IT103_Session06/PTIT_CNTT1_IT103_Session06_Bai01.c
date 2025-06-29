#include <stdio.h>

int toBinary(int n)
{
    if (n == 0)
    {
        return 0;
    }
    toBinary(n / 2);
    printf("%d", n % 2);
}

int main()
{
    int n;
    printf("Nhap so bat ky: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("khong hop le");
        return 1;
    }

    toBinary(n);

    return 0;
}