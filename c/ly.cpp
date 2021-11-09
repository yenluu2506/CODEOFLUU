#include<stdio.h>
#include<stdlib.h>
struct Sinhvien {
	char HovaTen[30];
	char GioiTinh[40];
	char Noisinh[30];
	char Masinhvien[30];
	int Namsinh;
};
void nhapSinhvien (Sinhvien *sv);
void xuatSinhvien (Sinhvien *sv);
void nhapSinhvien (Sinhvien *danhsach, int &soluong);
void xuatSinhvien (Sinhvien *danhsach, int &soluong);
int main(){
	Sinhvien *sv;
	Sinhvien *danhsach;
	int soluong;
	sv = (Sinhvien*) malloc(sizeof(Sinhvien));
	nhapSinhvien(danhsach,soluong);
	xuatSinhvien(danhsach,soluong);
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

void Menu(){
	int chon, flat=1;
	while(flat){
		printf("1. Nhap du lieu cua tung sinh vien.\n");
		printf("2. Xap sepn thong ke va hien thi thong tin chi tiet cua tung sinh vien theo tinh.\n");
		printf("3. tim sinh vien theo tinh.\n");
		printf("4. ghi vao tap tin nhi phan employee.dat.\n");
		printf("5. Thoat.\n");
		printf("Moi ban chon chuc nang: ");
		scanf("%d", &chon);
		switch(chon){
			case 1: 
				struct sinh vien a[100];
				int n;
				printf ("Nhap n: ");
				scanf ("%d", &n);
				NhapDS(a,n);
				break;
			case 2:
				printf("\nThong tin sinh vien da nhap vao la: \n");
				XuatDS(a,n);
				break;
			case 3:
				printf("nhap tinh",sinh vien(a,n));
				break;
			case 4:
				taptinnhiphan(a,n);
				break;
			case 5:
				flat=0;		
		}
	}
