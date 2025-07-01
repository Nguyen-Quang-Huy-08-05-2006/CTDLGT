#include <stdio.h>

void linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("arr[%d] = %d\n", i, arr[i]);
            return;
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

    linearSearch(numbers, n, x);

    return 0;
}