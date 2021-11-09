#include<stdio.h>
void nhapmang(int A[], int n){
	printf("Nhap vao so phan tu n: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("a[%d]: ", i);
		scanf("%d", &A[i]);
	}
}
void xuatmang(int A[], int n){
	printf("\nMang da nhap la: ");
	for(int i=0; i<n; i++){
		printf("%5d", A[i]);
	}
}
int Tong_DeQuy(int A[], int n){
	if(n==1){
		return A[0];
	}
	else{
		return A[n-1] + Tong_DeQuy(A, n-1);
	}
}
int main(){
	int A[100];
	int n;
	nhapmang(A,n);
	xuatmang(A,n);
	printf("Tong day so tinh bang de quy la: %d ", Tong_DeQuy(A,n));
}
