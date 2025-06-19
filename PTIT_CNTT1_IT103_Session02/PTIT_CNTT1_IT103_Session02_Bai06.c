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

    int addPos;
    printf("Nhap vi tri so ban muon them: ");
    scanf("%d", &addPos);
    int newValue;
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    if (addPos < 0 || addPos >= n)
    {
        printf("Vi tri khong hop le.\n");
    }
    else
    {
        int *temp = (int *)realloc(arr, (n + 1) * sizeof(int));
        if (temp == NULL)
        {
            printf("Khong the cap phat bo nho.");
            free(arr);
            return 1;
        }
        arr = temp;

        for (int i = n; i > addPos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[addPos] = newValue;
        n++;
        printf("Mang sau khi them la: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    free(arr);
    return 0;
}