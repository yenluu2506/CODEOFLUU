#include<stdio.h>
#include <conio.h>
#include<stdlib.h>
int main(int n, char *a[]){
	int i;
	int x,y;
	printf("\nTen chuong trinh: %s", a[0]);
	printf("\nCac tham so nhan duoc: ");
	for(int i=1; i<n; ++i)
		printf("\n%s", a[i]);
	x=atof(a[1]);
	y=atof(a[2]);
	printf("\nTong = %d", x+y);
}
