#include<stdio.h>
#include<conio.h>

void main() {
    int n,i,l,j,t,k;
    float x[100], y[100], p[100] [100], c, kq;
    printf("Nhap n: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) { 
        printf("Nhap x[%d], y[%d] ", i,i); 
        scanf("%f%f",&x[i], &y[i]);
    }
    for (i=0; i<n; i++) { 
        p[i] [0]=x[i];
        p[i] [1]=y[i];
    }
    //tinh ty hieu
    l=1;
    for(j=0; j<n; j++){
        k=j+2;
        for (t=1; t<n; t++) {
            p[t] [k] = (p[t] [k-1]-p[t-1] [k-1])/(x[t]-x[t-1]);
        }
        l=l+1;
    }
    //lap bang ti hieu
    for(i=0; i<n; i++){
        for(j=0; j<n+2; j++){
            printf("%.2f\t\t", p[i][j] );
        }
        printf("\n");
    }
    printf("Nhap gia tri can tinh gan dung: ");
    scanf("%f", &c);
    float tich;
    for(i=0; i<n; i++){
        tich=1;
        for(j=0; j<i;j++){
            tich=tich*(c-x[j]);
        }
        kq = kq+p[i][i+1]*tich;
    }
    printf("Ket qua la: %.2f", kq);
}