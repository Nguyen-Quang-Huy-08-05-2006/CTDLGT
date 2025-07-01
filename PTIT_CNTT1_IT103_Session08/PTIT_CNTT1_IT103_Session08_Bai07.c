#include <stdio.h>

void quickSort(int arr[], int n)
{
    if (n < 2)
        return;
    int pivot = arr[n / 2];
    int left[n], right[n];
    int leftCount = 0, rightCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n / 2)
            continue;
        if (arr[i] < pivot)
        {
            left[leftCount++] = arr[i];
        }
        if (arr[i] > pivot)
        {
            right[rightCount++] = arr[i];
        }
    }

    quickSort(left, leftCount);
    quickSort(right, rightCount);

    for (int i = 0; i < leftCount; i++)
    {
        arr[i] = left[i];
    }

    arr[leftCount] = pivot;
    for (int i = 0; i < rightCount; i++)
    {
        arr[leftCount + 1 + i] = right[i];
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

    quickSort(numbers, n);
    for (int i = 0; i < n; i++)
    {
        printf("numbers[%d]=%d\n", i, numbers[i]);
    }

    return 0;
}
