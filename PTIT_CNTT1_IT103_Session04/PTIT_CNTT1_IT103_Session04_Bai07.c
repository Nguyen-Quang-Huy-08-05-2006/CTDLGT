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

    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] == numbers[j])
            {
                if (i + j == n - 1)
                {
                    printf("Cap doi xung: (%d; %d)\n", numbers[i], numbers[j]);
                    a++;
                }
            }
        }
    }

    if (a == 0)
    {
        printf("Khong co cap doi xung");
    }
    return 0;
}