#include <stdio.h>
#include <stdlib.h>
int totalMainDiagonal(int **arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i][i];
    }
    return total;
}

int totalSecondaryDiagonal(int **arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i][n - 1 - i];
    }
    return total;
}

int main()
{

    int rows, cols;
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &rows);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &cols);
    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000)
    {
        printf("So hang va cot phai lon hon 0 va nho hon 1000.\n");
        return 1;
    }

    if (rows > cols || rows < cols)
    {
        printf("Khong ton tai duong cheo\n");
        return 1;
    }

    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL)
    {
        printf("Khong the cap phat bo nho.");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Khong the cap phat bo nho.");
            return 1;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Nhap phan tu arr[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    int totalMain = totalMainDiagonal(arr, rows);
    printf("Tong duong cheo chinh = %d\n", totalMain);

    int totalSecondary = totalSecondaryDiagonal(arr, rows);
    printf("Tong duong cheo phu = %d\n", totalSecondary);

    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}