//Bai 12: Tinh S(n) = x + x^2 + x^3 + … + x^n
#include <stdio.h>
#include<math.h>
int main(){
	int n,x,s=0;
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("\nNhap x: ");
	scanf("%d",&x);
	for(int i=1;i<=n;i++){
	 s=s+pow(x,i);	
	}
    printf("\nTong la s: %d",s);
}
