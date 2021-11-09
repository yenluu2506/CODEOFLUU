#include<conio.h>
#include<stdio.h>
#include<math.h>
void nhap( float d[],int n){
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
main(){
	float x,d[10],a,b,t1,t2; char q;
	int i,n;
	printf("nhap bac da thuc n\n");scanf("%d",&n);
		printf("nhap cac he so\n");
	nhap(d,n);
	while(1){
    printf("\n nhap khoang nghiem a va b\n"); scanf("%f%f",&a,&b);
    if (f(d,n,a)*f(d,n,b)>0){
    	printf("\n a b khong phaikhoang ngiem\n");
	   continue;}
    do{
  	printf("\n%9.3f%9.3f%9.3f%9.3f",a,b,x,f(d,n,x));
       x=a-((b-a)*f(d,n,a))/(f(d,n,b)-f(d,n,a));
       if(f(d,n,x)*f(d,n,a)>0) a=x;
       else b=x;
		}
	 while(fabs(f(d,n,x))>=0.001);
	 printf("\nngiem cua phuong trinh la %.3f",x);
	 printf("\ntiep tuc k?(c/k)");
	 q=getch();
	 if(q=='k') break;
    }
}