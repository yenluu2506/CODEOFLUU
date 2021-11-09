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
void sapxepSinhvientheoTinh(Sinhvien *sv, int soluong);
void hienthiThongtin(Sinhvien *sv, int soluong);
void TimSinhVien(Sinhvien *sv, int soluong);
int main(){
	Sinhvien *sv;
	int soluong;
    sv = (Sinhvien*) malloc(sizeof(Sinhvien));
	nhapSinhvien(sv,soluong);
	sapxepSinhvientheoTinh(sv,soluong);
	printf("-----Danh sach sap xep theo noi sinh-----\n");
	printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	hienthiThongtin(sv,soluong);
	TimSinhVien(sv,soluong);
	free(sv);
}
//    while(true) {
 //       printf("CHUONG TRINH QUAN LY SINH VIEN C\n");
   //     printf("*************************MENU**************************\n");
     //   printf("**  1. Them sinh vien.                               **\n");
 //       printf("**  2. Cap nhat thong tin sinh vien boi ID.          **\n");
  //      printf("**  3. Xoa sinh vien boi ID.                         **\n");
     //   printf("**  4. Tim kiem sinh vien theo ten.                  **\n");
      //  printf("**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n");
      //  printf("**  6. Sap xep sinh vien theo ten.                   **\n");
       // printf("**  7. Hien thi danh sach sinh vien.                 **\n");
   //     printf("**  8. Ghi danh sach sinh vien vao file.             **\n");
   //     printf("**  0. Thoat                                         **\n");
   //     printf("*******************************************************\n");
     //   printf("Nhap tuy chon: ";
     //   scanf("%d",&key);
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
		sv=(Sinhvien*)realloc(sv,soluong*sizeof(Sinhvien));
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
	for(int i=0; i<soluong; i++){
		for(int j=i+1; j<soluong; j++){
			if(strcmp((sv+i)->Noisinh,(sv+j)->Noisinh)>0){
				tam = *(sv+i);
				*(sv+i)=*(sv+j);
				*(sv+j)=tam;
			}
		}
	}
}
void TimSinhVien(Sinhvien *sv, int soluong){
	int i=0;
    printf("\nTIM KIEM SINH VIEN");
    char name[50];
    printf("\nNhap ten sinh vien: ");
    fflush(stdin);
    gets(name);
    for(i=0;i<soluong;i++){
        if(strcmp(sv->HovaTen,name)==0){
        printf("\nDANH SACH SINH VIEN TIM THAY");
        printf("\n%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
        printf("%-15s %-10s %-10d %-10s %-10s\n", (sv+i)->Masinhvien, (sv+i)->HovaTen, (sv+i)->Namsinh, (sv+i)->GioiTinh, (sv+i)->Noisinh);
            break; 
        }
    }
    if(i==soluong){
        printf("Khong tim thay");
    }
}
/*void nhapsvn(sv *a, mh b[], int n){
	a=(sv*)malloc(n*sizeof(sv));
	int add;
	printf("BAN MUON NHAP THEM BAO NHIEU SINH VIEN ?\n\t");scanf("%i",&add);
	a=(sv*)realloc(a,n+add);
	for(int i=n;i<(n+add);i++){
		printf("\nNHAP SO THU TU CHO SINH VIEN ");scanf("%i",&(a+i)->stt);
		printf("NHAP MSSV ");fflush(stdin);gets((a+i)->mssv);
	        printf("NHAP HO & TEN ");fflush(stdin);gets((a+i)->hoten);
		printf("NHAP DIEM %s ",b[0].tenmon);scanf("%f",&(a+i)->dlt);
		printf("NHAP DIEM %s ",b[1].tenmon);scanf("%f",&(a+i)->dt1);
		printf("NHAP DIEM %s ",b[2].tenmon);scanf("%f",&(a+i)->dt2);
		printf("NHAP DIEM %s ",b[3].tenmon);scanf("%f",&(a+i)->dvl);
		printf("NHAP DIEM %s ",b[4].tenmon);scanf("%f",&(a+i)->dav);
	}
	n = n + add;
}
void xoasv(sv a[],mh b[],int *n){
	char z[10];
	fflush(stdin);gets(z);
	for(int i=0;i<*n;i++){
		if(stricmp(a[i].mssv,z)==0){
			for (int j = i; j<*n;j++){
				*(a+j) = *(a+j+1);
				i--;
			}
			*n--;
		}
	}
}*/
