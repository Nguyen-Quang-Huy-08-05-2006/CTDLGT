#include <stdio.h>

void insertionSort(int arr[], int n)
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
}

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void printArray(int arr[], int n)
{
    printf("Mang: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n], arrCopy[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arrCopy[i] = arr[i];
    }

    printf("\nMang ban dau:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nMang sau khi sap xep (Insertion Sort):\n");
    printArray(arr, n);

    int target;
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &target);

    int indexLinear = linearSearch(arrCopy, n, target);
    if (indexLinear != -1)
        printf("Tim thay %d o vi tri (linear search): %d\n", target, indexLinear);
    else
        printf("%d khong ton tai trong mang (linear search).\n", target);

    int indexBinary = binarySearch(arr, 0, n - 1, target);
    if (indexBinary != -1)
        printf("Tim thay %d o vi tri (binary search): %d\n", target, indexBinary);
    else
        printf("%d khong ton tai trong mang (binary search).\n", target);

    return 0;
}
