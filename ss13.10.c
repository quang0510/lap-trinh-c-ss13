#include <stdio.h>
#include <stdlib.h>

void nhapMang(int arr[], int *n) {
    printf("Nhap so luong phan tu (toi da 100): ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void inMang(int arr[], int n) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu(int arr[], int *n) {
    int pos, value;
    printf("Nhap vi tri muon them (0 den %d): ", *n);
    scanf("%d", &pos);
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void suaPhanTu(int arr[], int n) {
    int pos, value;
    printf("Nhap vi tri muon sua (0 den %d): ", n - 1);
    scanf("%d", &pos);
    printf("Nhap gia tri moi: ");
    scanf("%d", &value);
    arr[pos] = value;
}

void xoaPhanTu(int arr[], int *n) {
    int pos;
    printf("Nhap vi tri phan tu muon xoa (0 den %d): ", *n - 1);
    scanf("%d", &pos);
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void sapXepMang(int arr[], int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int timKiemTuyenTinh(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int timKiemNhiPhan(int arr[], int n, int key) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int choice;
    int arr[100];
    int n = 0;

    do {
        printf("\n********MENU******\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu (1: Giam dan, 2: Tang dan)\n");
        printf("7. Tim kiem phan tu (1: Tuyen tinh, 2: Nhi phan)\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3:
                themPhanTu(arr, &n);
                break;
            case 4:
                suaPhanTu(arr, n);
                break;
            case 5:
                xoaPhanTu(arr, &n);
                break;
            case 6: {
                int subChoice;
                printf("Chon cach sap xep (1: Giam dan, 2: Tang dan): ");
                scanf("%d", &subChoice);
                if (subChoice == 1 || subChoice == 2) {
                    sapXepMang(arr, n, subChoice == 2);
                    printf("Da sap xep xong!\n");
                }
                break;
            }
            case 7: {
                int key, subChoice;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &key);
                printf("Chon cach tim kiem (1: Tuyen tinh, 2: Nhi phan): ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    int index = timKiemTuyenTinh(arr, n, key);
                    if (index != -1) {
                        printf("Tim thay tai vi tri %d\n", index);
                    } else {
                        printf("Khong tim thay phan tu!\n");
                    }
                } else if (subChoice == 2) {
                    sapXepMang(arr, n, 1);
                    int index = timKiemNhiPhan(arr, n, key);
                    if (index != -1) {
                        printf("Tim thay tai vi tri %d\n", index);
                    } else {
                        printf("Khong tim thay phan tu!\n");
                    }
                }
                break;
            }
            case 8:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}
