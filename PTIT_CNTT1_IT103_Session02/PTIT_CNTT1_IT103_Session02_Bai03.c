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

    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}