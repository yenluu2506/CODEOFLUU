#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
struct Sinhvien {
	char HovaTen[30];
	char GioiTinh[40];
	char Noisinh[30];
	char Masinhvien[30];
	int Namsinh;
	int Sohopdong;
	char Phinoitru[50];
};
void nhap(Sinhvien *sinhvien);
void xuap(Sinhvien *sinhvien);
void nhap(Sinhvien *&danhsach, int &soluong);
void xuat(Sinhvien *danhsach, int soluong);
void sapXepTheoTinh(Sinhvien *danhsach, int soluong);
void hienthiThongtin(Sinhvien *danhsach, int soluong);
void thongKeTheoTinh(Sinhvien *danhsach, int soluong);
void timKiemTheoTinh(Sinhvien *danhsach, int soluong);
void ghiFile(Sinhvien *danhsach, int soluong);
//void docFile(Sinhvien *danhsach, int soluong);
void menu(Sinhvien *danhsach, int soluong);
int main(){
	Sinhvien *danhsach;
	int soluong;
	menu(danhsach,soluong);
	free(danhsach);
//	nhap(danhsach,soluong);
//	sapXepTheoTinh(danhsach,soluong);
//	printf("-----Danh sach sap xep theo noi sinh-----\n");
//	//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
//	hienthiThongtin(danhsach,soluong);
//	thongKeTheoTinh(danhsach, soluong);
//	timKiemTheoTinh(danhsach, soluong);
//	free(danhsach); //ham giai phong bo nho da cap phat
//	ghiFile(danhsach, soluong);
////	docFile(danhsach, soluong);
}
void nhap(Sinhvien *sinhvien){
	fflush(stdin);
	printf("\n--Thong tin sinh vien--");
	printf("\nHo va Ten: ");
	gets(sinhvien->HovaTen);
	printf("Ma sinh vien: ");
	gets(sinhvien->Masinhvien);
	printf("Gioi tinh: ");
	gets(sinhvien->GioiTinh);
	printf("Noi sinh: ");
	gets(sinhvien->Noisinh);
	printf("Nam sinh: ");
	scanf("%d", &sinhvien->Namsinh);
	printf("So hop dong: ");
	scanf("%d", &sinhvien->Sohopdong);
	printf("Phi noi tru: ");
	gets(sinhvien->Phinoitru);
}
void xuat(Sinhvien *sinhvien){
	fflush(stdin);
	printf("\n--Thong tin sinh vien da nhap--");
	printf("\nHo va Ten: %s", sinhvien->HovaTen);
	printf("\nMa sinh vien: %s", sinhvien->Masinhvien);
	printf("\nGioi tinh: %s", sinhvien->GioiTinh);
	printf("\nNoi sinh: %s", sinhvien->Noisinh);
	printf("\nNam sinh: %d", sinhvien->Namsinh);
	printf("\nSo hop dong: %d", sinhvien->Sohopdong);
	printf("\nPhi noi tru: %s", sinhvien->Phinoitru);
}
void nhap(Sinhvien *&danhsach, int &soluong){
	printf("\nNhap so luong sinh vien: ");
	scanf("%d", &soluong);
	danhsach=(Sinhvien*)malloc(soluong*sizeof(Sinhvien));
	for(int i=0; i<soluong; i++){
		printf("\nNhap sinh vien thu %d: ", i+1);
		nhap(&*(danhsach+i));
	}
}
void xuat(Sinhvien *danhsach, int soluong){
	printf("\n---Danh sach sinh vien---");
	for(int i=0; i<soluong; i++){
		printf("\nSinh vien thu: %d", i+1);
		xuat(danhsach+i);
	}
}
void hienthiThongtin(Sinhvien *danhsach, int soluong){
	//printf("%-15s %-10s %-10s %-10s %-10s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh");
	for (int i=0; i<soluong; i++){
		printf("%-15s %-15s %-15d %-15s %-15s %-15d %-15s\n", (danhsach+i)->Masinhvien, (danhsach+i)->HovaTen, (danhsach+i)->Namsinh, (danhsach+i)->GioiTinh, (danhsach+i)->Noisinh, (danhsach+i)->Sohopdong, (danhsach+i)->Phinoitru);
	}
}
void sapXepTheoTinh(Sinhvien *danhsach, int soluong){
	Sinhvien tam;
	for(int i=0; i<soluong-1; i++){
		for(int j=i+1; j<soluong; j++){
			if(strcmp((danhsach+i)->Noisinh,(danhsach+j)->Noisinh)>0){
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
		if(strcmp((danhsach+i)->Noisinh, (danhsach+i+1)->Noisinh)==0){
			dem ++;
		}
		else{
			printf("\n%s co %d sinh vien", (danhsach+i)->Noisinh, dem);
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
	printf("%-15s %-15s %-15s %-15s %-15s %-15d %-15s\n", "Ma sinh vien", "Ho va Ten", "Nam sinh", "Gioi tinh", "Noi sinh", "So hop dong", "Phi noi tru");
	for(int i=0; i<soluong; i++){
		if(strcmp(tentinh, ((danhsach+i)->Noisinh))==0){
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
	printf("\nNhap ten file: ");
	gets(fName);
	printf("\n");
    strcat(fPath,fName);
    printf("%s",fPath);
	FILE* fOut = fopen(fPath, "wb");
	for(int i = 0; i < soluong; i++) {
		fprintf(fOut, "%-15s %-15s %-15d %-15s %-15s %-15d %-15s\n", (danhsach+i)->Masinhvien, (danhsach+i)->HovaTen, (danhsach+i)->Namsinh, (danhsach+i)->GioiTinh, (danhsach+i)->Noisinh, (danhsach+i)->Sohopdong, (danhsach+i)->Phinoitru);
	}
	fclose(fOut);
}
/*
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
void menu(Sinhvien *danhsach, int soluong){
    int key;
//    int n;
    int flat = 1;
    bool daNhap = false;
    do{
        printf("\nNhap so luong Sinh Vien: ");
		scanf("%d", &soluong);
    }while(soluong <= 0);
    while(true){
        system("cls");
        printf("*********************************************************************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN KTX                                                   **\n");
        printf("**      1. Nhap du lieu                                                                    **\n");
        printf("**      2. In danh sach sinh vien                                                          **\n");
        printf("**      3. Sap sep thong ke va hien thi thong tin chi tiet cua tung sinh vien theo tinh.   **\n");
        printf("**      4. Tim sinh vien theo tinh.                                                        **\n");
        printf("**      5. Ghi vao tap tin nhi phan                                                        **\n");
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
                printf("\nBam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuat(danhsach,soluong);
                }else{
                    printf("\nNhap danh sach Sinh Vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap sep thong ke va hien thi thong tin chi tiet cua tung sinh vien theo tinh.\n");
                    printf("\n");
                    sapXepTheoTinh(danhsach,soluong);
                    hienthiThongtin(danhsach,soluong);
                    thongKeTheoTinh(danhsach, soluong);
                }else{
                    printf("\nNhap danh sach Sinh Vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon tim sinh vien theo tinh.");
                    timKiemTheoTinh(danhsach, soluong);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon ghi vao tap tin nhi phan");
                    ghiFile(danhsach, soluong);
                }else{
                    printf("\nNhap danh sach Sinh Vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                false;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                printf("\n");
                getch();
                break;
        }
    }
}
