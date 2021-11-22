#include <iostream>
using namespace std;

struct Phanso{
    int tu, mau;
};

void nhapPhanso(Phanso & ps){
    cout<< "Nhap tu so: "<< endl;
    cin>> ps.tu;
    do{
        cout<< "Nhap mau so: "<< endl;
        cin>> ps.mau;
        if(ps.mau == 0){
            cout << "Mau so phai khac 0"<< endl;
        }
    }while (ps.mau == 0);  
}
void xuatPhanso(const Phanso ps){
    cout << ps.tu<< "/"<< ps.mau;
}
int timUCLN(int a, int b){
    a = abs(a);
    b = abs(b);
    while (a!=b)
    {
        if(a>b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
    
}
void Rutgon(Phanso &ps){
    int UCLN = timUCLN(ps.tu, ps.mau);
    ps.tu /= UCLN;
    ps.mau /= UCLN;
}
Phanso tinhTong(const Phanso x,const  Phanso y){
    Phanso Tong;
    Tong.tu = x.tu * y.mau + x.mau * y.tu;
    Tong.mau = x.mau * y.mau;
    Rutgon(Tong);
    return Tong;
}
Phanso tinhHieu(const Phanso x,const Phanso y){
    Phanso Hieu;
    Hieu.tu = x.tu * y.mau - x.mau * y.tu;
    Hieu.mau = x.mau * y.mau;
    Rutgon(Hieu);
    return Hieu;
}
Phanso tinhTich(const Phanso x,const Phanso y){
    Phanso Tich;
    Tich.tu = x.tu * y.tu;
    Tich.mau = x.mau * y.mau;
    Rutgon(Tich);
    return Tich;
}
Phanso tinhThuong(const Phanso x,const Phanso y){
    Phanso Thuong;
    Thuong.tu = x.tu * y.mau;
    Thuong.mau = x.mau * y.tu;
    Rutgon(Thuong);
    return Thuong;
}
bool kiemtraDuong(const Phanso ps){
    return ps.tu / ps.mau > 0;
}
int sosanhPhanso(const Phanso ps1, const Phanso ps2){
    if((float)ps1.tu / ps1.mau > (float)ps2.tu / ps2.mau)
        return 1;
    else if((float)ps1.tu / ps1.mau == (float)ps2.tu / ps2.mau)
        return 0;
    else
        return -1;
}
int main(){
    Phanso x,y;
    nhapPhanso(x);
    xuatPhanso(x);
    if(kiemtraDuong(x)){
        cout<<"Phan so x la phan so duong"<< endl;
    }
    else
        cout<< "Phan so x la phan so am" << endl;
    nhapPhanso(y);
    xuatPhanso(y);
    if(kiemtraDuong(y)){
        cout<<"Phan so y la phan so duong"<< endl;
    }
    else
        cout<< "Phan so y la phan so am" << endl;
    if(sosanhPhanso(x, y)==1)
        cout << "x>y"<< endl;
    else if (sosanhPhanso(x, y)==0)
        cout << "x=y"<< endl;
    else cout<< "x<y"<< endl;
    Phanso Tong = tinhTong (x, y);
    Phanso Hieu = tinhHieu (x, y);
    Phanso Tich = tinhTich (x, y);
    Phanso Thuong = tinhThuong (x, y);
    cout << "Tong: ";
    xuatPhanso(Tong);
    cout << endl;
    cout << "Hieu: ";
    xuatPhanso(Hieu);
    cout << endl;
    cout << "Tich: ";
    xuatPhanso(Tich);
    cout << endl;
    cout << "Thuong: ";
    xuatPhanso(Thuong);
    cout << endl;
    system("pause");
    return 0;
}