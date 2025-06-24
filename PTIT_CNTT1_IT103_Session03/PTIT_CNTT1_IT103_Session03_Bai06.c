#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int *arr;

    printf("Nhap so luong phan tu ban dau n: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000)
    {
        printf("Gia tri n khong hop le. Phai nam trong khoang (0, 1000).\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so luong phan tu muon them m: ");
    scanf("%d", &m);

    if (m <= 0 || n + m >= 1000)
    {
        printf("So luong phan tu moi khong hop le.\n");
        free(arr);
        return 1;
    }

    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    if (arr == NULL)
    {
        printf("Khong the cap phat lai bo nho.\n");
        return 1;
    }

    printf("Nhap %d phan tu them vao:\n", m);
    for (int i = n; i < n + m; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang sau khi them:\n");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
