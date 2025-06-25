#include <stdio.h>

int main()
{
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr [%d] = ", i);
        scanf("%d", &numbers[i]);
    }

    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == x)
        {
            printf("%d xuat hien tai vi tri %d\n", x, i + 1);
            return 0;
        }
    }
    printf("khong tim thay phan tu.\n", x);
    return 0;
}