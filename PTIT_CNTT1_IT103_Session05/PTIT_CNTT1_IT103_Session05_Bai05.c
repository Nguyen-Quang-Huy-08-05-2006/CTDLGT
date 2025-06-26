#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalidrome(int left, int right, char *str)
{
    if (left >= right)
    {
        return 1;
    }
    if (str[left] != str[right])
    {
        return 0;
    }
    return isPalidrome(left + 1, right - 1, str);
}

int main()
{
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    size_t len = strlen(str);

    if (isPalidrome(0, len - 1, str))
    {
        printf("Palindrome valid.\n");
    }
    else
    {
        printf("Palindrome invalid.\n");
    }

    return 0;
}