#include<stdio.h>
void nhap(int a[], int &amp, int n){
    do{
        printf("Nhap n: ");
        scanf("%d",&amp,n);
    }
    while(n<2||n>99);
     
    for(int i=0; i<n; i++){
        printf("a[%d]: ",i);
        scanf("%d",&amp, a[i]);
    }
}
 
void xuat(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%5d",a[i]);
    }
}
int ktrant(int n){
    if(n<2)
        return 0;
    else{
        for(int i=2;i<=n/2;i++)
            if(n%i==0)
                return 0;
        return 1;
    }
}
 
void insonguyento(int a[], int n){
    printf("\nCac so nguyen to co trong mang la: \n");
    for(int i=0;i<n;i++)
        if(ktrant(a[i]))
            printf("%5d",a[i]);
}
int main(){
    int a[100];
    int n;
    nhap(a,n);
    insonguyento(a,n);
    return 0;
}
