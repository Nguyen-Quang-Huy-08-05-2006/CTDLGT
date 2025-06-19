#include <stdio.h>

int main()
{
    int arr[5] = {1, 1, 3, 2, 5};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        for (int j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (arr[i] == arr[j])
            {
                printf("mang co phan tu trung lap");
            }
            else
            {
                printf("mamg khong co phan tu trung lap");
            }
        }
    }
    return 0;
}

// do phuc tap thoi gian la o(n^2)
// do phuc tap khong gian la o(1)