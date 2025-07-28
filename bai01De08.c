#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100

typedef struct Student
{
    int id;
    char name[50];
    int status;
    int avg;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

typedef struct Node
{
    Student data;
    struct Node *prev;
    struct Node *next;
} Node;

struct Node *createNode(Student data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendNode(struct Node **head, Student data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void newStudent(Node **inActiveList, Student students[], int *studentCount)
{
    Student newStudent;
    printf("Nhap ID sinh vien: ");
    scanf("%d", &newStudent.id);
    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    printf("Nhap diem trung binh: ");
    scanf("%d", &newStudent.avg);
    printf("Nhap trang thai sinh vien (1 = hoat dong, 0 = khong hoat dong): ");
    scanf("%d", &newStudent.status);
    if (newStudent.status == 1)
    {
        if (*studentCount < MAX_STUDENTS)
        {
            students[*studentCount] = newStudent;
            (*studentCount)++;
            printf("Them sinh vien thanh cong.\n");
        }
        else
        {
            printf("Danh sach sinh vien da day");
            return;
        }
    }
    else if (newStudent.status == 0)
    {
        appendNode(inActiveList, newStudent);
        printf("Them sinh vien thanh cong.\n");
    }
    else
    {
        printf("Trang thai khong hop le.");
        return;
    }
}

void printStudent(Node *head, Student students[], int *studentCount)
{
    Node *current = head;
    printf("Danh sach sinh vien: \n");
    for (int i = 0; i < *studentCount; i++)
    {
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        if (students[i].status == 1)
        {
            printf("Trang thai: Hoat dong \n");
        }
        else
        {
            printf("Trang thai: Khong hoat dong\n");
        }
        printf("Diem trung binh: %d\n", students[i].avg);
        printf("----------------------------------\n");
    }

    while (current != NULL)
    {
        printf("ID: %d\n", current->data.id);
        printf("Ten: %s\n", current->data.name);
        if (current->data.status == 1)
        {
            printf("Trang thai: Hoat dong \n");
        }
        else
        {
            printf("Trang thai: Khong hoat dong\n");
        }
        printf("Diem trung binh: %d\n", current->data.avg);
        current = current->next;
        printf("----------------------------------\n");
    }
}

void deleteStudent(Node **head, Student sutdents[], int *studentCount)
{
    int n;
    printf("Nhap id sinh vien can xoa: ");
    scanf("%d", &n);
    Node *current = *head;
    while (current != NULL)
    {
        if (n == current->data.id)
        {
            if (current->prev == NULL)
            {
                *head = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = NULL;
                }
            }
            else if (current->next == NULL)
            {
                current->prev->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("Xoa sinh vien thanh cong.\n");
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay sinh vien can tim.\n");
}

void updateStudent(Node *head, Student students[], int *studentCount)
{
    int n;
    printf("Nhap id sinh vien can cap nhat: ");
    scanf("%d", &n);
    Node *current = head;
    while (current != NULL)
    {
        if (current->data.id == n)
        {
            printf("Nhap ten moi: ");
            getchar();
            fgets(current->data.name, sizeof(current->data.name), stdin);
            current->data.name[strcspn(current->data.name, "\n")] = '\0';
            printf("Nhap diem trung binh moi: ");
            scanf("%d", &current->data.avg);
            printf("Cap nhat thong tin thanh cong.\n");
            return;
        }
        current = current->next;
    }
    for (int i = 0; i < *studentCount; i++)
    {
        if (students[i].id == n)
        {
            printf("Nhap ten moi: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Nhap diem trung binh moi: ");
            scanf("%d", &students[i].avg);
            printf("Cap nhat thong tin thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien can tim.\n");
    return;
}

void changeStatus(Node *head, Student students[], int *studentCount)
{
    printf("Nhap vao id sinh vien muon thay doi trang thai: ");
    int n, temp;
    scanf("%d", &n);
    Node *current = head;
    while (current != NULL)
    {
        if (current->data.id == n)
        {
            printf("Sinh vien ID: %d dang co trang thai khong hoat dong, ban co muon thay doi khong (1 = co, 0 = khong): ", current->data.id);
            scanf("%d", &temp);
            if (temp == 1)
            {
                current->data.status = 1;
                printf("Thay doi trang thai thanh cong.");
                return;
            }
            else if (temp == 0)
            {
                return;
            }
            else
            {
                printf("Sai cu phap!");
                return;
            }
        }
        current = current->next;
    }
    for (int i = 0; i < *studentCount; i++)
    {
        if (students[i].id == n)
        {
            printf("Sinh vien ID: %d dang co trang thai hoat dong, ban co muon thay doi khong (1 = co, 0 = khong): ", students[i].id);
            scanf("%d", &temp);
            if (temp == 1)
            {
                students[i].status = 0;
                printf("Thay doi trang thai thanh cong.\n");
                return;
            }
            else if (temp == 0)
            {
                return;
            }
            else
            {
                printf("Sai cu phap!\n");
                return;
            }
        }
    }
    printf("Khong tim thay sinh vien can tim.\n");
}
Student allStudents[MAX_STUDENTS];
int count = 0;

void mergeSortStudent(Student allStudents[], Node *head, Student students[], int *studentCount, int count)
{
    for (int i = 0; i < studentCount; i++)
    {
        allStudents[count++] = students[i];
    }

    Node *current = head;
    while (current != NULL)
    {
        allStudents[count++] = current->data;
        current = current->next;
    }
}

int main(void)
{
    Node *inActiveList = NULL;
    int answer;
    do
    {
        printf("————————— STUDENT MANAGER —————————\n");
        printf("1.Thêm sinh viên\n");
        printf("2.Hiển thị danh sách sinh viên\n");
        printf("3.Xóa sinh viên\n");
        printf("4.Cập nhật thông tin sinh viên\n");
        printf("5.Thay đổi trạng thái sinh viên\n");
        printf("6.Sắp xếp sinh viên\n");
        printf("7.Tìm kiếm sinh viên\n");
        printf("8.Thoát chương trình\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            newStudent(&inActiveList, students, &studentCount);
            break;
        case 2:
            printStudent(inActiveList, students, &studentCount);
            break;
        case 3:
            deleteStudent(&inActiveList, students, &studentCount);
            break;
        case 4:
            updateStudent(inActiveList, students, &studentCount);
            break;
        case 5:
            changeStatus(inActiveList, students, &studentCount);
            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            printf("Dang dong chuong trinh...\n");
            break;

        default:
            printf("Sai cu phap.\n");
            break;
        }

    } while (answer != 8);
}
