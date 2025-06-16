#include <stdio.h>
// cach1
void cach1(int n)
{
    int temp = 0;
    for (int i = 0; i <= n; i++)
    {
        temp += i;
    }
    printf("%d", temp);
}
// Do phuc tap la o(n)

// cach 2
void cach2(int n)
{
    int a = (n * (n + 1)) / 2;
    printf("%d", a);
}
// Do phuc tap la o(1)