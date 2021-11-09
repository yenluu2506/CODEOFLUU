//Bai 2: Tinh S(n) = 1^2 + 2^2 + … + n^2
#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int s=0;
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		s=s+pow(i,2);
	}
	printf("Tong s la: %d", s);
	return 0;
}
