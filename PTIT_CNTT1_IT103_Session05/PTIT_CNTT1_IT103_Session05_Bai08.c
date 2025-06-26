#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNumber(char *str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }
    if (str[i] == '\0')
    {
        return 0;
    }
    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int stringToInt(char *str, int index, int result)
{
    if (str[index] == '\0')
    {
        return result;
    }
    return stringToInt(str, index + 1, result * 10 + (str[index] - '0'));
}

int main()
{
    char str[100];
    printf("Nhap chuoi la so: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    size_t len = strlen(str);

    if (!isNumber(str))
    {
        printf("Chuoi khong phai la so.\n");
        return 0;
    }

    printf("%d", stringToInt(str, 0, 0));

    return 0;
}