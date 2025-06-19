#include <stdio.h>

int main()
{
    int arr[10] = {1, 1, 4, 6, 1, 2, 2, 1, 9, 10};
    int temp;
    int indexTemp;
    int newTemp;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        temp = 0;
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (arr[i] == arr[j])
            {
                temp++;
            }
        }
        if (temp > newTemp)
        {
            newTemp = temp;
            indexTemp = arr[i];
        }
    }
    printf("So duoc lap nhieu nhat la %d voi %d lan lap", indexTemp, newTemp);
}

// do phuc tap thoi gian la o(n^2)
// do phuc tap khong gian la o(1)