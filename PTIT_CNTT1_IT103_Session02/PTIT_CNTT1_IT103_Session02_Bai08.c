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
    {
        printf("Cap phat bo nho thanh cong.\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Cac phan tu lon hon so dung sau la: ");
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("%d ", arr[i]);
        }
    }

    free(arr);
    return 0;
}