#include <stdio.h>
#include <stdlib.h>
float evenAverage(int *arr, int n)
{
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0)
    {
        printf("Khong co so chan trong mang.\n");
        return -1;
    }
    else if (count == 1)
    {
        printf("Trung binh cong cua so chan trong mang la: %d\n", sum);
        return sum;
    }
    else
    {
        float average = (float)sum / count;
        printf("Trung binh cong cua so chan trong mang la: %.2f\n", average);
        return average;
    }
}

int main()
{
    int n;
    int *arr;
    int tempN;
    printf("Nhap so phan tu cua mang: ");
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

    float average = evenAverage(arr, n);
    if (average != -1)
    {
        printf("Average = %.2f\n", average);
    }

    free(arr);
    return 0;
}