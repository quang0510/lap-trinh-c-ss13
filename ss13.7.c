#include <stdio.h>

void taoMaTran(int rows, int cols, int matrix[100][100]) {
    printf("Nhap gia tri cho ma tran (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void inMaTran(int rows, int cols, int matrix[100][100]) {
    printf("Ma tran (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    taoMaTran(rows, cols, matrix);

    inMaTran(rows, cols, matrix);

    return 0;
}

