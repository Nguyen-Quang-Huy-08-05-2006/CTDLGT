#include <stdio.h>
#include <stdlib.h>

int *mallocAray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

// do phuc tap khong gian la O(n)
