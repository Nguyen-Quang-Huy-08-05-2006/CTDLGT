#include <stdio.h>

void insertSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\b\b}\n");
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

    insertSort(numbers, n);
    return 0;
}