#include <iostream>
#include <string.h>
using namespace std;

struct Congnhan{
    char ten[30];
    int namsinh;
    int sogiolam;
};
void nhap(Congnhan *congnhan){
    fflush (stdin);
    cout<< "Ho va ten: ";
    gets(congnhan->ten);
    cout<< "Nam sinh: ";
    cin>> congnhan->namsinh;
    cout << "So gio lam: ";
    cin >> congnhan->sogiolam;
}
void xuat(Congnhan *congnhan){
    fflush(stdin);
    cout<<"Ho va ten: "<< congnhan->ten<< endl;
    cout<< "Nam sinh: "<< congnhan->namsinh<< endl;
    cout << "So gio lam: "<< congnhan->sogiolam<< endl;
}
void nhap(Congnhan *&danhsach , int &soluong){
    cout << "Nhap so luong sinh vien: ";
    cin >> soluong;
	danhsach = new Congnhan[soluong];
    for(int i=0; i<soluong; i++){
        cout<< "Cong nhan thu "<< i+1 << endl;
        nhap(&*(danhsach+i));
    }
}
void xuat(Congnhan *danhsach, int soluong){
    for(int i=0; i<soluong; i++){
        cout<< "Cong nhan thu "<< i+1<< endl;
        xuat(&*(danhsach+i));
    }
}
void sapxeptheoGio(Congnhan *danhsach, int soluong){
    Congnhan tam;
    for(int i=0; i<soluong; i++){
        for(int j=i+1; j<soluong; j++){
            if((danhsach+i)->sogiolam > (danhsach+j)->sogiolam){
                tam = *(danhsach+i);
                *(danhsach+i)=*(danhsach+j);
                *(danhsach+j)=tam;
            }
        }
    }
}
int main(){
    Congnhan *danhsach;
    int soluong;
    nhap(danhsach, soluong);
    cout<< "-------------------------Danh sach cong nhan------------------------"<< endl;
    xuat(danhsach, soluong);
    sapxeptheoGio(danhsach, soluong);
    cout<< "-------------Danh sach da sap xep tang dan theo gio lam-------------"<< endl;
    xuat(danhsach, soluong);
    delete[] danhsach;
}
