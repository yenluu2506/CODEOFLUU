#include <Windows.h>
#include <vector>
#include"Person.cpp"
#include "Quan_ly_ktx_team_3.cpp"

using namespace std;

class Manage : public Person
{
private:
    double coefficientssalary; //he so luong
    string position;           //chuc vu
    string phone;              //so dien thoai
    double seniority;          //tham nien
public:
    Manage();
    ~Manage();
    double getCoefficientssalary();
    void setCoefficientssalary(double coefficientssalary);
    double getSeniority();
    void setSeniority(double seniority);
    string getPosition();
    void setPosition(string position);
    string getPhone();
    void setPhone(string phone);
    void tinhtien()
    {
        money = coefficientssalary * 1600 + seniority * 500;
    }
    void Nhap(int &n);
    void Xuat(int &n);
    void capnhatThongtin();
};
Manage::Manage()
{
    seniority = 0;
    position = "";
    phone = "";
    coefficientssalary = 0;
}
Manage::~Manage()
{
}
double Manage::getCoefficientssalary()
{
    return coefficientssalary;
}
void Manage::setCoefficientssalary(double coefficientssalary)
{
    this->coefficientssalary = coefficientssalary;
}
string Manage::getPosition()
{
    return position;
}
void Manage::setPosition(string position)
{
    this->position = position;
}
double Manage::getSeniority(){
    return seniority;
}
void Manage::setSeniority(double seniority){
    this->seniority = seniority;
}
string Manage::getPhone()
{
    return phone;
}
void Manage::setPhone(string phone)
{
    this->phone = phone;
}

void Manage::Nhap(int &n)
{
    Person::Nhap(n);
    gotoXY(100,4+n);
    getline(cin, phone);
    fflush(stdin);
    gotoXY(115,4+n);
    cin >> seniority;
    fflush(stdin);
    gotoXY(130,4+n);
    cin >> coefficientssalary;
    fflush(stdin);
    gotoXY(145,4+n);
    getline(cin, position);
    cout<<"\n\n\n\n";
}


void Manage::Xuat(int &n)
{
    Person::Xuat(n);
    gotoXY(100,4+n);
    cout << phone;
    gotoXY(115,4+n);
    cout << seniority;
    gotoXY(130,4+n);
    cout << coefficientssalary;
    gotoXY(145,4+n);
    cout << position;
    gotoXY(160,4+n);
    this->tinhtien();
    cout << money;
    cout<<"\n\n\n\n";
}


void Manage::capnhatThongtin()
{
    Person::capnhatThongtin();
    gotoXY(100,4);
    getline(cin, phone);
    fflush(stdin);
    gotoXY(115,4);
    cin >> seniority;
    fflush(stdin);
    gotoXY(130,4);
    cin >> coefficientssalary;
    fflush(stdin);
    gotoXY(145,4);
    getline(cin, position);
    cout<<"\n\n\n\n";
}

