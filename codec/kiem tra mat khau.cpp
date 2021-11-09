#include<stdio.h>
#include<string.h>
void nhapDayso(int &n);
void lietkeChanLe(int n);
void datPass(char matkhau[10]);
int main(){
	int n;
	char matkhau[10];
	nhapDayso(n);
	lietkeChanLe(n);
	datPass(matkhau);
}
void nhapDayso(int &n){
	printf("Nhap n: ");
	scanf("%d", &n);
	if(n>0){
		printf("\nDay so vua nhap la: ");
		for(int i=1; i<=n; i++){
			printf("%5d ", i);
		}
	}
	else {
		printf("\nVui long nhap lai n: ");
	}
}
void lietkeChanLe(int n){
	printf("\nDay so chan la: ");
	for(int i=0; i<=n; i+=2){
		printf("%5d", i);
	}
	printf("\nDay so le la: ");
	for(int i=1; i<=n; i+=2){
		printf("%5d", i);
	}
}
void datPass(char matkhau[10]){
	printf("\nNhap mat khau: ");
	fflush(stdin);
	gets(matkhau);
	do{
		if(strcmp(matkhau , "123456789")!=0){
			printf("\nMat khau khong chinh xac vui long nhap lai: ");
			break;
		}
		else{
			printf("\nMat khau chinh xac.");
			break;
			
		}
	} while(strcmp(matkhau, "123456789")!=0);
}
