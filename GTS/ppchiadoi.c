#include<conio.h>
#include<stdio.h>
#include<math.h>
void nhap( float d[20],int n){
		int i;
		for (i=0;i<=n;i++)
		{printf("d[%d]=",i);scanf("%f",&d[i]);
		}
	}
float f(float d[],int n, float c ){
		int i; float p=d[0];
		for(i=1;i<=n;i++)
		p=p*c+d[i];
		return p;
}
int main(){
	float x,d[10],a,b,c,e; //char q;
	int i,n;
		printf("nhap bac da thuc n\n");scanf("%d",&n);
		printf("nhap cac he so\n");
	nhap(d,n);
	while(1){
    printf("\n nhap khoang nghiem a va b\n"); scanf("%f%f",&a,&b);
    if (f(d,n,a)*f(d,n,b)>0) continue;
    
      	do
      	{
	   
      	  c=(a+b)/2; e=f(d,n,c);
      	   printf("\n%9.3f%9.3f%9.3f\n",a,b,e);
        	if(e*f(d,n,a)>0) 
      	  a=c;
      	else
		  b=c; 
		 }
		while(fabs(e)>=0.001);
		printf("\n nghiem cua chuong trinh la:%.3f",c);
	  }
}