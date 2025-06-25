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
    int temp;
    printf("Nhap so can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == x)
        {
            temp = i;
        }
    }
    printf("%d.\n", temp);
    return 0;
}