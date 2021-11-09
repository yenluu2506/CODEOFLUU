#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int n;
	float t,x0, eps;
	float x[n];
	int i;
	float f(float);
	float daoham(float);
	printf("Timnghiemcuaphuongtrinhphituyen\n");
	printf("bangphuongphaplapNewton\n");
	printf("Chogiatricuax0= ");
	scanf("%f",&x0);i=1;x[i]=x0;
	do{
	x[i+1]=x[i]-f(x[i])/daoham(x[i]);
	t=fabs(x[i+1]-x[i]);
	x[i]=x[i+1];
	i=i+1;
	if(i>100){
	printf("Baitoankhonghoitu\n");
	getch();
	exit(1);
	}else;
	}while(t>=eps);
	printf("Nghiemx=%.5f",x[i]);
	getch();
	float f (float x){
	    float a=x*x-x-2;
	    return(a);}
	float daoham(float x){float d=2*x-1;return(d);
}