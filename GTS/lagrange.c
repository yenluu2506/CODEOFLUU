#include <stdio.h>

int n;
float c, x[100], y[100], P, L;

int main(){
    printf("Nhap gia tri n: ");
    scanf("%d", &n);
    printf("Nhap gia tri c: ");
    scanf("%f", &c);
    for(int i=0; i<n; i++){
        printf("Nhap x[%d], y[%d]: ", i, i);
        scanf("%f%f", &x[i], &y[i]);
    }
    P=0;
    for (int i=0; i<n; i++){
        L=1;
        for(int j=0; j<n; j++){
            if(i!=j){
                L=L*(c-x[i])/(x[i]-x[j]);
            }
        }
        P=P+y[i]*L;
        printf("L = %f \n", L);
    }
    printf("P(%f) = %f", c, P);
}