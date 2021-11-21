//BAI 2.2
#include<iostream>
using namespace std;
///MYDATE
class MyDate{
    protected:
        int ngay, thang, nam;
    public:
        MyDate();
        ~MyDate();
        void Nhap();
        void Xuat();
        bool operator > (MyDate x);
};
MyDate::MyDate(){
    this->ngay = 0;
    this->thang = 0;
    this->nam = 0;
}
MyDate::~MyDate(){}
void MyDate::Nhap() {
    cout<<"Nhap ngay: ";
    cin>>ngay;
    cout<<"Nhap thang: ";
    cin>>thang;
    cout<<"Nhap nam: ";
    cin>>nam;
 }
void MyDate::Xuat(){
    cout<<"\n Ngay - Thang - Nam: ";
    cout<<ngay<<"-"<<thang<<"-"<<nam<<endl;
}
bool MyDate::operator>(MyDate x){
    if(this->nam > x.nam) 
    return true;
    if((this->nam == x.nam)&&(this->thang > x.thang)) 
    return true;
    if((this->nam == x.nam)&&(this->thang == x.thang)&&(this->ngay > x.ngay))
    return true;
    else
       return 0;
}

///PERSON
class Person : public MyDate{
    protected:
        string Name;
        string Address;
        long Phone;
    public: 
        Person();
        ~Person();
        void Nhap();
        void Xuat();
};
Person::Person(){
    this->Name ="";
    this->Address = "";
    this->Phone = 0;
}
Person::~Person(){}

void Person::Nhap(){
MyDate::Nhap();
cout<<"\tNhap ten: ";
cin>>Name;
cout<<"\tNhap dia chi: ";
cin>>Address;
cout<<"\tNhap so dien thoai: ";
cin.ignore();
cin>>Phone;
}
void Person::Xuat(){
MyDate::Xuat();
cout<<"\tTen la: "<<Name<<endl;
cout<<"\tDia chi la: "<<Address<<endl;
cout<<"\tSo dien thoai la: "<<Phone<<endl;
}

class SVCN : public Person{
    private: 
        float Salary;
    public: 
        SVCN();
        ~SVCN();
        void Nhap();
        void Xuat();  
};
SVCN::SVCN(){
    this->Salary = 0;
}
SVCN::~SVCN(){}
void SVCN::Nhap(){
    Person::Nhap();
    cout<<"\tNhap luong can bo: ";
    cin>>Salary;
}
void SVCN::Xuat(){
    Person::Xuat();
    cout<<"\tLuong can bo la: "<<Salary<<endl;
}
int main(){
    SVCN *y = new SVCN[10];
    SVCN *cb[4], *tg;
    for(int i = 0; i<4; i++){
        cb[i] = new SVCN;
        cout<<"Nhap thong tin can bo vien chuc thu " << i+1 << ":" <<endl;
        cb[i]->Nhap();
        cb[i]->Xuat();
    }

cout<<"\nDANH SACH TRUOC KHI SAP XEP:";
for(int i=0; i<4; i++){
    cout<<"\n Can bo thu "<<i+1<<":"<<endl;
    cb[i]->Xuat();
}
for(int i=0; i<3; i++){
    for(int j=j+1; j<4; j++){
        if(*cb[i]>*cb[j]){
            tg=cb[i];
            cb[i]=cb[j];
            cb[j]=tg;
        }
    }
} 
cout<<"\nDANH SACH SAU KHI SAP XEP:";
for(int i=0; i<4; i++) {
    cout<<"\nCan bo thu "<<i+1<<":"<<endl;
    cb[i]->Xuat();
}
return 0;
}
