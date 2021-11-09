#include<conio.h>
#include<stdio.h>
#include<string.h>

int nhap(void)
{
	int n;
	printf("N= ");
	scanf("%d",&n);
	while(n<=0||n>=20)
		{
		printf("Nhap lai N = ");
		scanf("%d",&n);
		}
	return(n);
}
void  nhapmang(int *a,int n)
{
int i;
for(i=0;i<n;i++)
	do
	{
	printf("Nhap a[%d] = ",i);
	scanf("%d",&a[i]);
	} while (a[i]>=n);
}
void sum(int *a, int n)
{
int tong,i;
for(i=0;i<n;i++)
	tong+=a[i];
printf(" Sum = %d",tong);
}

void menu(void)
{
	printf("  **  Choice **");
	printf("\n  1. Nhap N");
	printf("\n  2. Nhap Mang");
	printf("\n  3. Tinh tong mang");
	printf("\n  4. Exit\n");
}

void main()
{
int i=0,chon,m,b[20];
clrscr();
menu();
scanf("%d",&chon);
switch(chon)
{
	case 1:
	{       m=nhap();
		i=1;
		break;
	}
	case 2:
	{
		if(i==1)
		{
			nhapmang(b,m);
			i=2;
			break;
		}
		else
		{
			printf("Hay nhap N !\n");
			m=nhap();
			nhapmang(b,m);
			i=2;
			break;
		}

	}
	case 3:
	{
		if(i==2)
		{
			sum(b,m); break;
		}
		else
		{
		    printf("Chua Nhap mang.\n");
		    if(i==1)
			 {
			   nhapmang(b,m);
			 }
			   else
			   if(i==0)
			       {
			       printf("\n\nChua nhap N!\n");
			       m=nhap();
			       nhapmang(b,m);
			       sum(b,m);
			       }
      
	       break;
		}
	}

	case 4: exit(0);

	default : menu();
}

