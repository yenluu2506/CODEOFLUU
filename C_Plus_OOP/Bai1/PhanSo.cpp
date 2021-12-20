#include<iostream>
#include "PhanSo.h"
#include<math.h>
using namespace std;
PHANSO::PHANSO(){
    TuSo=0;
    MauSo=1;
}
PHANSO::PHANSO(double a,double b){
    TuSo=a;
    MauSo=b;
}
void PHANSO::Reduce(){
    double ucln;
    double a=abs(TuSo);
    double b=abs(MauSo);
    if(TuSo==0&&MauSo==0){
        ucln=TuSo+MauSo;
    }
    else{
        while(a!=b){
            if(a>b){
                a-=b;
            }
            else
            {
                b-=a;
            }
        }
        ucln=a;
    }
    TuSo/=ucln;
    MauSo/=ucln;
}
PHANSO::~PHANSO(){
}
PHANSO PHANSO::operator+(const PHANSO & Ps){
    PHANSO res;
    res.TuSo=this->TuSo*Ps.MauSo+Ps.TuSo*this->MauSo;
    res.MauSo=this->MauSo*Ps.MauSo;
    res.Reduce();
    return res;
}
PHANSO PHANSO::operator-(const PHANSO & Ps){
    PHANSO res;
    res.TuSo=this->TuSo*Ps.MauSo-Ps.TuSo*this->MauSo;
    res.MauSo=this->MauSo*Ps.MauSo;
    res.Reduce();
    return res;
}
PHANSO PHANSO::operator*(const PHANSO & Ps){
    PHANSO res;
    res.TuSo=this->TuSo*Ps.TuSo;
    res.MauSo=this->MauSo*Ps.MauSo;
    res.Reduce();
    return res;
}
PHANSO PHANSO::operator/(const PHANSO & Ps){
    PHANSO res;
    res.TuSo=this->TuSo*Ps.MauSo;
    res.MauSo=this->MauSo*Ps.TuSo;
    res.Reduce();
    return res;
}
bool PHANSO::operator==(const PHANSO & Ps){
    return (this->TuSo/this->MauSo-Ps.TuSo/Ps.MauSo==0);
}
bool PHANSO::operator!=(const PHANSO & Ps){
    return (this->TuSo/this->MauSo-Ps.TuSo/Ps.MauSo!=0);
}
bool PHANSO::operator>(const PHANSO & Ps){
    return (this->TuSo/this->MauSo-Ps.TuSo/Ps.MauSo>0);
}
bool PHANSO::operator<(const PHANSO & Ps){
    return (this->TuSo/this->MauSo-Ps.TuSo/Ps.MauSo<0);
}
bool PHANSO::operator>=(const PHANSO & Ps){
    return (this->TuSo/this->MauSo-Ps.TuSo/Ps.MauSo>=0);
}
bool PHANSO::operator<=(const PHANSO & Ps){
    return (this->TuSo/this->MauSo-Ps.TuSo/Ps.MauSo<=0);
}
ostream & operator<<(ostream &os,const PHANSO &Ps){
    os<<Ps.TuSo<<"/"<<Ps.MauSo;
    return os;
}
istream & operator>>(istream &is,PHANSO& Ps){
    cout<<"Nhap tu so: ";
    is>>Ps.TuSo;
    cout<<"Nhap mau so: ";
    while(cin>>Ps.MauSo,Ps.MauSo==0){
        cout<<"Mau so khac 0, nhap lai: ";
    }
    return is;
}
PHANSO::PHANSO(const PHANSO &ps){
    this->MauSo=ps.MauSo;
    this->TuSo=ps.TuSo;
}
PHANSO PHANSO::operator=(const PHANSO & ps){
    this->MauSo=ps.MauSo;
    this->TuSo=ps.TuSo;
    return *this;
}
PHANSO::PHANSO(double a){
    this->MauSo=1;
    this->TuSo=a;
}