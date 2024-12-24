#include <stdio.h>
#include <string.h>

struct Library {
    int bookCode;
    char bookTitle[50];
    char author[50];
    char genre[50];
    float price;
};

void numbersAndInfo(struct Library books[], int *n);
void printInfo(struct Library books[], int n);
void addBook(struct Library books[], int *n);
void deleteBook(struct Library books[], int *n);
void updateBook(struct Library books[], int n);
void sortBook(struct Library books[], int n);
void findBook(struct Library books[], int n);

int main() {
    struct Library books[50];
    int type, n = 0, check = 0;
    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &type);
        getchar();

        switch (type) {
            case 1:
                numbersAndInfo(books, &n);
                check = -1;
                break;
            case 2:
                if (check) {
                    printInfo(books, n);
                } else {
                    printf("Chua co thong tin sach. Vui long nhap truoc!\n");
                }
                break;
            case 3:
                if (check) {
                    addBook(books, &n);
                } else {
                    printf("Chua co thong tin sach. Vui long nhap truoc!\n");
                }
                break;
            case 4:
                if (check) {
                    deleteBook(books, &n);
                } else {
                    printf("Chua co thong tin sach. Vui long nhap truoc!\n");
                }
                break;
            case 5:
                if (check) {
                    updateBook(books, n);
                } else {
                    printf("Chua co thong tin sach. Vui long nhap truoc!\n");
                }
                break;
            case 6:
                if (check) {
                    sortBook(books, n);
                } else {
                    printf("Chua co thong tin sach. Vui long nhap truoc!\n");
                }
                break;
            case 7:
                if (check) {
                    findBook(books, n);
                } else {
                    printf("Chua co thong tin sach. Vui long nhap truoc!\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh. Cam on ban da su dung!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (type != 8);
    return 0;
}

void numbersAndInfo(struct Library books[], int *n) {
    printf("Vui long nhap so luong sach: ");
    scanf("%d", n);
    getchar();
    int i = 0;
    while (i < *n) {
        printf("Vui long nhap ma sach: ");
        scanf("%d", &(books[i].bookCode));
        getchar();
        printf("Vui long nhap ten sach: ");
        fgets(books[i].bookTitle, sizeof books[i].bookTitle, stdin);
        books[i].bookTitle[strcspn(books[i].bookTitle, "\n")] = '\0';
        printf("Vui long nhap tac gia: ");
        fgets(books[i].author, sizeof books[i].author, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';
        printf("Vui long nhap the loai: ");
        fgets(books[i].genre, sizeof books[i].genre, stdin);
        books[i].genre[strcspn(books[i].genre, "\n")] = '\0';
        printf("Vui long nhap gia sach: ");
        scanf("%f", &(books[i].price));
        getchar();
        i++;
    }
}

void printInfo(struct Library books[], int n) {
    int i = 0;
    while (i < n) {
        printf("Ma sach: %d\n", books[i].bookCode);
        printf("Ten sach: %s\n", books[i].bookTitle);
        printf("Tac gia: %s\n", books[i].author);
        printf("The loai: %s\n", books[i].genre);
        printf("Gia sach: %.2f\n", books[i].price);
        i++;
    }
}

void addBook(struct Library books[], int *n) {
    int index;
    printf("Vui long nhap vi tri muon chen sach (1->%d): ", *n);
    scanf("%d", &index);
    getchar();
    if (index > 0 && index <= *n) {
        index--;
        int i = 0;
        while (*n - i > index) {
            books[*n - i] = books[*n - i - 1];
            i++;
        }
        printf("Vui long nhap ma sach: ");
        scanf("%d", &(books[index].bookCode));
        getchar();
        printf("Vui long nhap ten sach: ");
        fgets(books[index].bookTitle, sizeof books[index].bookTitle, stdin);
        books[index].bookTitle[strcspn(books[index].bookTitle, "\n")] = '\0';
        printf("Vui long nhap tac gia: ");
        fgets(books[index].author, sizeof books[index].author, stdin);
        books[index].author[strcspn(books[index].author, "\n")] = '\0';
        printf("Vui long nhap the loai: ");
        fgets(books[index].genre, sizeof books[index].genre, stdin);
        books[index].genre[strcspn(books[index].genre, "\n")] = '\0';
        printf("Vui long nhap gia sach: ");
        scanf("%f", &(books[index].price));
        getchar();
        (*n)++;
    }
}

void deleteBook(struct Library books[], int *n) {
    int index, i = 0, j;
    printf("Vui long nhap ma sach muon xoa: ");
    scanf("%d", &index);
    getchar();
    while (i < *n) {
        if (index == books[i].bookCode) {
            j = i;
            while (j < *n - 1) {
                books[j] = books[j + 1];
                j++;
            }
            (*n)--;
        }
        i++;
    }
}

void updateBook(struct Library books[], int n) {
    int index;
    printf("Vui long nhap vi tri muon thay doi (1->%d): ", n);
    scanf("%d", &index);
    getchar();
    if (index > 0 && index <= n) {
        index--;
        printf("Vui long nhap ma sach: ");
        scanf("%d", &(books[index].bookCode));
        getchar();
        printf("Vui long nhap ten sach: ");
        fgets(books[index].bookTitle, sizeof books[index].bookTitle, stdin);
        books[index].bookTitle[strcspn(books[index].bookTitle, "\n")] = '\0';
        printf("Vui long nhap tac gia: ");
        fgets(books[index].author, sizeof books[index].author, stdin);
        books[index].author[strcspn(books[index].author, "\n")] = '\0';
        printf("Vui long nhap the loai: ");
        fgets(books[index].genre, sizeof books[index].genre, stdin);
        books[index].genre[strcspn(books[index].genre, "\n")] = '\0';
        printf("Vui long nhap gia sach: ");
        scanf("%f", &(books[index].price));
        getchar();
    }
}

void sortBook(struct Library books[], int n) {
    struct Library temp;
    int i = 0, j, choose;
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choose);
    getchar();
    while (i < n - 1) {
        j = i + 1;
        while (j < n) {
            if ((choose == 1 && books[i].price > books[j].price) || 
                (choose == 2 && books[i].price < books[j].price)) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void findBook(struct Library books[], int n) {
    char name[50];
    int found = 0;
    printf("Vui long nhap ten sach can tim: ");
    fgets(name, sizeof name, stdin);
    name[strcspn(name, "\n")] = '\0';
    int i = 0;
    while (i < n) {
        if (strcmp(books[i].bookTitle, name) == 0) {
            printf("Ma sach: %d\n", books[i].bookCode);
            printf("Ten sach: %s\n", books[i].bookTitle);
            printf("Tac gia: %s\n", books[i].author);
            printf("The loai: %s\n", books[i].genre);
            printf("Gia sach: %.2f\n", books[i].price);
            found = 1;
        }
        i++;
    }
    if (!found) {
        printf("Khong tim thay sach voi ten: %s\n", name);
    }
}

