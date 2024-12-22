#include <stdio.h>
struct sinhVien {
    int id;
    char name[50];
    int age;
    char phoneNum[25];
};

void xoaSinhVien(struct sinhVien sinhVienList[], int *size, int id); 
void printSinhVienList(struct sinhVien sinhVienList[], int size); 
int main() {
    
    struct sinhVien sinhVienList[5] = {
       {1,"Nguyen Viet T",18,"0123456789"
		},
		{2,"Nguyen Duc T",18,"0987654321"
		},
		{3,"Nguyen Tung A",18,"013579"
		},
		{4,"Nguyen Gia B",18,"02468"
		},
		{5,"Vu Van D",18,"097531"
	},
    };

    int currentSize = 5;
    printf("Danh sach sinh vien truoc khi xoa:\n");
    printSinhVienList(sinhVienList, currentSize);

    int idDelete;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idDelete);

    
    xoaSinhVien(sinhVienList, &currentSize, idDelete);

  
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printSinhVienList(sinhVienList, currentSize);

    return 0;
}
void xoaSinhVien(struct sinhVien sinhVienList[], int *size, int id) {
int flag = 0; 
    for (int i = 0; i < *size; i++) {
        if (sinhVienList[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                sinhVienList[j] = sinhVienList[j + 1];
            }
            (*size)--; 
            flag = 1;  
            break;
        }
    }

    if (!flag) {
        printf("Sinh vien co ID %d khong ton tai!\n", id);
    }
}
void printSinhVienList(struct sinhVien sinhVienList[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n",
               sinhVienList[i].id, sinhVienList[i].name, sinhVienList[i].age, sinhVienList[i].phoneNum);
    }
}