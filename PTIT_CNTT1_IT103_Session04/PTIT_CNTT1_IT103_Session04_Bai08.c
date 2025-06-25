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

    int a = 0;
    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == x)
        {
            printf("%d\n", i);
            a++;
        }
    }
    if (a == 0)
    {
        printf("Khong co phan tu trong mang.\n");
    }
    return 0;
}