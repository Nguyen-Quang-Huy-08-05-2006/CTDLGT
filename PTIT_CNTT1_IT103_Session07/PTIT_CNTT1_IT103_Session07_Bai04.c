#include <stdio.h>
#include <string.h>

void stringSort(char str[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                int temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        {
            printf("%c", str[i]);
        }
    }
}

int main()
{
    char str[100];
    printf("Nhap chuoi bat ky:");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (str[0] == '\0' || str[0] == '\n')
    {
        printf("Khong hop le");
        return 1;
    }

    stringSort(str, strlen(str));
    return 0;
}