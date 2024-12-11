#include <stdio.h>
#include <math.h>

int laSoNguyenTo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void nhapMang(int matrix[100][100], int n, int m) {
    printf("Nhap gia tri cho ma tran (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void inMaTran(int matrix[100][100], int n, int m) {
    printf("Ma tran (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void inCacGoc(int matrix[100][100], int n, int m) {
    printf("Cac phan tu o goc cua ma tran: ");
    printf("%d %d %d %d\n", 
           matrix[0][0], 
           matrix[0][m - 1], 
           matrix[n - 1][0], 
           matrix[n - 1][m - 1]);
}


void inDuongBien(int matrix[100][100], int n, int m) {
    printf("Cac phan tu tren duong bien cua ma tran: ");
    for (int i = 0; i < m; i++) printf("%d ", matrix[0][i]);  
    for (int i = 1; i < n - 1; i++) printf("%d %d ", matrix[i][0], matrix[i][m - 1]);
    for (int i = 0; i < m; i++) printf("%d ", matrix[n - 1][i]); 
    printf("\n");
}


void inDuongCheo(int matrix[100][100], int n, int m) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n && i < m; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");

    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < n && i < m; i++) {
        printf("%d ", matrix[i][m - i - 1]);
    }
    printf("\n");
}

void inSoNguyenTo(int matrix[100][100], int n, int m) {
    printf("Cac phan tu la so nguyen to trong ma tran: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laSoNguyenTo(matrix[i][j])) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    int matrix[100][100];
    int choice;

    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(matrix, n, m);
                break;
            case 2:
                inMaTran(matrix, n, m);
                break;
            case 3:
                inCacGoc(matrix, n, m);
                break;
            case 4:
                inDuongBien(matrix, n, m);
                break;
            case 5:
                inDuongCheo(matrix, n, m);
                break;
            case 6:
                inSoNguyenTo(matrix, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

