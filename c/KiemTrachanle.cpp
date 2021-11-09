#include<stdio.h>
void nhap1so(int &a);
void xuat1so(int a);
void kiemtraChanle(int a);
void nhapDiem();
void menu();
int main(){
	int a;
	nhap1so(a);
	xuat1so(a);
	kiemtraChanle(a);
	nhapDiem();
	menu();
}
void nhap1so(int &a){
	printf("Nhap vao so a: ");
	scanf("%d", &a);
}
void xuat1so(int a){
	printf("\nSo da nhap la: ");
	printf("%d", a);
}
void kiemtraChanle(int a){
	if(a%2==0){
		printf("\na la so chan.");
	}
	else{
		printf("\na la so le.");
	}
}
void nhapDiem(){
	float triet;
	float gt1; 
	float thdc;
	float dstt;
	float dtb;
	printf("\nNhap vao diem triet: ");
	scanf("%f", &triet);
	printf("\nNhap vao diem giai tich 1: ");
	scanf("%f", &gt1);
	printf("\nNhap vao diem tin hoc dai cuong: ");
	scanf("%f", &thdc);
	printf("\nNhap vao diem dstt: ");
	scanf("%f", &dstt);
	dtb = (triet+gt1+thdc+dstt)/4;
	printf("\nDiem trung binh la: %.2f", dtb);
	if(dtb>9){
		printf("\nXuat Sac");
	}
	else if(dtb>8 && dtb<9){
		printf("\nGioi");
	}
	else if(dtb>6.5 && dtb<8){
		printf("\nKha");
	}
	else if(dtb>4 && dtb<6.5){
		printf("\nTrung Binh");
	}
	else{
		printf("\nYeu");
	}
}
void menu(){
	int chon;
	printf("\n----Menu----");
	printf("\n1. Com ga");
	printf("\n2. Lau bo");
	printf("\n3. Bun");
	printf("\n4. Banh xeo");
	printf("\n5. Thoat");
	printf("\n");
	printf("\nMoi ban lua chon: ");
	scanf("%d", &chon);
	switch(chon){
		case 1:{
			printf("1. Ban da chon com ga");
			break;
		}
		case 2: {
			printf("2. Ban da chon lau bo");
			break;
		}
		case 3: {
			printf("3. Ban da chon bun");
			break;
		}
		case 4: {
			printf("4. Ban da chon banh xeo");
			break;
		}
		case 5: {
			break;
		}
	}
}
