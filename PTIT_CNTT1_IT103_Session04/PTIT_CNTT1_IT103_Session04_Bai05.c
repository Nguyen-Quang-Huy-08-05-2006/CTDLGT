#include <stdio.h>

int main()
{
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr [%d] = ", i);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);

    int left = 0;
    int right = n - 1;
    int mid = (right - left) / 2;
    int found = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (numbers[mid] == x)
        {
            found = 1;
            break;
        }
        else if (numbers[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (found == 0)
    {
        printf("Khong co phan tu trong mang.\n", x);
        return 0;
    }
    else
    {
        printf("%d xuat hien tai arr [%d]\n", x, mid);
    }
    return 0;
}