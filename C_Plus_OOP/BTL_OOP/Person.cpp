#include <iostream>
#include <Windows.h>
#include <vector>
#include "Quan_ly_ktx_team_3.cpp"

using namespace std;

class Person
{
protected:
    string name;    //ho va ten
    int age;        //tuoi
    string address; //dia chi
    string id;      //ma id
    double money;   //tinh tien
    bool check;

public:
    Person();
    ~Person();
    string getName();
    void setName(string name);
    int getAge();
    void setAge(int age);
    string getAddress();
    void setAddress(string address);
    void setId(string id);
    string getId();
    virtual void Nhap(int &);
    virtual void Xuat(int &);
    virtual void capnhatThongtin();
    virtual void tinhtien() = 0;
    double getMoney()
    {
        return money;
    }
    bool selection();
    void selection(bool check);
};
Person::Person()
{
    name = "";
    age = 0;
    address = "";
    money = 0;
}
Person::~Person()
{
}
bool Person::selection()
{
    return this->check;
}
void Person::selection(bool check)
{
    this->check = check;
}
string Person::getName()
{
    return name;
}
void Person::setName(string name)
{
    this->name = name;
}
int Person::getAge()
{
    return age;
}
void Person::setAge(int age)
{
    this->age = age;
}
string Person::getAddress()
{
    return address;
}
void Person::setAddress(string address)
{
    this->address = address;
}

string Person::getId()
{
    return id;
}
void Person::setId(string id)
{
    this->id = id;
}
void Person::Nhap(int &n)
{
    fflush(stdin);
    gotoXY(35, 4+n);
    getline(cin, name);
    fflush(stdin);
    gotoXY(60, 4+n);
    cin >> age;
    fflush(stdin);
    gotoXY(70,4+n);
    getline(cin, address);
    gotoXY(85,4+n);
    getline(cin, id);
    fflush(stdin);
    cout<<"\n\n\n";
}

void Person::Xuat(int &n)
{
    gotoXY(35, 4+n);
    cout << name;
    gotoXY(60, 4+n);
    cout << age ;
    gotoXY(70,4+n);
    cout << address ;
    gotoXY(85,4+n);
    cout << id ;
    cout<<"\n\n\n";
}

void Person::capnhatThongtin()
{
    fflush(stdin);
    gotoXY(35, 4);
    getline(cin, name);
    fflush(stdin);
    gotoXY(60, 4);
    cin >> age;
    fflush(stdin);
    gotoXY(70,4);
    getline(cin, address);
    cout<<"\n\n\n\n";
}
