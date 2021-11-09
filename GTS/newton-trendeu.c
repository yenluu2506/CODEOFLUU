#include<stdio.h>

void main()
{
    float x[20],fx[20][20],xvalue,h,p,temp,ans;
    int n,i,j,fact;
    printf("\n Nhap gia tri cua x can tinh cho f(x): ");
    scanf("%f",&xvalue);
    printf("\n Nhap so luong phan tu: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\n Nhap gia tri cua x: ");
        scanf("%f",&x[i]);
        printf("\n Nhap gia tri cua f(x): ");
        scanf("%f",&fx[i][0]);
    }

    h=x[1]-x[0];
    p=(xvalue-x[0])/h;

    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            fx[j][i]=fx[j+1][i-1]-fx[j][i-1];
        }
    }

    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n-i;j++)
        {
            printf("%f ",fx[i][j]);
        }
    }

    ans=fx[0][0];
    for(i=1;i<n;i++){
        temp=p;
        for(j=1;j<i;j++){
            temp=temp*(p-j);
        }

        fact=1;
        for(j=1;j<=i;j++){
            fact=fact*j;
        }
        ans=ans+((temp/fact)*fx[0][i]);
    }
    printf("\n f(x) = %f",ans);
}