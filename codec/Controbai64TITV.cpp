#include <stdio.h>

int main(){
	//thu nhat chung ta co mot mang bat ki, ten cua mang no duoc xem nhu la mot cai bien con tro
//	int x[] = {1, 2, 3, 4, 5};
//	printf("Mang x: ");
//	for(int i=0; i<5; i++){
//		printf("%4d", x[i]);
//	}
//	//dia chi cua ten mang se trung voi dia chi cua phan tu dau tien trong mang do
//	printf("\n Dia chi cua bien x la: %p", &x);
//	printf("\n Dia chi cua bien x[0] la: %p", &x[0]);
	
	int x[10];
	int n = 10;
	//khi nhap du lieu thi co the su dung ten mang cong dan len thi se lay cac dia chi cua phan tu vi no la con tro
	printf("\nNhap vao cac gia tri cua mang: ");
	for(int i=0; i<n; i++){
		printf("\nx[%d]: ", i);
//		scanf("%4d", &x[i]);
		scanf("%4d", x+i);
	}
	//de lay ra duoc gia tri tai mot dia chi nao do thi chung ta them dau * phia truoc dia chi
	printf("\nGia tri cua mang la: ");
	for(int i=0; i<n; i++){
//		printf("%5d", x[i]);
		printf("%5d", *(x+i));
	}
}
