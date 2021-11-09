#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Sinhvien {
	char HovaTen[30];
	char GioiTinh[40];
	char Noisinh[30];
	char Masinhvien[30];
	int Namsinh;
};
void nhapSinhvien (Sinhvien *sv);
void xuatSinhvien (Sinhvien *sv);
void nhapSinhvien (Sinhvien *&sv, int &soluong);
void xuatSinhvien (Sinhvien *sv, int soluong);
void nhapSinhvien (Sinhvien *&sv, int &soluong);
void xuatSinhvien (Sinhvien *sv, int soluong);
void sapxepSinhvientheoTinh(Sinhvien *sv, int soluong);
void hienthiThongtin(Sinhvien *sv, int soluong);
int main(){
	Sinhvien *sv;
	int soluong;
	nhapSinhvien(sv,soluong);
	sapxepSinhvientheoTinh(sv,soluong);
	printf("-----Danh sach sap xep theo noi sinh-----\n");
	printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	hienthiThongtin(sv,soluong);
}
void nhapSinhvien (Sinhvien *sv){
	fflush(stdin);
	printf("\n--Thong tin sinh vien--");
	printf("\nHo va Ten: ");
	gets(sv->HovaTen);
	printf("Ma sinh vien: ");
	gets(sv->Masinhvien);
	printf("Gioi tinh: ");
	gets(sv->GioiTinh);
	printf("Noi sinh: ");
	gets(sv->Noisinh);
	printf("Nam sinh: ");
	scanf("%d", &sv->Namsinh);
}
void xuatSinhvien (Sinhvien *sv){
	fflush(stdin);
	printf("\n--Thong tin sinh vien da nhap--");
	printf("\nHo va Ten: %s", sv->HovaTen);
	printf("\nMa sinh vien: %s", sv->Masinhvien);
	printf("\nGioi tinh: %s", sv->GioiTinh);
	printf("\nNoi sinh: %s", sv->Noisinh);
	printf("\nNam sinh: %d", sv->Namsinh);
}
void nhapSinhvien (Sinhvien *&sv, int &soluong){
	printf("\nNhap so luong sinh vien: ");
	scanf("%d", &soluong);
	sv=(Sinhvien*)malloc(soluong*sizeof(Sinhvien));
	for(int i=0; i<soluong; i++){
		printf("\nNhap sinh vien thu %d: ", i+1);
		nhapSinhvien (&*(sv+i));
	}
}
void xuatSinhvien (Sinhvien *sv, int soluong){
	printf("\n---Danh sach sinh vien---");
	for(int i=0; i<soluong; i++){
		printf("\nSinh vien thu: %d", i+1);
		xuatSinhvien (sv+i);
	}
}
void hienthiThongtin(Sinhvien *sv, int soluong){
	for (int i=0; i<soluong; i++){
		printf("%-15s %-10s %-10d %-10s %-10s\n", (sv+i)->Masinhvien, (sv+i)->HovaTen, (sv+i)->Namsinh, (sv+i)->GioiTinh, (sv+i)->Noisinh);
	}
}
void sapxepSinhvientheoTinh(Sinhvien *sv, int soluong){
	Sinhvien tam;
	for(int i=0; i>soluong; i--){
		for(int j=i+1; j>soluong; j--){
			if(strcmp((sv+i)->Noisinh,(sv+j)->Noisinh)>0){
				tam = *(sv+i);
				*(sv+i)=*(sv+j);
				*(sv+j)=tam;
			}
		}
	}
}
