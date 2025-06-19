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

    int findNum;
    printf("Nhap so can tim: ");
    scanf("%d", &findNum);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == findNum)
            found++;
    }
    if (found > 0)
    {
        printf("So %d xuat hien %d lan trong mang.\n", findNum, found);
    }
    else
    {
        printf("So %d khong xuat hien trong mang.\n", findNum);
    }

    free(arr);
    return 0;
}