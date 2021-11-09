#include <stdio.h>
#include <string.h>
struct Book{
	char TenSach[50];
	char TacGia[50];
	int NamXuatBan;
};
void Nhap(Book &a){
	fflush(stdin);
	printf("Nhap ten sach: ");
	gets(a.TenSach);
	printf("Nhap ten tac gia: ");
	gets(a.TacGia);
	printf("Nhap nam xuat ban: ");
	scanf("%d", &a.NamXuatBan);
}
void Xuat(Book a){
	printf("Ten sach: %s\n", a.TenSach);
	printf("Tac gia: %s\n", a.TacGia);
	printf("Nam xuat ban: %d\n", a.NamXuatBan);
}
void NhapSach(Book a[], int n){
	for(int i=1; i<=n; i++){
		printf("Nhap thong tin sach %d: \n", i);
		Nhap(a[i]);
	}
}
void XuatSach(Book a[], int n){
	for(int i=1; i<=n; i++){
		printf("Thong tin sach %d la: \n", i);
		Xuat(a[i]);
	}
}
int DemSoSach(Book a[], int n){
	int dem=0;
	char ten[50];
	fflush(stdin);
	printf("\nNhap ten tac gia can tim: ");
	gets(ten);
	for(int i=1; i<=n; i++){
		if(strcmp(ten, a[i].TacGia)==0)
			dem++;
	}
	return dem;
}
void menu(){
	printf("\n0.thoat");
	printf("\n1.nhap vao mot day n cuon sach");
	printf("\n2. Xuat ra man hinh thong tin cua cuon sach");
	printf("\n3. Nhap vao ten mot cuon sach dem xem tac gia co bao nhieu cuon");
	printf("\n4. Thong ke nam xuat ban");	
}
int main(){
	struct Book a[100];
	int n, chon, k, h, d, i;
	do{
		printf("Nhap so sach: ");
		scanf("%d", &n);
	}while(n<=0 || n>100);
	NhapSach(a, n);
	XuatSach(a, n);
	printf("\nSo sach co cung tac gia la: %d\n", DemSoSach(a, n));
	menu();
	printf("\nMoi ban chon: ");
	scanf("%d", &chon);
	switch (chon){
		case 0: 
			break;
		case 1: {
			k = Nhap();
			i=1;
			break;
		}
		case 2: {
			h = Xuat();
			i=2;
			break;
		}
		case 3: {
			d = DemSoSach();
			i = 3;
			break;
		}
	default: menu()
	}
}
