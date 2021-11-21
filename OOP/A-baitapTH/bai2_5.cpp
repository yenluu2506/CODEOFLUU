#include <iostream>
using namespace std;

class MyAddress {
    protected:
        string Diachi;
    public:
        MyAddress();
        ~MyAddress();
        void XuatDiachi();
};
MyAddress::MyAddress(){
    Diachi = "";
}
MyAddress::~MyAddress(){}
void MyAddress::XuatDiachi(){
    cout << "Dia Chi: " << Diachi ;
}
class Person : public MyAddress{
    protected:
        string Ten;
        int Phone;
    public:
        Person();
        ~Person();
};
Person::Person(){
    Ten = "";
    Diachi = "";
    Phone = 0;
}
Person::~Person(){}

class Officer : public Person{
    private:
        float Salary;
    public:
        Officer();
        void Nhap ();
        void Xuat();
        bool operator > (Officer &a);
        void sapxep();
};
Officer::Officer(){
    Ten = "";
    Diachi = "";
    Phone = 0;
    Salary = 0;
}
void Officer::Nhap(){
    fflush(stdin);
    cout << "Nhap Ten: ";
    getline(cin,Ten);
    cout << "Nhap Dia Chi: ";
    getline(cin,Diachi);
    cout << "Nhap So Phone: ";
    cin >> Phone;
    cout << "Nhap Luong: ";
    cin >> Salary;
}
void Officer::Xuat(){
    cout << "Ten: "<<Ten<<" Dia Chi: "<< Diachi <<" So Phone: "<< Phone<<" Luong: "<< Salary<<endl;
}
bool Officer::operator > (Officer &a){
    if (Salary > a.Salary)
        return true;
}

void Officer::sapxep(){
    Officer *a;
    Officer tmp;
    for(int i=0; i < 3; i++){
        for(int j=i+1; j < 4; j++){
            if ((a+i) > (a+j)){
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
        }
    }
    Xuat();
}
int main (){
    Officer *a= new Officer[4];
    Officer p;
    for(int i = 0; i < 4; i++){
        cout << endl<< "Thong tin "<< i+1 << endl;
        (a+i)->Nhap();
    }
    for(int i = 0; i < 4; i++){
        cout << endl<< "Thong tin "<< i+1 << endl;
        (a+i)->Xuat();
    }
    p.sapxep();
    return 0;
}