#include <stdio.h>

int main()
{
    // int arr[n]
    int count;
    int arr[10] = {1, 2, 4, 6, 99, 0, 2, 45, 2, 1};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] == 2)
        {
            count++;
        }
    }
    printf("so lan xuat hien cua so can tim la %d", count);

    return 0;
}
// do phuc tap la o(n)