/* - nh?p xu?t 1 nv
   - tính luong nhân viên theo h? s? luong*/
 // bac luong 1,2,3
 // he so luong bac1 la 4.8, bac 2 la 5, bac 3 la 6
 //ptr = (int*) calloc(100, sizeof(int));
 
#include <stdio.h>
#include <stdlib.h>
 struct NhanVien{
     char hoten[30];
     int namsinh;
     float luongcoban;
     float hesoluong;
     float bacluong;
 };
 typedef struct NhanVien NHANVIEN;
 void NhapNhanVien(NHANVIEN *nv ){
     printf("Nhap ten: ");
     gets(nv->hoten);
     printf("Nam sinh: ");
     scanf("%d",&nv->namsinh);
     printf("Nhap luongcoban: ");
     scanf("%f",&nv->luongcoban);
     printf("he so luong bac1 la 4.8, bac 2 la 5, bac 3 la 6");
     printf("\nNhap hesoluong: ");
     scanf("%f",&nv->hesoluong);
     printf("Nhap bacluong: ");
     scanf("%f",&nv->bacluong);
 }
void XuatNhanVien(NHANVIEN *nv){
    printf("\nhoten: %s",nv->hoten);
    printf("\nnamsinh: %d",nv->namsinh);
    printf("\nhesoluong: %.0f",nv->hesoluong);
    printf("\nbacluong: %.0f",nv->bacluong);
}
float TinhLuong(NHANVIEN *nv){
    float tongluong;
    tongluong = nv->luongcoban*nv->hesoluong*nv->bacluong;
return tongluong;
}
int main(){
    float luong;
    NHANVIEN *nv;
    nv = (NHANVIEN*) malloc(sizeof(NHANVIEN));
    NhapNhanVien(nv);
    XuatNhanVien(nv);
    luong =TinhLuong(nv);
    printf("\nLuong Nhan Vien duoc nhan la: %.0f",luong);
return 0;
}
