#include <stdio.h>

int sum(int n, int index, int *numbers)
{
    if (n == index)
    {
        return 0;
    }
    return numbers[index] + sum(n, index + 1, numbers);
}

int main()
{
    int n;
    int numbers[100];
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("arr [%d] = ", i);
        scanf("%d", &numbers[i]);
    }
    printf("%d", sum(n, 0, numbers));
    return 0;
}