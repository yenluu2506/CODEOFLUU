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
void thongkeSinhvienTheotinh(Sinhvien *sv, int soluong);
void timkiemSinhvienTheotinh(Sinhvien *sv, int soluong);
//void ghiFile(Sinhvien *sv, int soluong);
//void docFile(Sinhvien *sv, int soluong);
int main(){
	Sinhvien *sv;
	int soluong;
	nhapSinhvien(sv,soluong);
	sapxepSinhvientheoTinh(sv,soluong);
	printf("-----Danh sach sap xep theo noi sinh-----\n");
	//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	hienthiThongtin(sv,soluong);
	thongkeSinhvienTheotinh(sv, soluong);
	timkiemSinhvienTheotinh(sv, soluong);
	free(sv); //ham giai phong bo nho da cap phat
//	ghiFile(sv, soluong);
//	docFile(sv, soluong);
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
	//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	for (int i=0; i<soluong; i++){
		printf("%-15s %-10s %-10d %-10s %-10s\n", (sv+i)->Masinhvien, (sv+i)->HovaTen, (sv+i)->Namsinh, (sv+i)->GioiTinh, (sv+i)->Noisinh);
	}
}
void sapxepSinhvientheoTinh(Sinhvien *sv, int soluong){
	Sinhvien tam;
	for(int i=0; i<soluong-1; i++){
		for(int j=i+1; j<soluong; j++){
			if(strcmp((sv+i)->Noisinh,(sv+j)->Noisinh)>0){
				tam = *(sv+i);
				*(sv+i)=*(sv+j);
				*(sv+j)=tam;
			}
		}
	}
}
void thongkeSinhvienTheotinh(Sinhvien *sv, int soluong){
	sapxepSinhvientheoTinh(sv,soluong);
	int dem = 1;
	for(int i=0; i<soluong; i++){
		if(strcmp((sv+i)->Noisinh, (sv+i+1)->Noisinh)==0){
			dem ++;
		}
		else{
			printf("\n%s co %d sinh vien", (sv+i)->Noisinh, dem);
			dem = 1;
		}
	}
}
void  timkiemSinhvienTheotinh(Sinhvien *sv, int soluong){
	char tentinh[20];
	printf("\nNhap ten tinh: ");
	fflush(stdin);
	gets(tentinh);
	int tim=0;
	printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	for(int i=0; i<soluong; i++){
		if(strcmp(tentinh, ((sv+i)->Noisinh))==0){
			//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
			hienthiThongtin(sv+i, 1);
			tim = 1;
			}
	}
	if(tim == 0){
		printf("\nKhong tim thay sinh vien theo tinh %s nhu yeu cau.", tentinh);
	}
}
/*void ghiFile(Sinhvien *sv, int soluong) {
	getchar();
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "wb");
	for(int i = 0; i < soluong; i++) {
		Sinhvien ds = sv[i];
		fprintf(fOut, "%-15s %-10s %-10d %-10s %-10s\n", (sv+i)->Masinhvien, (sv+i)->HovaTen, (sv+i)->Namsinh, (sv+i)->GioiTinh, (sv+i)->Noisinh);
	}
	fclose(fOut);
}

void docFile(Sinhvien *sv, int *soluong) {
	FILE* fOut = fopen("sinhvien.dat", "rb");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct Sinhvien sv;
			fscanf(fOut, "%-15s %-10s %-10d %-10s %-10s\n", (sv+i)->Masinhvien, (sv+i)->HovaTen, (sv+i)->Namsinh, (sv+i)->GioiTinh, (sv+i)->Noisinh);
			sv[i++] = ds;
			if(feof(fOut)) {
				break;
			}
		}
	}
	
	fclose(fOut);
	*soluong = i;
}*/
int xoaTheoID() {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa SV co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
        return 0;
    } else {
        return 1;
    }
}
