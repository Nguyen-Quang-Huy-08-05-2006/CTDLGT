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

    int fixPos;
    printf("Nhap vi tri so can sua: ");
    scanf("%d", &fixPos);
    int newValue;
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    if (fixPos < 0 || fixPos >= n)
    {
        printf("Vi tri khong hop le.\n");
    }
    else
    {
        arr[fixPos] = newValue;
        printf("Mang sau khi sua la: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    free(arr);
    return 0;
}