#include <stdio.h>
#
int main() {
    int Mang[50], n = 0, chon;
    do {
        printf("\n---MENU---\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri cua no\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("Nhap so luong phan tu cua mang: ");
                scanf("%d", &n);
                printf("Nhap cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("Nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &Mang[i]);
                }
                break;

            case 2:
                printf("Cac phan tu trong mang: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", Mang[i]);
                }
                printf("\n");
                break;

            case 3: {
                int max = Mang[0];
                for (int i = 1; i < n; i++) {
                    if (Mang[i] > max) max = Mang[i];
                }
                printf("Gia tri lon nhat trong mang la: %d\n", max);
                break;
            }

            case 4:
                printf("Cac so nguyen to trong mang: ");
                for (int i = 0; i < n; i++) {
                    if (Mang[i]) {
                        printf("%d ", Mang[i]);
                    }
                }
                printf("\n");
                break;

            case 5: {
                int vitrithem, them;
                printf("Nhap vi tri can them: ");
                scanf("%d", &vitrithem);
                printf("Nhap gia tri can them: ");
                scanf("%d", &them);
                if (vitrithem < 0 || vitrithem > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = n; i > vitrithem; i--) {
                        Mang[i] = Mang[i - 1];
                    }
                    Mang[vitrithem] = them;
                    n++;
                }
                break;
            }

            case 6: {
                int vitrixoa;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &vitrixoa);
                if (vitrixoa < 0 || vitrixoa >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = vitrixoa; i < n - 1; i++) {
                        Mang[i] = Mang[i + 1];
                    }
                    n--;
                }
                break;
            }

            case 7:
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (Mang[i] > Mang[j]) {
                            int temp = Mang[i];
                            Mang[i] = Mang[j];
                            Mang[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", Mang[i]);
                }
                printf("\n");
                break;

            case 8: {
                int searchValue, check = -1;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &searchValue);
                for (int i = 0; i < n; i++) {
                    if (Mang[i] == searchValue) {
                        check = i;
                        break;
                    }
                }
                if (check != -1) {
                    printf("Gia tri %d nam o vi tri: %d\n", searchValue, check);
                } else {
                    printf("Khong tim thay gia tri %d trong mang.\n", searchValue);
                }
                break;
            }

            case 9:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 9);

    return 0;
}

