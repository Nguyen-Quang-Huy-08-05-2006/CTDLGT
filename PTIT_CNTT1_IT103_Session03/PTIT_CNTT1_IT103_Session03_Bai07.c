#include <stdio.h>

int tinhTongDong(int arr[][1000], int k, int cols)
{
    int sum = 0;
    for (int j = 0; j < cols; j++)
    {
        sum += arr[k][j];
    }
    return sum;
}

int main()
{
    int rows, cols, k;
    int arr[1000][1000];

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000)
    {
        printf("Kich thuoc khong hop le.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Nhap dong k muon tinh tong: ");
    scanf("%d", &k);

    if (k < 0 || k >= rows)
    {
        printf("Chi so dong khong hop le.\n");
        return 1;
    }

    int tong = tinhTongDong(arr, k, cols);
    printf("Tong dong %d la: %d\n", k, tong);

    return 0;
}
