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

    int x = numbers[0];
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > x)
        {
            x = numbers[i];
        }
    }
    printf("Phan tu lon nhat la %d.\n", x);
    return 0;
}