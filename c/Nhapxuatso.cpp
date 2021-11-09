// bai 4

#include <stdio.h>

void Nhap1so(){
	int a;
	printf("Nhap vao gia tri a: ");
	scanf("%d", &a);
}
void Xuat1so(){
	int a;
	printf("So da nhap la: %d ", a);
}
void Nhap2so(){
	int b, c;
	printf("\nNhap vao gia tri b va c: ");
	scanf("%d %d", &b, &c);
}
void Xuat2so(){
	int b,c ;
	printf("So da nhap la: %d %d", b, c);
}
void Nhapmang1chieu(int A[], int n){
	for (int i=0; i<n; i++){
		printf("a[%d]: ", i);
		scanf("%d", &A[i]);
	}
}
void Xuatmang1chieu(int A[], int n){
	for(int i=0; i<n; i++){
		printf("%5d", A[i]);
	}
}
void Tinh2so(){
	int b, c;
	int tong = 0;
	int hieu = 0;
	tong = b+c;
	printf("\nTong cua 2 so la: %d ", tong);
	if(b>c){
		hieu = b-c;
	}else;
	printf("\nHieu cua 2 so la: %d", hieu);
}

int main(){
	int A[100], n;
	Nhap1so();
	Xuat1so();
	Nhap2so();
	Xuat2so();
	printf("\nNhap vao so phan tu n: ");
	scanf("%d", &n);
	Nhapmang1chieu(A,n);
	//printf("Mang 1 chieu da nhap la: ");
	Xuatmang1chieu(A,n);
	Tinh2so();
}
