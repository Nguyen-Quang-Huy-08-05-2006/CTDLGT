#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Dia %d di chuyen tu %c sang %c\n", n, source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Dia %d di chuyen tu %c sang %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le\n");
        return 0;
    }
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}