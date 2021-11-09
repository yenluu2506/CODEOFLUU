//bai 1
#include <stdio.h>
#define MAX_SIZE 100
struct Sinhvien {
	char hoten[40];
	char masinhvien[10];
	int namsinh;
	float diem;
};
void nhap(Sinhvien &sinhvien);
void xuat(Sinhvien sinhvien);
void nhap(Sinhvien danhsach[], int &soluong);
void xuat(Sinhvien danhsach[], int soluong);
Sinhvien timSinhvienDiemcaoNhat(Sinhvien danhsach[],int soluong);
Sinhvien timSinhvienDiemthapnhat(Sinhvien danhsach[], int soluong);
int main(){
	Sinhvien danhsach[MAX_SIZE];
	Sinhvien sinhviendiemcaonhat;
	Sinhvien sinhviendiemthapnhat;
	int soluong;
	nhap(danhsach, soluong);
	xuat(danhsach, soluong);
	sinhviendiemcaonhat = timSinhvienDiemcaoNhat(danhsach, soluong);
	printf("\n");
	printf("\nSinh vien diem cao nhat la: ");
	xuat(sinhviendiemcaonhat);
	sinhviendiemthapnhat = timSinhvienDiemthapnhat(danhsach, soluong);
	printf("\n");
	printf("\nSinh vien diem thap nhat la: ");
	xuat(sinhviendiemthapnhat);
}
void nhap(Sinhvien &sinhvien){
	fflush(stdin);
	printf("Ho va ten: ");
	gets(sinhvien.hoten);
	printf("Ma sinh vien: ");
	gets(sinhvien.masinhvien);
	printf("Nam sinh: ");
	scanf("%d", &sinhvien.namsinh);
	printf("Nhap diem trung binh: ");
	scanf("%f", &sinhvien.diem);
}
void xuat(Sinhvien sinhvien){
	printf("\nHo va ten: %s ", sinhvien.hoten);
	printf("\nMa sinh vien: %s ", sinhvien.masinhvien);
	printf("\nNam sinh: %d ", sinhvien.namsinh);
	printf("\nDiem trung binh: %.2f ", sinhvien.diem);
}
void nhap(Sinhvien danhsach[], int &soluong){
	printf("\nSoluong: ");
	scanf("%d", &soluong);
	for(int vitri=0; vitri<soluong; vitri++){
		nhap(danhsach[vitri]);
	}
}
void xuat(Sinhvien danhsach[], int soluong){
	for(int vitri=0; vitri<soluong; vitri++){
		xuat(danhsach[vitri]);
	}
}
Sinhvien timSinhvienDiemcaoNhat(Sinhvien danhsach[], int soluong){
	Sinhvien ketqua;
	int diemcaonhat;
	for(int vitri=0; vitri<soluong; vitri++){
		if(danhsach[vitri].diem>diemcaonhat){
			diemcaonhat = danhsach[vitri].diem;
			ketqua = danhsach[vitri];
		}
	}
	return ketqua;
}
Sinhvien timSinhvienDiemthapnhat(Sinhvien danhsach[], int soluong){
	Sinhvien Ketqua;
	int diemthapnhat;
	for(int vitri=0; vitri<soluong; vitri++){
		if(danhsach[vitri].diem<diemthapnhat){
			diemthapnhat = danhsach[vitri].diem;
			//Ketqua = danhsach[vitri];
		}
		Ketqua = danhsach[vitri];
	}
}
