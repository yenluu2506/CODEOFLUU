//bai2
#include <stdio.h>
#include <string.h>
int tinhTong(int n);
int tinhTich(int n);
int tinh(int n);
void pass(char matkhau[10]);
int main(){
	int n;
	char matkhau[10];
	printf("Nhap vao n: ");
	scanf("%d", &n);
	printf("Tong cua day so la: %d ", tinhTong(n));
	printf("\nTich cua day so la: %d", tinhTich(n));
	printf("\nTong la: %d", tinh(n));
	pass(matkhau);
	return 0;
}
int tinhTong(int n){
	int S = 0;
	for(int i=2; i<=n; i++){
		S += i;
	}
	return S;
}
int tinhTich(int n){
	int S = 1;
	for(int i=1; i<=n; i++){
		S *= i;
	}
	return S;
}
int tinh(int n){
	int S = 0;
	int i = 4;
	while (i<=n){
		S += i;
		i++;
	}
	return S;
}
void pass(char matkhau[10]){
	printf("\nNhap mat khau: ");
	fflush(stdin);
	gets(matkhau);
	do{
		if(strcmp(matkhau, "12345678")==0){
			printf("\nMat khau chinh xac.");
		}
		else{
			printf("\nMat khau sai.");
			break;
		}
	}while (strcmp(matkhau, "12345678")!=0);
}
