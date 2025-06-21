#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;
    int tempN;
    pprintf("Nhap so phan tu cua mang: ");
    scanf("%d", &tempN);
    if (tempN <= 0)
    {
        printf("So phan tu phai la so nguyen duong.\n");
        return 1;
    }
    else if (tempN > 1000)
    {
        printf("So phan tu khong duoc lon hon 1000.\n");
        return 1;
    }
    n = tempN;
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

    int maxValue = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }

    printf("Max = %d", maxValue);

    free(arr);
    return 0;
}