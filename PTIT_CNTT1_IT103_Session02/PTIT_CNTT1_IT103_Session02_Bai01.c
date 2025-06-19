#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Khong the cap phat bo nho.");
        return 1;
    }
    else

        for (int i = 0; i < n; i++)
        {
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &arr[i]);
        }

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Phan tu lon nhat trong mang la: %d\n", max);

    free(arr);
    return 0;
}