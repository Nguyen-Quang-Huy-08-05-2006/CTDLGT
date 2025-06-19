#include <stdio.h>

int main()
{
    // int arr[n]
    int arr[10] = {8, 6, 4, 9, 10, 34, 2, 1, 44, 70};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

// Do phuc tap la o(n^2)