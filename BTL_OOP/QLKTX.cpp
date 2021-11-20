#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "setcolor.h"
#include <conio.h>
#include <cstdlib>

using namespace std;

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void gotoXY (int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

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

class Student : public Person
{
private:
    string identitycard; //so CMND
    int room;            // so phong
    double unitprice;    //don gia
    int violations;      //so lan vi pham noi qui
    double months;       //so thang
public:
    Student();
    ~Student();
    void setIdentitycard(string identitycar);
    string getIdentitycard();
    void setRoom(int room);
    int getRoom();
    void setUnitprice(unsigned long int unitprice);
    double getUnitprice();
    void setViolations(int violations);
    int getViolations();
    double getMonths();
    void setMonths(double months);
    void Nhap(int &n);
    void Xuat(int &n);
    void tinhtien()
    {
        this->money = this->months * this->unitprice;
    }
    void capnhatThongtin();
};
Student::Student()
{
    id = "";
    identitycard = "";
    room = 0;
    unitprice = 0;
    violations = 0;
    months = 0;
}
Student::~Student()
{
}
string Student::getIdentitycard()
{
    return identitycard;
}
void Student::setIdentitycard(string identitycard)
{
    this->identitycard = identitycard;
}
int Student::getRoom()
{
    return room;
}
void Student::setRoom(int room)
{
    this->room = room;
}
double Student::getMonths()
{
    return months;
}
void Student::setMonths(double months)
{
    this->months = months;
}
double Student::getUnitprice()
{
    return unitprice;
}
void Student::setUnitprice(unsigned long int unitprice)
{
    this->unitprice = unitprice;
}
int Student::getViolations()
{
    return violations;
}
void Student::setViolations(int violations)
{
    this->violations = violations;
}
void Student::Nhap(int &n)
{
    Person::Nhap(n);
    gotoXY(100,4+n);
    getline(cin, identitycard);
    fflush(stdin);
    gotoXY(115,4+n);
    cin >> room;
    fflush(stdin);
    gotoXY(125,4+n);
    cin >> months;
    fflush(stdin);
    gotoXY(135,4+n);
    cin >> unitprice;
    fflush(stdin);
    gotoXY(148,4+n);
    cin >> violations;
    fflush(stdin);
    cout<<"\n\n\n\n";
}

void Student::Xuat(int &n)
{
    Person::Xuat(n);
    gotoXY(100,4+n);
    cout << identitycard;
    gotoXY(115,4+n);
    cout << room ;
    gotoXY(125,4+n);
    cout << months;
    gotoXY(135,4+n);
    cout << unitprice;
    gotoXY(148,4+n);
    cout << violations;
    gotoXY(162,4+n);
    this->tinhtien();
    cout << money ;
    cout<<"\n\n\n\n";
}

void Student::capnhatThongtin()
{
    Person::capnhatThongtin();
    gotoXY(100,4);
    getline(cin, identitycard);
    fflush(stdin);
    gotoXY(115,4);
    cin >> room;
    fflush(stdin);
    gotoXY(125,4);
    cin >> months;
    fflush(stdin);
    gotoXY(135,4);
    cin >> unitprice;
    fflush(stdin);
    gotoXY(148,4);
    cin >> violations;
    fflush(stdin);
    cout<<"\n\n\n\n";
}

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

void inmenu1(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
		gotoXY(2,1);
        cout << "1. Nhap sinh vien";
        gotoXY(2,2);
        cout << "2. Nhap ban quan ly";
        gotoXY(2,3);
        cout << "3. Thoat ";
}

void inmenu2(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
		gotoXY(2,1);
        cout << "1. Enter student";
        gotoXY(2,2);
        cout << "2. Enter manage";
        gotoXY(2,3);
        cout << "3. Exit ";
}

void inmenu3(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
		gotoXY(2,1);
        cout << "1. Sinh vien";
        gotoXY(2,2);
        cout << "2. Ban quan ly";
        gotoXY(2,3);
        cout << "3. Thoat ";
}

void inmenu4(){
	for(int i=0; i <5; i++){
		gotoXY(1,i);
		putchar(219);
	}
	
	for(int i=0; i <5; i++){
		gotoXY(30,i);
		putchar(219);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(220);
	}
		gotoXY(2,1);
        cout << "1. Student";
        gotoXY(2,2);
        cout << "2. Manage";
        gotoXY(2,3);
        cout << "3. Exit ";
}

void inkhung(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(124,i);
		putchar(219);
		gotoXY(134,i);
		putchar(219);
        gotoXY(144,i);
		putchar(219);
        gotoXY(161,i);
		putchar(219);
        gotoXY(177,i);
        putchar(219);
	}

    for(int i=35; i <177; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<" Ho va ten";
	gotoXY(60,2);
	cout<<" Tuoi";
	gotoXY(70,2);
	cout<<" Dia chi";
	gotoXY(85,2);
	cout<<" Ma ID";
	gotoXY(100,2);
	cout<<" CMND/CCCD";
	gotoXY(115,2);
	cout<<" Phong";
	gotoXY(125,2);
	cout<<" Thang";
    gotoXY(135,2);
    cout <<" Don gia";
    gotoXY(145,2);
    cout<<" So lan vi pham";
    gotoXY(162,2);
    cout<<" Tien can dong";
}

void inkhung1(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(129,i);
		putchar(219);
		gotoXY(144,i);
		putchar(219);
        gotoXY(159,i);
		putchar(219);
        gotoXY(175,i);
		putchar(219);
	}

    for(int i=35; i <175; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<" Ho va ten";
	gotoXY(60,2);
	cout<<" Tuoi";
	gotoXY(70,2);
	cout<<" Dia chi";
	gotoXY(85,2);
	cout<<" Ma ID";
	gotoXY(100,2);
	cout<<" So DT";
	gotoXY(115,2);
	cout<<" Tham nien";
	gotoXY(130,2);
	cout<<" He so luong";
    gotoXY(145,2);
    cout <<" Chuc vu";
    gotoXY(160,2);
    cout<<" Tien luong";
}

void inkhung3(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(124,i);
		putchar(219);
		gotoXY(134,i);
		putchar(219);
        gotoXY(147,i);
		putchar(219);
        gotoXY(161,i);
		putchar(219);
        gotoXY(177,i);
        putchar(219);
	}

    for(int i=35; i <177; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<" First and last name";
	gotoXY(60,2);
	cout<<" Age";
	gotoXY(70,2);
	cout<<" Address";
	gotoXY(85,2);
	cout<<" ID code";
	gotoXY(100,2);
	cout<<" Identity card";
	gotoXY(115,2);
	cout<<" Room";
	gotoXY(125,2);
	cout<<" Months";
    gotoXY(135,2);
    cout <<" Unit price";
    gotoXY(148,2);
    cout<<" Violations";
    gotoXY(162,2);
    cout<<"Money to pay";
}

void inkhung4(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(129,i);
		putchar(219);
		gotoXY(144,i);
		putchar(219);
        gotoXY(159,i);
		putchar(219);
        gotoXY(175,i);
		putchar(219);
	}

    for(int i=35; i <175; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<"First and last name";
	gotoXY(60,2);
	cout<<"Age";
	gotoXY(70,2);
	cout<<"Address";
	gotoXY(85,2);
	cout<<"ID code";
	gotoXY(100,2);
	cout<<"Phone";
	gotoXY(115,2);
	cout<<"Seniority";
	gotoXY(130,2);
	cout<<"Coefficients";
    gotoXY(145,2);
    cout <<"Position";
    gotoXY(160,2);
    cout<<"Salary";
}

void giaodien()
{
    system("cls");
    srand(time(NULL));
    SetColor(0, 1 + rand() % 15);
    gotoXY(40,1);
    cout << "      ########     #      #     #       ##       #       #     #      #        #     #  ########  #       #      " << endl;
    gotoXY(40,2);
    cout << "     #        #    #      #    #  #     #  #     #       #       #   #         #   #       #        #   #        " << endl;
    gotoXY(40,3);
    cout << "    #       #  #   #      #   #    #    #    #   #       #         #           # #         #          #          " << endl;
    gotoXY(40,4);
    cout << "     #        #    #      #  ########   #      # #       #         #           #   #       #        #   #        " << endl;
    gotoXY(40,5);
    cout << "      ########  #  ######## #        #  #       ##       #######   #           #     #     #      #       #      " << endl;

    SetColor(0, 2);
    gotoXY(73,8);
        for(int i=0;i<=38;i++){
            putchar(219);
        }
        for(int i=0;i<=10;i++){
            cout<<endl;
            gotoXY(73,8+i);
            putchar(219);
        }
        for(int i=0;i<=36;i++){
            putchar(219);
        }
        for(int i=0;i<=10;i++){
            cout<<endl;
            gotoXY(111,8+i);
            putchar(219);
        }
    gotoXY(80, 11);
    cout << "1. Ngon ngu Tieng Viet" << endl;
    gotoXY(80, 12);
    cout << "2. Language English" << endl;
    gotoXY(80, 13);
    cout << "3. Thoat" << endl;
}

void giaodien2()
{
    for(int i=0; i <13; i++){
		gotoXY(64,i);
		putchar(219);
	}
	
	for(int i=0; i <13; i++){
		gotoXY(120,i);
		putchar(219);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,12);
		putchar(220);
	}

    SetColor(0, 2);
    gotoXY(70,1);
    cout << "Ban da chon ngon ngu Tieng Viet" << endl;
    gotoXY(70,2);
    cout << "1. Nhap thong tin";
    gotoXY(70,3);
    cout << "2. Hien thi thong tin";
    gotoXY(70,4);
    cout << "3. Sap xep theo ten";
    gotoXY(70,5);
    cout << "4. Tim kiem theo tinh";
    gotoXY(70,6);
    cout << "5. Cap nhat thong tin theo ID";
    gotoXY(70,7);
    cout << "6. Xoa theo ID";
    gotoXY(70,8);
    cout << "7. Tim kiem theo ID";
    gotoXY(70,9);
    cout << "8. Tinh tong tien";
    gotoXY(70,10);
    cout << "9. Thoat ";
    gotoXY(70,15);
    cout << " Nhap lua chon: ";
}

void giaodien3()
{
    for(int i=0; i <13; i++){
		gotoXY(64,i);
		putchar(219);
	}
	
	for(int i=0; i <13; i++){
		gotoXY(120,i);
		putchar(219);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,12);
		putchar(220);
	}

    SetColor(0, 2);
    gotoXY(70,1);
    cout << "You have selected the English language" << endl;
    gotoXY(70,2);
    cout << "1. Enter information";
    gotoXY(70,3);
    cout << "2. Display information";
    gotoXY(70,4);
    cout << "3. Sort by name";
    gotoXY(70,5);
    cout << "4. Search by address";
    gotoXY(70,6);
    cout << "5. Update by ID";
    gotoXY(70,7);
    cout << "6. Delete by ID";
    gotoXY(70,8);
    cout << "7. Search by ID";
    gotoXY(70,9);
    cout << "8. Total Money";
    gotoXY(70,10);
    cout << "9. Exit ";
    gotoXY(70,15);
    cout <<  "Enter Choose: ";
}

class Dormitory
{
private:
    vector<Person *> list_person;

public:
    Dormitory();
    ~Dormitory();
    void Nhap();
    void Xuat();
    void input();
    void output();
    friend void inkhung();
    friend void inmenu1();
    friend void inkhung1();
    friend void inmenu2();
    friend void inkhung3();
    friend void inmenu3();
    friend void inkhung4();
    friend void inmenu4();
    void sapxepName();
    void SortName();
    void capnhatThongtin();
    void capnhatID();
    void updateID();
    void timkiemAddress();
    void findAddress();
    void timkiemID();
    void findID();
    void xoaID();
    void deleteID();
    void TongTien();
    void TotalMoney();
};

Dormitory::Dormitory()
{
}

Dormitory::~Dormitory()
{
}

void Dormitory::Nhap()
{
    int i = 1, Luachon, n;
    inmenu1();
    while (i)
    {
        cout << "\n \n \n   Nhap lua chon: ";
        cin >> Luachon;
        Person *p;
        switch (Luachon)
        {
        case 1:
        {
            system("cls");
            inkhung();
            inmenu1();
            cout << "\n\n\n  Nhap so luong sinh vien: " << endl;    
            cin>>n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Student[n];
                p->Nhap(i);
                p->selection(true);
                list_person.push_back(p);
            }
            break;
        }
        case 2:
        {
            system("cls");
            inkhung1();
            inmenu1();
            cout << "\n\n\n  Nhap so luong quan ly: " << endl;
            cin >> n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Manage[n];
                p->Nhap(i);
                p->selection(false);
                list_person.push_back(p);
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::input()
{
    int i = 1, Selection, n;
    inmenu2();
    while (i)
    {
        cout << "\n \n\n  Enter selection: ";
        cin >> Selection;
        Person *p;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inkhung3();
            inmenu2();
            cout << "\n\n\n  Enter number of students: " << endl;
            cin >> n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Student[n];
                p->Nhap(i);
                p->selection(true);
                list_person.push_back(p);
            }

            break;
        }
        case 2:
        {
            system("cls");
            inkhung4();
            inmenu2();
            cout << "\n\n\n  Enter number of manages: " << endl;
            cin >> n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Manage[n];
                p->Nhap(i);
                p->selection(false);
                list_person.push_back(p);
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::Xuat()
{
    int i = 1, Luachon, n;
    inmenu3();
    while (i)
    {
        cout << "\n \n\n  Nhap lua chon: ";
        cin >> Luachon;
        switch (Luachon)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung1();
                    list_person[i]->Xuat(i);
                }
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::output()
{
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n \n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung3();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung4();
                    list_person[i]->Xuat(i);
                }
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::sapxepName()
{
    for (int i = 0; i < list_person.size() - 1; i++)
    {
        for (int j = list_person.size() - 1; j > i; j--)
        {
            char *name1 = new char[list_person[j]->getName().length()];
            strcpy(name1, list_person[j]->getName().c_str());
            char *name2 = new char[list_person[j - 1]->getName().length()];
            strcpy(name2, list_person[j - 1]->getName().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Person *mtp;
                mtp = list_person[j];
                list_person[j] = list_person[j - 1];
                list_person[j - 1] = mtp;
            }
        }
    }
    int i = 1, Luachon, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Luachon;
        switch (Luachon)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung1();
                    list_person[i]->Xuat(i);
                }
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}
void Dormitory::SortName()
{
    for (int i = 0; i < list_person.size() - 1; i++)
    {
        for (int j = list_person.size() - 1; j > i; j--)
        {
            char *name1 = new char[list_person[j]->getName().length()];
            strcpy(name1, list_person[j]->getName().c_str());
            char *name2 = new char[list_person[j - 1]->getName().length()];
            strcpy(name2, list_person[j - 1]->getName().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Person *mtp;
                mtp = list_person[j];
                list_person[j] = list_person[j - 1];
                list_person[j - 1] = mtp;
            }
        }
    }
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung3();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung4();
                    list_person[i]->Xuat(i);
                }
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}
void Dormitory::timkiemAddress()
{
    int i = 1, Selection, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Nhap dia chi day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  Khong tim duoc theo yeu cau!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Nhap dia chi day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung1();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                    cout << "\n  Khong tim duoc theo yeu cau!!!";
                    break;
                }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::findAddress()
{

    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Enter address to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung3();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Enter address to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung4();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::timkiemID()
{
    int i = 1, Selection, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  Khong tim duoc theo yeu cau!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung1();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  Khong tim duoc theo yeu cau!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::findID()
{
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung3();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung4();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::capnhatThongtin()
{
    int i;
    if (list_person[i]->selection() == true)
    {
        list_person[i]->capnhatThongtin();
    }
    else if ((list_person[i]->selection() == false))
    {
        list_person[i]->capnhatThongtin();
    }
}

void Dormitory::capnhatID()
{

    int i = 1, Selection, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Nhap ID day du de cap nhat: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        inkhung();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Da cap nhat thanh cong!!!" << endl;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID Khong ton tai!!!";
                        break;
                    }
                    
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID Khong ton tai!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID day du de cap nhat: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        inkhung1();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Da cap nhat thanh cong!!!" << endl;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID Khong ton tai!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID Khong ton tai!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::updateID()
{
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << " \n\n\nEnter ID to update: " << endl;
            fflush(stdin);
            gotoXY(2, 6);
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        inkhung3();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Successfully updated!!!" << endl;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << " \n\n\nEnter ID to update: " << endl;
            cin.ignore();
            gotoXY(2, 6);
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        inkhung4();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Successfully updated!!!" << endl;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::xoaID()
{
    int i = 1, luachon, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID de xoa: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Da xoa ID " << xoa << " ra khoi he thong!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID khong ton tai!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID khong ton tai!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  Nhap ID de xoa: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Da xoa ID " << xoa << " ra khoi he thong!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID khong ton tai!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID khong ton tai!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::deleteID()
{
    int i = 1, luachon, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to delete: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Removed ID " << xoa << " from the system!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to delete: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Removed ID " << xoa << " from the system!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
            }
            break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "  Invalid selection !!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::TongTien()
{
    unsigned long int Tongluong = 0;
    unsigned long int Tongphi = 0;
    for (int i = 0; i < list_person.size(); i++)
    {

        if (list_person[i]->selection() == true)
        {
            list_person[i]->tinhtien();
            Tongphi = Tongphi + list_person[i]->getMoney();
        }
        else
        {
            list_person[i]->tinhtien();
            Tongluong = Tongluong + list_person[i]->getMoney();
        }
    }
    gotoXY(70,3);
    cout << "  Tong tien luong quan ly la: " << Tongluong << endl;
    gotoXY(70,4);
    cout << "  Tong tien phi ktx la: " << Tongphi<< endl;
}
void Dormitory::TotalMoney()
{
    unsigned long int Tongluong = 0;
    unsigned long int Tongphi = 0;
    for (int i = 0; i < list_person.size(); i++)
    {

        if (list_person[i]->selection() == true)
        {
            list_person[i]->tinhtien();
            Tongphi = Tongphi + list_person[i]->getMoney();
        }
        else
        {
            list_person[i]->tinhtien();
            Tongluong = Tongluong + list_person[i]->getMoney();
        }
    }
    gotoXY(70,3);
    cout << "  Manager's total salary: " << Tongluong << endl;
    gotoXY(70,4);
    cout << "  Total dormitory rent: " << Tongphi<<endl;
}
void menu()
{

    int chon;
    int i = 1;
    while (i)
    {
        giaodien();
        gotoXY(70,23);
        cout << "  Nhap lua chon: ";
        gotoXY(72,24);
        cin >> chon;
        switch (chon)
        {
        case 1:
        {
            Dormitory p;
            bool check;
            int Luachon, j = 1;
            while (j)
            {
                system("cls");
                giaodien2();
                cin >> Luachon;
                switch (Luachon)
                {
                case 1:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    p.Nhap();
                    check = true;
                    system("cls");
                    break;
                }
                case 2:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.Xuat();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 3:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.sapxepName();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 4:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.timkiemAddress();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 5:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    
                    if (check)
                    {
                        p.capnhatID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 6:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.xoaID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 7:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.timkiemID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 8:
                {
                    system("cls");
                    gotoXY(70,1);
                    cout << "  =======Tong Tien=======" << endl;
                    p.TongTien();
                    system("pause");
                    break;
                }
                case 9:
                {
                    system("cls");
                    j--;
                    break;
                }
                default:
                {
                    cout << "  Lua chon khong hop le!!!" << endl;
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            Dormitory p;
            bool check;
            int Luachon, k = 1;
            
            while (k)
            {
                system("cls");
                giaodien3();
                cin >> Luachon;
                switch (Luachon)
                {
                case 1:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    p.input();
                    check = true;
                    system("cls");
                    break;
                }
                case 2:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.output();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 3:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.SortName();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 4:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.findAddress();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 5:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.updateID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 6:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.deleteID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 7:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.findID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 8:
                {
                    system("cls");
                    gotoXY(70,1);
                    cout << "  =======Total Money=======" << endl;
                    p.TotalMoney();
                    system("pause");
                    break;
                }
                case 9:
                {
                    system("cls");
                    k--;
                    break;
                }

                default:
                {
                    cout << "  Invalid selection!!!" << endl;
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
            cout << "  Nhap sai! Nhap lai" << endl;
            break;
        }
    }
}

void GiaoDien_DangNhap(){
        system("cls");
        SetColor(0, 2);
        gotoXY(75,3);
        for(int i=0;i<35;i++){
            putchar(223);
        }
        for(int i=0;i<=3;i++){
            cout<<endl;
            gotoXY(74,3+i);
            putchar(219);
        }
        for(int i=0;i<=3;i++){
            cout<<endl;
            gotoXY(110,3+i);
            putchar(219);
        }
        gotoXY(79, 4);
        SET_COLOR(6);
        cout<<"DANG NHAP TAI KHOAN QUAN LY";
        SetColor(0, 2);
        gotoXY(73,6);
        for(int i=0;i<=38;i++){
            putchar(219);
        }
        for(int i=0;i<=15;i++){
            cout<<endl;
            gotoXY(73,6+i);
            putchar(219);
        }
        for(int i=0;i<=36;i++){
            putchar(219);
        }
        for(int i=0;i<=15;i++){
            cout<<endl;
            gotoXY(111,6+i);
            putchar(219);
        }
}

int main()
{
    bool logic = true;
    string user = "admin";
    string pass = "123456";
    string u, p;
    do
    {
        GiaoDien_DangNhap();
        gotoXY(79, 8);
        cout << "Tai Khoan/ Account:" << endl;
        gotoXY(79, 9);
        SET_COLOR(11);
        getline(cin, u);
        gotoXY(79, 10);
        SET_COLOR(2);
        cout << "Mat Khau/ Password:" << endl;
        gotoXY(79, 11);
        SET_COLOR(11);
        getline(cin, p);
        if (user != u || pass != p)
        {
            GiaoDien_DangNhap();
            gotoXY(79, 8);
            SET_COLOR(10);
            cout<<"Tai khoan hoac mat khau sai...";
            gotoXY(79, 9);
            cout << "Vui long nhap lai!"<<endl;
            gotoXY(79, 10);
            cout<< "(Please try again)";
            SET_COLOR(2);
            gotoXY(79, 12);
            SET_COLOR(2);
            cout << "Tai Khoan/ Account: " << endl;
            gotoXY(79, 13);
            SET_COLOR(11);
            getline(cin, u);
            gotoXY(79, 14);
            SET_COLOR(2);
            cout << "Mat Khau/ Password:" << endl;
            gotoXY(79, 15);
            SET_COLOR(14);
            getline(cin, p);
        }

    } while (user != u || pass != p);
    gotoXY(76, 17);
    cout << "Dang nhap thanh cong !!";
    gotoXY(76, 18);
    cout << "Nhan 1 phim bat ky de tiep tuc....";
    getch();
    menu();
    return 0;
}