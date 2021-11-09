#include<stdio.h>
int A[100], B[100], n;
void nhapmang();
//void xuatmang(int A[], int n);
void Dem();
int main(){
	nhapmang();
//	xuatmang(A,n);
	Dem();
}
void nhapmang(){
	printf("Nhap so phan tu n: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("A[%d]: ", i);
		scanf("%d", &A[i]);
	}
	for(int i=0; i<n; i++){
		B[i]=1;
	}
}
//void xuatmang(int A[], int n){
//	printf("Mang da nhap la:\n ");
//	for(int i=0; i<n; i++){
//		printf("%5d", A[i]);
//	}
//}
void Dem(){
	printf ("Gia tri \t so lan \n");
	int dem=1;
	for(int i=0; i<n; i++){
		if(B[i]){
			B[i]=0;
			for(int j=i+1; j<n; j++){
				if(A[j]==A[i]){
					dem++;
					B[j]=0;
				}
			}
			printf("%5d \t %5d \n", A[i], dem);
		}
	}
}
