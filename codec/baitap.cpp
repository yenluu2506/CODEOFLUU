#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Sinhvien {
    char masinhvien[30];
	char hoten[30];
	char gioitinh[40];
	char noisinh[30];
	int namsinh;
};
void nhap (Sinhvien *sinhvien); // NOTE: doc 1 sinh vien
void xuat (Sinhvien *sinhvien);// NOTE: xuat 1 sinh vien
void nhap (Sinhvien *&danhsach, int &soluong); // NOTE: nhap 1 danh sach nhan vien
void xuat (Sinhvien *danhsach, int soluong);
void sapXepTheoTinh(Sinhvien *danhsach, int soluong);
void hienthiThongtin(Sinhvien *danhsach, int soluong);
void thongKeTheoTinh(Sinhvien *danhsach, int soluong);
void timKiemTheoTinh(Sinhvien *danhsach, int soluong);
void ghiFile(Sinhvien *danhsach, int soluong);
//void docFile(Sinhvien *danhsach, int soluong);
void menu(Sinhvien *danhsach, int soluong);
//void pressAnyKey();
int main(){
	Sinhvien *danhsach;
	int soluong;
//	nhap(danhsach,soluong);
////	xuat(danhsach,soluong);
//	sapXepTheoTinh(danhsach,soluong);
//	printf("-----Danh sach sap xep theo noi sinh-----\n");
	//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
//	hienthiThongtin(danhsach,soluong);
//	thongKeTheoTinh(danhsach, soluong);
//	timKiemTheoTinh(danhsach, soluong);
//	free(danhsach); //ham giai phong bo nho da cap phat
//	ghiFile(danhsach, soluong);
//	docFile(danhsach, soluong);
	menu(danhsach,soluong);
}
void nhap (Sinhvien *sinhvien){
	fflush(stdin);
	printf("\n--Thong tin sinh vien--");
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
}
void xuat (Sinhvien *sinhvien){
	fflush(stdin);
	printf("\n--Thong tin sinh vien da nhap--");
	printf("\nHo va Ten: %s", sinhvien->hoten);
	printf("\nMa sinh vien: %s", sinhvien->masinhvien);
	printf("\nGioi tinh: %s", sinhvien->gioitinh);
	printf("\nNoi sinh: %s", sinhvien->noisinh);
	printf("\nNam sinh: %d", sinhvien->namsinh);
}
void nhap (Sinhvien *&danhsach, int &soluong){
	printf("\nNhap so luong sinh vien: ");
	scanf("%d", &soluong);
	danhsach=(Sinhvien*)malloc(soluong*sizeof(Sinhvien));
	for(int i=0; i<soluong; i++){
		printf("\nNhap sinh vien thu %d: ", i+1);
		nhap (&*(danhsach+i));
	}
}
void xuat (Sinhvien *danhsach, int soluong){
	printf("\n---Danh sach sinh vien---");
	for(int i=0; i<soluong; i++){
		printf("\nSinh vien thu: %d", i+1);
		xuat (danhsach+i);
	}
}
void hienthiThongtin(Sinhvien *danhsach, int soluong){
	//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	for (int i=0; i<soluong; i++){
		printf("%-15s %-10s %-10d %-10s %-10s\n", (danhsach+i)->masinhvien, (danhsach+i)->hoten, (danhsach+i)->namsinh, (danhsach+i)->gioitinh, (danhsach+i)->noisinh);
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
void  timKiemTheoTinh(Sinhvien *danhsach, int soluong){
	char tentinh[20];
	printf("\nNhap ten tinh: ");
	fflush(stdin);
	gets(tentinh);
	int tim=0;
	printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	for(int i=0; i<soluong; i++){
		if(strcmp(tentinh, ((danhsach+i)->noisinh))==0){
			//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
			hienthiThongtin(danhsach+i, 1);
			tim = 1;
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
	printf("Nhap ten file: ");
	gets(fName);
    strcat(fPath,fName);
    printf("%s",fPath);
	FILE* fOut = fopen(fPath, "wb");
	for(int i = 0; i < soluong; i++) {
		fprintf(fOut, "%-15s %-10s %-10d %-10s %-10s\n", (danhsach+i)->masinhvien, (danhsach+i)->hoten, (danhsach+i)->namsinh, (danhsach+i)->gioitinh, (danhsach+i)->noisinh);
	}
	fclose(fOut);
}
/*
void docFile(Sinhvien *sinhvien, int *soluong) {
	FILE* fOut = fopen("sinhvien.dat", "rb");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct Sinhvien sinhvien;
			fscanf(fOut, "%-15s %-10s %-10d %-10s %-10s\n", (danhsach+i)->masinhvien, (danhsach+i)->hoten, (danhsach+i)->namsinh, (danhsach+i)->gioitinh, (danhsach+i)->noisinh);
			sinhvien[i++] = ds;
			if(feof(fOut)) {
				break;
			}
		}
	}
	
	fclose(fOut);
	*soluong = i;
}*/
//void pressAnyKey() {
//    printf("\n\nBam phim bat ky de tiep tuc...");
//    //gets();
//    system("cls");
//}
void menu(Sinhvien *danhsach, int soluong){
	int chon, flat = 1;
	while(flat){
		printf("1. Nhap du lieu cua tung sinh vien.\n");
		printf("2. Xuat du lieu cua tung sinh vien.\n");
		printf("3. Xap sep thong ke va hien thi thong tin chi tiet cua tung sinh vien theo tinh.\n");
		printf("4. Tim sinh vien theo tinh.\n");
		printf("5. Ghi vao tap tin nhi phan.\n");
		printf("6. Thoat.\n");
		printf("Moi ban chon chuc nang: ");
		scanf("%d", &chon);
		switch(chon){
			case 1: {
				//Sinhvien *danhsach;
				//int soluong;
				nhap(danhsach,soluong);
				//pressAnyKey();
				break;
			}
			case 2: {
				//Sinhvien *danhsach;
				xuat(danhsach,soluong);
				//pressAnyKey();
				break;
			}
			case 3: {
				//Sinhvien *danhsach;
				sapXepTheoTinh(danhsach,soluong);
				printf("-----Danh sach sap xep theo noi sinh-----\n");
				//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
				hienthiThongtin(danhsach,soluong);
				thongKeTheoTinh(danhsach, soluong);
				//pressAnyKey();
				break;
			}
			case 4: {
				//Sinhvien *danhsach;
				timKiemTheoTinh(danhsach, soluong);
				free(danhsach);
				//pressAnyKey();
				break;
			}
			case 5: {
				ghiFile(danhsach, soluong);
				//pressAnyKey();
				break;
			}
			case 6: {
				printf("\nBan da thoat khoi chuong trinh.\n");
				flat = 0;
			}
			default: 
				printf("\nKhong co chuc nang nay.");
				printf("\nHay chon chuc nang trong menu.");
		}
	}
}
