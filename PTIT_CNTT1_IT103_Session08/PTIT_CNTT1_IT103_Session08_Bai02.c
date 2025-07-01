#include <stdio.h>
void sortArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\b\b}\n");
}

void binarySearch(int arr[], int left, int right, int x)
{
    sortArr(arr, right + 1);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            printf("arr[%d] = %d\n", mid, arr[mid]);
            return;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("Khong ton tai phan tu.\n");
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

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    binarySearch(numbers, 0, n - 1, x);

    return 0;
}