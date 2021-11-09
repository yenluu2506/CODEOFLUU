#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
struct Sinhvien {
    char masinhvien[30];
	char hoten[30];
	char gioitinh[40];
	char noisinh[30];
	int sohopdong;
	int namsinh;
};
void nhap (Sinhvien *sinhvien);
void xuat (Sinhvien *sinhvien);
void nhap (Sinhvien *&danhsach, int &soluong);
void xuat (Sinhvien *danhsach, int soluong);
void sapXepTheoTinh(Sinhvien *danhsach, int soluong);
void hienthiThongtin(Sinhvien *danhsach, int soluong);
void thongKeTheoTinh(Sinhvien *danhsach, int soluong);
void timKiemTheoTinh(Sinhvien *danhsach, int soluong);
void sapXepTheoTen(Sinhvien *danhsach, int soluong);
int xoaTheoMSV(Sinhvien *danhsach, int soluong, int id);
void ghiFile(Sinhvien *danhsach, int soluong);
void menu(Sinhvien *danhsach, int soluong);
void SetColor(WORD color);
void pressAnyKey();
int main(){
	Sinhvien *danhsach;
	int soluong;
	system("color 73");
    SetColor(74);
	menu(danhsach,soluong);
	free(danhsach);
}
void SetColor(WORD color){ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void nhap (Sinhvien *sinhvien){
	fflush(stdin);
	printf("\n--Thong tin sinh vien--");
	printf("\n");
	printf("\nHo va Ten: ");
	gets(sinhvien->hoten);
	printf("Ma sinh vien: ");
	gets(sinhvien->masinhvien);
	printf("Gioi tinh: ");
	gets(sinhvien->gioitinh);
	printf("Noi sinh: ");
	gets(sinhvien->noisinh);
	printf("Nam sinh: ");
	scanf("%d", &sinhvien->namsinh);
	printf("So hop dong: ");
	scanf("%d", &sinhvien->sohopdong);
}
void xuat (Sinhvien *sinhvien){
	fflush(stdin);
	printf("\n--Thong tin sinh vien da nhap--");
	printf("\n");
	printf("\nHo va Ten: %s", sinhvien->hoten);
	printf("\nMa sinh vien: %s", sinhvien->masinhvien);
	printf("\nGioi tinh: %s", sinhvien->gioitinh);
	printf("\nNoi sinh: %s", sinhvien->noisinh);
	printf("\nNam sinh: %d", sinhvien->namsinh);
	printf("\nSo hop dong: %d", sinhvien->sohopdong);
}
void nhap (Sinhvien *&danhsach, int &soluong){
	danhsach=(Sinhvien*)malloc(soluong*sizeof(Sinhvien));
	for(int i=0; i<soluong; i++){
		printf("\nNhap sinh vien thu %d: \n", i+1);
		nhap (&*(danhsach+i));
	}
}
void xuat (Sinhvien *danhsach, int soluong){
	printf("\n---Danh sach sinh vien---");
	printf("\n");
	for(int i=0; i<soluong; i++){
		printf("\nSinh vien thu: %d", i+1);
		xuat (danhsach+i);
	}
}
void hienthiThongtin(Sinhvien *danhsach, int soluong){
	for (int i=0; i<soluong; i++){
		printf("\n%-15s %-15s %-15d %-15s %-15s %-15d\n",(danhsach+i)->masinhvien, (danhsach+i)->hoten, (danhsach+i)->namsinh, (danhsach+i)->gioitinh, (danhsach+i)->noisinh, (danhsach+i)->sohopdong);
	}
}
void sapXepTheoTinh(Sinhvien *danhsach, int soluong){
	Sinhvien tam;
	for(int i=0; i<soluong-1; i++){
		for(int j=i+1; j<soluong; j++){
			if(strcmp((danhsach+i)->noisinh,(danhsach+j)->noisinh)>0){
				tam = *(danhsach+i);
				*(danhsach+i)=*(danhsach+j);
				*(danhsach+j)=tam;
			}
		}
	}
}
void thongKeTheoTinh(Sinhvien *danhsach, int soluong){
	sapXepTheoTinh(danhsach,soluong);
	int dem = 1;
	for(int i=0; i<soluong; i++){
		if(strcmp((danhsach+i)->noisinh, (danhsach+i+1)->noisinh)==0){
			dem ++;
		}
		else{
			printf("\n%s co %d sinh vien", (danhsach+i)->noisinh, dem);
			dem = 1;
		}
	}
}
void timKiemTheoTinh(Sinhvien *danhsach, int soluong){
	char tentinh[20];
	printf("\nNhap ten tinh: ");
	fflush(stdin);
	gets(tentinh);
	int tim=0;	
	for(int i=0; i<soluong; i++){
		if(strcmp(tentinh, ((danhsach+i)->noisinh))==0){
			tim++;
			if(tim == 1){
				printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh", "So hop dong");
			}
			hienthiThongtin(danhsach+i, 1);
		}
	}
	if(tim == 0){
		printf("\nKhong tim thay sinh vien theo tinh %s nhu yeu cau.", tentinh);
	}
}
void ghiFile(Sinhvien *danhsach, int soluong) {
	getchar();
	char fName[26];
    char fPath[100]="./src/data/";
	printf("\nNhap ten file: ");
	gets(fName);
	printf("\n");
    strcat(fPath,fName);
    printf("%s",fPath);
	FILE* fOut = fopen(fPath, "wb");
	for(int i = 0; i < soluong; i++) {
		fprintf(fOut, "%-15s %-10s %-10d %-10s %-10s %-10d\n", (danhsach+i)->masinhvien, (danhsach+i)->hoten, (danhsach+i)->namsinh, (danhsach+i)->gioitinh, (danhsach+i)->noisinh, (danhsach+i)->sohopdong);
	}
	fclose(fOut);
}
void pressAnyKey() {
    printf("\n\nBam phim bat ky de tiep tuc...");
    getch();
    system("cls");
}
void menu(Sinhvien *danhsach, int soluong){
    int key;
    int flat = 1;
    bool daNhap = false;
    do{
        printf("\nNhap so luong Sinh Vien: ");
		scanf("%d", &soluong);
    }while(soluong <= 0);
    while(flat){
        system("cls");
        printf("*********************************************************************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN KTX                                                   **\n");
        printf("**      1. Nhap du lieu                                                                    **\n");
        printf("**      2. In danh sach sinh vien                                                          **\n");
        printf("**      3. Sap sep thong ke va hien thi thong tin chi tiet cua tung sinh vien theo tinh.   **\n");
        printf("**      4. Sap xep hien thi thong tin sinh vien theo ten.                                  **\n");
        printf("**      5. Tim sinh vien theo tinh.                                                        **\n");
        printf("**      6. Xoa sinh vien.                                                                  **\n");
        printf("**      7. Ghi vao tap tin nhi phan                                                        **\n");
        printf("**      0. Thoat                                                                           **\n");
        printf("*********************************************************************************************\n");
        printf("**       Nhap lua chon cua ban                                                             **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap danh sach Sinh Vien!");
                printf("\n");
                nhap(danhsach,soluong);
                printf("\nBan da nhap thanh cong!");
                printf("\n");
                daNhap = true;
                pressAnyKey();
				break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuat(danhsach,soluong);
                }else{
                    printf("\nNhap danh sach Sinh Vien truoc!!!!");
                }
                pressAnyKey();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap sep thong ke va hien thi thong tin chi tiet cua tung sinh vien theo tinh.\n");
                    printf("\n");
                    printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh", "So hop dong");
                    sapXepTheoTinh(danhsach,soluong);
                    hienthiThongtin(danhsach,soluong);
                    thongKeTheoTinh(danhsach, soluong);
                }else{
                    printf("\nNhap danh sach Sinh Vien truoc!!!!");
                }
                pressAnyKey();
                break;
            case 4:
            	if(daNhap){
                    printf("\nBan da chon sap xep theo ten!");
                    printf("\n");
                    printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh", "So hop dong");
                    sapXepTheoTen(danhsach,soluong);
                    hienthiThongtin(danhsach,soluong);
                    
                }else{
                    printf("\nNhap danh sach Sinh Vien truoc!!!!");
                }
                pressAnyKey();
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon tim sinh vien theo tinh.");
                    timKiemTheoTinh(danhsach, soluong);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                pressAnyKey();
                break;
            case 6:
            	if(daNhap){
                    printf("\nBan da chon xoa sinh vien!");
                    printf("\n");
					char id[30];
					int soluong;
                    if (xoaTheoMSV(danhsach,soluong, id) == 1) {
                        printf("\nSinh vien co MSV = %d da bi xoa.", &id);
                        soluong--;
                    }
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                pressAnyKey();
                break;
            case 7:
                if(daNhap){
                    printf("\nBan da chon ghi vao tap tin nhi phan");
                    ghiFile(danhsach, soluong);
                }else{
                    printf("\nNhap danh sach Sinh Vien truoc!!!!");
                }
                pressAnyKey();
                break;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                flat =0;
                false;
        }
    }
}
void sapXepTheoTen(Sinhvien *danhsach, int soluong){
	Sinhvien tam;
	for(int i=0; i<soluong-1; i++){
		for(int j=i+1; j<soluong; j++){
			if(strcmp((danhsach+i)->hoten,(danhsach+j)->hoten)>0){
				tam = *(danhsach+i);
				*(danhsach+i)=*(danhsach+j);
				*(danhsach+j)=tam;
			}
		}
	}
}
//void xoa(Sinhvien *danhsach, int &soluong){
//	int k;
// 	for (int i=k;i<soluong-1;i++){
//		(danhsach+i)==(danhsach+i+1);
//    	soluong--;
//	}
//}
//void xoaSinhvien(Sinhvien *danhsach, int soluong){
//	char masinhvien[17];
//	int k;
//   	printf("Nhap Ma so Sinh Vien can xoa: ");
//   	scanf("%s", &masinhvien);
//   	for(int i=0;i<soluong;i++)
////    if (strcmp(masinhvien,(danhsach+i)->masinhvien)==0){
////        xoa(danhsach,soluong);
////        break;
////        }
//	(danhsach+k)==(danhsach+k+1);
//    	soluong--;
//    hienthiThongtin(danhsach, soluong);
//}

int xoaTheoMSV(Sinhvien *danhsach, int soluong, char id[30]) {
    int found = 0;
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%d", &id);
    for(int i = 0; i < soluong; i++) {
        if ((strcmp(danhsach)->masinhvien, id)=0){
            found = 1;
            for (int j = i; j < soluong; j++) {
                (danhsach+j) == (danhsach+j+1);
            }
            printf("\n Da xoa SV co MSV = ", id);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co MSV = %s khong ton tai.", id);
    }
}
