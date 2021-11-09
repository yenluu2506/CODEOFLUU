#include <stdio.h>
 
 
void NhapMaTran(int a[][100], int m, int n)
{
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
      {
         printf("A[%d][%d] = ", i, j);
         scanf("%d", &a[i][j]);
      }
}

void XuatMaTran(int a[][100], int m, int n)
{
   for(int i = 0; i < m; i++)
   {
      for(int j = 0; j < n; j++)
         printf("%d\t", a[i][j]);
      printf("\n");
   }
}
 
int PhanTuLonNhat(int a[][100], int m, int n)
{
   int max = a[0][0];
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(a[i][j]>max)
            max = a[i][j];
   return max;
}

int PhanTuNhoNhat(int a[][100], int m, int n)
{
   int min = a[0][0];
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(a[i][j]<min)
            min = a[i][j];
   return min;
}
 
int main(){
    int a[100][100];
    int m,n;
    printf("nhap so hang n = "); scanf("%d",&n);
    printf("nhap so cot m = "); scanf("%d",&m);
    printf("nhap vao ma tran:\n");
    NhapMaTran(a, m , n);
    XuatMaTran(a, m, n);
    printf("\nPhan tu lon nhat la %d", PhanTuLonNhat(a, m, n));
    printf("\nPhan tu nho nhat la %d", PhanTuNhoNhat(a, m, n));
}
