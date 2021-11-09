//bai 5

#include <stdio.h>
void Nhapmang(int A[], int n){
	for (int i=0; i<n; i++){
		printf("a[%d]: ", i);
		scanf("%d", &A[i]);
	} 
}
void Xuatmang(int A[], int n){
	for(int i=0; i<n; i++){
		printf("%5d", A[i]);
	}
}
int Max(int A[], int n){
	int Max= A[0];
	for(int i=0; i<n ; i++){
		if(Max < A[i] ){
			Max = A[i];
		}
	}
	return Max;
}
int VitriMax(int A[], int n){
	int vitri = Max(A,n);
	for (int i=0; i<n; i++){
		if(vitri == A[i]){
			return i+1;
		}
	}
}
int main(){
	int A[100];
	int n;
	printf("Nhap vao n: ");
	scanf("%d", &n);
	Nhapmang(A,n);
	Xuatmang(A,n);
	printf("\nGia tri lon nhat cua mang la: %d ", Max(A,n));
	printf("\nVi tri cua gia tri lon nhat la: %d ", VitriMax(A,n));
}
