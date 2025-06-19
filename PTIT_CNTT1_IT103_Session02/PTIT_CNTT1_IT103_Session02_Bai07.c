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

    int total;
    printf("Nhap tong cua 2 so bat ky trong mang: ");
    scanf("%d", &total);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == total)
            {
                printf("%d va %d co tong bang %d.\n", arr[i], arr[j], total);
            }
        }
    }

    free(arr);
    return 0;
}