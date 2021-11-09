#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct {
    char HoTen[50];
    int Tuoi;
    char Lop[10];
} Sinh_Vien;
void Nhap_ds(int *n,Sinh_Vien sv[100])
{
    printf("\nNhap so sinh vien: ");
    scanf("%d",n);
    for(int i=0;i<*n;i++)
    {
        printf("\nNhap thong tin sinh vien: %d",i+1);
        printf("\nNhap ho ten: ");
        fflush(stdin);
        gets(sv[i].HoTen);
        printf("Nhap tuoi: ");
        scanf("%d",&sv[i].Tuoi);
        printf("Nhap lop: ");
        fflush(stdin);
        gets(sv[i].Lop);
    }
}
void In_ds(int n,Sinh_Vien sv[100])
{
    printf("\nDANH SACH SINH VIEN");
    printf("\nSTT     HO TEN    TUOI     LOP");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%s\t%d\t%s",i+1,sv[i].HoTen,sv[i].Tuoi,sv[i].Lop);
    }
}
void Tim_ds(int n,Sinh_Vien sv[100])
{
    int i=0;
    printf("\nTIM KIEM SINH VIEN");
    char name[50];
    printf("\nNhap ten sinh vien: ");
    fflush(stdin);
    gets(name);
    for(i=0;i<n;i++){
        if(strcmp(sv[i].HoTen,name)==0){
        printf("\nDANH SACH SINH VIEN TIM THAY");
        printf("\nSTT     HO TEN    TUOI     LOP");
        printf("\n%d\t%s\t%d\t%s",i+1,sv[i].HoTen,sv[i].Tuoi,sv[i].Lop);
            break; 
        }
    }
    if(i==n){
        printf("Khong tim thay");
    }
}
main()
{
    int c;
    Sinh_Vien sv[100];
    int n;

    while(c!=4){
        printf("\nChon 1: Nhap danh sach sinh vien");
        printf("\nChon 2: Hien thi danh sach sinh vien");
        printf("\nChon3: Tim kiem sinh vien theo Ten");
        printf("\nChon4: Ket thuc");
        printf("\nMoi ban chon: ");
        scanf("%d",&c);
    switch(c){
        case 1:
            Nhap_ds(&n,sv);
            //system("cls");
            break;
        case 2:
            In_ds(n,sv);
            break;
        case 3:
            Tim_ds(n,sv);
            break;
        }
    }
}
