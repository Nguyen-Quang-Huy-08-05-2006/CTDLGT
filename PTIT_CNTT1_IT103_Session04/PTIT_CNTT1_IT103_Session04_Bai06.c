#include <stdio.h>

struct student
{
    int id;
    int age;
    char name[50];
};

typedef struct student Student;

int main()
{
    struct student students[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Nhap thong tin sinh vien [%d] :\n", i);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        printf("Ten: ");
        scanf(" %[^\n]", students[i].name);
    }

    int x;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &x);

    for (int i = 0; i < 5; i++)
    {
        if (students[i].id == x)
        {
            printf("ID: %d\n", students[i].id);
            printf("Tuoi: %d\n", students[i].age);
            printf("Ten: %s\n", students[i].name);
            return 0;
        }
    }

    return 0;
}