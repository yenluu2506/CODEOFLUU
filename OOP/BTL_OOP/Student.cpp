#include <Windows.h>

#include"Person.cpp"
using namespace std;
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
