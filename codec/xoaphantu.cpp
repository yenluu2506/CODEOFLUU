#include<stdio.h>
#include<conio.h>
using namespace std;
void nhapmang(int a[], int &n)
{ printf("nhap so phan tu :" );
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  { printf(" phan tu thu %d :",i);
    scanf("%d",&a[i]);
  }
}
int xuatmang(int a[],int n)
 {for(int i=0;i<n;i++)
   {
     printf("%d \t",a[i]);
   }
 }
void xoa1vitrik(int a[],int n)
{
 int k;
 printf("nhap vi tri can xoa: ");
 scanf("%d",&k);
 for(int i=0;i<n;i++)
  a[k]=a[k+1]; 
 n=n-1; 
 xuatmang(a,n);   
}
int main()
{
 int a[50],n;
 nhapmang(a,n);
 xoa1vitrik(a,n);
 return 0;
}
