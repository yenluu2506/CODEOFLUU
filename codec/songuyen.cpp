#include <stdio.h>
void nhap(int &so1,int &so2);
int tong(int so1, int so2);
int hieu(int so1, int so2);
int giaTriTuyetDoi(int so);
int main (){
	int so1, so2;
	// NOTE: nhap vao 2 so
	nhap(so1,so2);
	printf("2 so: %d %d\n", so1, so2);
	printf("Tong cua 2 so: %d ", tong(so1, so2));
	printf("\nHieu cua 2 so: %d", giaTriTuyetDoi(hieu(so1, so2)));
	return 0;
}
void nhap(int &so1,int &so2){
	printf("Nhap vao 2 so: ");
	scanf("%d%d",&so1,&so2);
}
int tong(int so1, int so2){
	return so1 + so2;
}
int hieu(int so1, int so2){
	return so1 - so2;
}
int giaTriTuyetDoi(int so){
	int ketqua = so;
	if(so<0){
		ketqua = -so;
	}
	return ketqua;
}



