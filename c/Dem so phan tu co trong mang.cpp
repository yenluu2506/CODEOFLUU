#include<stdio.h>
#define MAX_SIZE 1000
void nhapMang(int a[], int &n);
void xuatMang(int a[], int n);
void sapxepTangdan(int a[], int n);
void lietkeSolanXuathien(int a[], int n);
int main(){
	int a[100], n;
	nhapMang(a,n);
	printf("Mang da nhap la: \n");
	xuatMang(a,n);
	sapxepTangdan(a,n);
	xuatMang(a,n);
	lietkeSolanXuathien(a,n);
}
void nhapMang(int a[], int &n){
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}
void xuatMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%5d", a[i]);
	}
}
void sapxepTangdan(int a[], int n){
	printf("\nMang da sap xep tang dan la: \n");
	int tam;
	for(int i=0; i<n-1; i++){
		for(int j=i; j<n; j++){
			if(a[i]>a[j]){
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
	}
}
void lietkeSolanXuathien(int a[], int n){
	sapxepTangdan(a,n);
	int dem=1;
	for(int i=0; i<n; i++){
		if(a[i]==a[i+1]){
			dem++;
		}
		else {
			printf("\nSo lan xuat hien cua so %d la %d", a[i], dem);
			dem = 1;   
		}
	}
}

