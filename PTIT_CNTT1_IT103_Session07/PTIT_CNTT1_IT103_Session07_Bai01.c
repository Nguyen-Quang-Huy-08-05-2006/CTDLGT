#include <stdio.h>

void bubleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("numbers[%d]=%d\n", i, arr[i]);
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu:");
    scanf("%d", &n);
    if (n < 0 || n > 1000)
    {
        printf("Khong hop le");
        return 1;
    }
    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        printf("numbers[%d] = ", i);
        scanf("%d", &numbers[i]);
    }

    bubleSort(numbers, n);
    return 0;
}