#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <string.h>
// #include <vector>
#include <Windows.h>
// #include <cstdlib>
// #include <ctime>
// #include <math.h>
// //#include "setcolor.h"
// #include <conio.h>
// #include <fstream>
// #include <cstdlib>
// #include <unistd.h>
// #include <chrono>
// #include <thread>
// #include <tr1/regex>

using namespace std;

void gotoXY (int x, int y)
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
    }
 void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
// int inputKey()
// {
// 	if (_kbhit())
// 	{
// 		int key = _getch();

// 		if (key == 224)	// special key
// 		{
// 			key = _getch();
// 			return key + 1000;
// 		}

// 		return key;
// 	}
// 	else
// 	{
// 		return key_none;
// 	}

// 	return key_none;
// }
// void gotoXY (int column, int line)
// {
// 	COORD coord;
// 	coord.X = column;
// 	coord.Y = line;
// 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
// }


int numberStudent(int &n){
	cout << "Enter number of students: " << endl;
	cin >> n;
    return n;
}
int numberManage(int &n){
	cout << "Enter number of manages: "<< endl;
	cin >> n;
    return n;
}

int SoluongSinhvien(int &n){
	cout << "Nhap so luong sinh vien: " << endl;
	cin >> n;
    return n;
}
int SoluongQuanly(int &n){
	cout << "Nhap so luong quan ly: "<< endl;
	cin >> n;
    return n;
}

class Person{
    protected:
        string name;
        int age;
        string address;
		string id; //mÃƒÂ£ sinh viÃƒÂªn
        double money;
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
        int numberStudent(int &n);
        int numberManage(int &n);
        int SoluongSinhvien(int &n);
        int SoluongQuanly(int &n);
        virtual void Nhap(int &);
        virtual void Xuat(int &);
        virtual void input(int &);
        virtual void output(int &);
        virtual void capnhatThongtin();
        virtual void updateInformation();
        virtual void tinhtien() = 0;
        double getMoney(){
            return money;
        }
        bool selection();
        void selection(bool check);
};
Person::Person(){
    name = "";
    age = 0;
    address = "";
    money = 0;
}
Person::~Person(){

}
bool Person::selection(){
    return this->check;
}
void Person::selection(bool check){
    this->check = check;
}
string Person::getName(){
	return name;
}
void Person::setName(string name){
    this->name = name;
}
int Person::getAge(){
    return age;
}
void Person::setAge(int age){
	this->age = age;
}
string Person::getAddress(){
    return address;
}
void Person::setAddress(string address){
    this->address = address;
}

string Person::getId(){
	return id;
}
void Person::setId(string id){
	this->id = id;
}
void Person::Nhap(int &n){
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    getline(cin, name);
    cout << "Nhap tuoi: ";
    fflush(stdin);
    cin >> age;
    cout << "Nhap dia chi: ";
    fflush(stdin);
    getline(cin, address);
    cout<<"Nhap ma ID: ";
    getline(cin, id);
	fflush(stdin);
}

void Person::input(int &n){
    cout << "Enter first and last name: ";
    fflush(stdin);
    getline(cin, name);
    cout << "Enter age: ";
    fflush(stdin);
    cin >> age;
    cout << "Enter address: ";
    fflush(stdin);
    getline(cin, address);
    cout<<"Enter ID code: ";
    getline(cin, id);
	fflush(stdin);
}

void Person::Xuat(int &n){
    cout << "Ho va ten: "<< name<<endl;
    cout << "Nam sinh: "<< age<<endl;
    cout << "Dia chi: "<< address<<endl;
    cout<<"Ma ID: "<<id<<endl;
}

void Person::output(int &n){
    cout << "First and last name: "<< name<<endl;
    cout << "Age: "<< age<<endl;
    cout << "Address: "<< address<<endl;
    cout<<"ID code: "<<id<<endl;
}

void Person::capnhatThongtin(){
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    getline(cin, name);
    cout << "Nhap tuoi: ";
    fflush(stdin);
    cin >> age;
    cout << "Nhap dia chi: ";
    fflush(stdin);
    getline(cin, address);
}

void Person::updateInformation(){
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    getline(cin, name);
    cout << "Nhap tuoi: ";
    fflush(stdin);
    cin >> age;
    cout << "Nhap dia chi: ";
    fflush(stdin);
    getline(cin, address);
}

class Student : public Person {
    private:
		string identitycard; //sÃ¡Â»â€˜ CMND
		int room; // sÃ¡Â»â€˜ phÃƒÂ²ng Ã¡Â»Å¸
		double unitprice; //dÃ†Â¡n gia
		int violations; //sÃ¡Â»â€˜ lÃ¡ÂºÂ§n vi phÃ¡ÂºÂ¡m
        double months; //sÃ¡Â»â€˜ thÃƒÂ¡ng Ã¡Â»Å¸
	public:
        Student();
        ~Student();
		void setIdentitycard(string identitycar);
		string getIdentitycard();
		void setRoom(int room);
		int getRoom();
		void setUnitprice (unsigned long int unitprice);
		double getUnitprice();
		void setViolations(int violations);
		int getViolations();
        double getMonths();
        void setMonths(double months);
        void Nhap(int &n);
        void Xuat(int &n);
        void input(int &n);
        void output(int &n);
        void tinhtien(){
            this->money = this->months*this->unitprice;
        }
        void capnhatThongtin();
        void updateInformation();
};
Student::Student(){
    id="";
    identitycard="";
    room = 0;
    unitprice = 0;
    violations = 0;
    months = 0;
}
Student::~Student(){

}
string Student::getIdentitycard() {
	return identitycard;
}
void Student::setIdentitycard(string identitycard) {
	this->identitycard = identitycard;
}
int Student::getRoom() {
	return room;
}
void Student::setRoom(int room) {
	this->room = room;
}
double Student::getMonths(){
    return months;
}
void Student::setMonths(double months){
    this->months = months;
}
double Student::getUnitprice() {
	return unitprice;
}
void Student::setUnitprice(unsigned long int unitprice) {
	this->unitprice = unitprice;
}
int Student::getViolations() {
	return violations;
}
void Student::setViolations(int violations) {
	this->violations = violations;
}
void Student::Nhap(int &n){
    Person::Nhap(n);
    // cout<<"Nhap ma sinh vien: ";
    // getline(cin,id);
    // fflush(stdin);
    cout<<"Nhap so CMND: ";
    getline(cin, identitycard);
	fflush(stdin);
    cout<<"Nhap so phong: ";
    cin>>room;
	fflush(stdin);
    cout << "Nhap so thang: ";
    cin >> months;
    fflush(stdin);
    cout<<"Nhap don gia: ";
    cin>>unitprice;
	fflush(stdin);
    cout<<"Nhap so lan vi pham: ";
    cin>>violations;
	fflush(stdin);
}

void Student::input(int &n){
    Person::input(n);
    // cout<<"Emter your Student code: ";
    // getline(cin,id);
    cout<<"Enter your identity card number: ";
    getline(cin, identitycard);
	fflush(stdin);
    cout<<"Enter room number: ";
    cin>>room;
	fflush(stdin);
    cout << "Enter number months: ";
    cin >> months;
    fflush(stdin);
    cout<<"Enter unit price: ";
    cin>>unitprice;
	fflush(stdin);
    cout<<"Enter the number of violations: ";
    cin>>violations;
	fflush(stdin);
}

void Student::output(int &n){
    Person::output(n);
    cout<<"Identity card number: "<<identitycard<<endl;
    cout<<"Room number: "<<room<<endl;
    cout<<"Months number: "<< months<< endl;
    cout<<"Unit price: "<<unitprice<<endl;
    cout<<"The number of violations: "<<violations<<endl;
    this->tinhtien();
    cout<<"Boarding fee: "<< money << endl;
}

void Student::Xuat(int &n){
    Person::Xuat(n);
    cout<<"So CMND: "<<identitycard<<endl;
    cout<<"So phong: "<<room<<endl;
    cout<<"So thang: "<< months<< endl;
    cout<<"Don gia: "<<unitprice<<endl;
    cout<<"So lan vi pham: "<<violations<<endl;
    this->tinhtien();
    cout<<"So tien can dong noi tru: "<< money << endl;
}

void Student::capnhatThongtin(){
    Person::capnhatThongtin();
    cout<<"Nhap so CMND: ";
    getline(cin, identitycard);
	fflush(stdin);
    cout<<"Nhap so phong: ";
    cin>>room;
	fflush(stdin);
    cout << "Nhap so thang: ";
    cin >> months;
    fflush(stdin);
    cout<<"Nhap don gia: ";
    cin>>unitprice;
	fflush(stdin);
    cout<<"Nhap so lan vi pham: ";
    cin>>violations;
	fflush(stdin);
}

void Student::updateInformation(){
    Person::updateInformation();
    cout<<"Enter Identity card number: ";
    getline(cin, identitycard);
	fflush(stdin);
    cout<<"Enter Room number: ";
    cin>>room;
	fflush(stdin);
    cout << "Enter Months number: ";
    cin >> months;
    fflush(stdin);
    cout<<"Enter Unit price: ";
    cin>>unitprice;
	fflush(stdin);
    cout<<"The number of violations: ";
    cin>>violations;
	fflush(stdin);
}

class Manage : public Person{
private:
    double coefficientssalary; //TiÃ¡Â»Ân lÃ†Â°Ã†Â¡ng
    string position; //ChÃ¡Â»Â©c vÃ¡Â»Â¥
	string phone; //CMND
    double seniority; //thÃƒÂ¢m niÃƒÂªn
public: 
    Manage();
    ~Manage();
    unsigned long int getCoefficientssalary();
    void setCoefficientssalary(unsigned long int coefficientssalary);
    string getPosition();
    void setPosition(string position);
	string getPhone();
	void setPhone(string phone);
    void tinhtien(){
        money = coefficientssalary*1600 + seniority*500;
    }
    void Nhap(int &n);
    void Xuat(int &n);
    void input(int &n);
    void output(int &n);
    void capnhatThongtin();
    void updateInformation();
};
Manage::Manage(){
    seniority = 0;
    position = "";
    phone = "";
    coefficientssalary = 0;
}
Manage::~Manage(){

}
unsigned long int Manage::getCoefficientssalary(){
    return coefficientssalary;
}
void Manage::setCoefficientssalary(unsigned long int coefficientssalary){
    this->coefficientssalary=coefficientssalary;
}
string Manage::getPosition(){
    return position;
}
void Manage::setPosition(string position){
    this->position=position;
}

string Manage::getPhone(){
	return phone;
}
void Manage::setPhone(string phone){
	this->phone=phone;
}

void Manage::Nhap(int &n){
    Person::Nhap(n);
    // cout<<"Nhap ma quan ly: ";
    // getline(cin,id);
    // fflush(stdin);
    cout<<"Nhap so dien thoai: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Nhap tham nien: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Nhap he so luong: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Nhap chuc vu: ";
	getline(cin,position);
}

void Manage::input(int &n){
    Person::input(n);
    // cout<<"Enter Manage code: ";
    // getline(cin,id);
    // fflush(stdin);
    cout<<"Enter your phone number: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Enter seniority: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Enter salary: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Enter position: ";
	getline(cin,position);
}

void Manage::Xuat(int &n){
    Person::Xuat(n);
    cout<<"So dien thoai: "<<phone<<endl;
    cout<<"Tham nien: "<< seniority<< endl;
	cout<<"He so luong: "<<coefficientssalary<<endl;
	cout<<"Chuc vu: "<<position<<endl;
    this->tinhtien();
    cout<<"Luong: "<< money<< endl;
}

void Manage::output(int &n){
    Person::output(n);
    cout<<"Phone number: "<<phone<<endl;
    cout<<"Seniority: "<< seniority<< endl;
	cout<<"Salary: "<<coefficientssalary<<endl;
	cout<<"Position: "<<position<<endl;
    this->tinhtien();
    cout<<"Salary: "<< money<< endl;
}

void Manage::capnhatThongtin(){
    Person::capnhatThongtin();
    cout<<"Nhap so dien thoai: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Nhap tham nien: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Nhap he so luong: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Nhap chuc vu: ";
	getline(cin,position);
}

void Manage::updateInformation(){
    Person::updateInformation();
    cout<<"Enter your phone number: ";
    getline(cin, phone);
	fflush(stdin);
    cout<<"Enter seniority: ";
    cin>>seniority;
    fflush(stdin);
	cout<<"Enter salary: ";
	cin>>coefficientssalary;
	fflush(stdin);
	cout<<"Enter position: ";
	getline(cin,position);
}

void inmenu1(){
	SetColor(0,2);
	gotoXY(2,1);
    cout << "1. Nhap sinh vien"<< endl;
    gotoXY(2,2);
    cout << "2. Nhap ban quan ly"<< endl;
    gotoXY(2,3);
    cout << "3. Thoat "<< endl;
}

void inmenu2(){
	SetColor(0,2);
	gotoXY(2,1);
    cout << "1. Enter student"<< endl;
    gotoXY(2,2);
    cout << "2. Enter manage"<< endl;
    gotoXY(2,3);
    cout << "3. Exit "<< endl;
}

void giaodien(){
	system("cls");
	srand(time(NULL));
	SetColor(0, 1+rand()%15);
    cout<<"      ********     *    *     *       **      *       *     *      *        *     *  ********  *       *      "<<endl;
	cout<<"     *        *    *    *    *  *     *  *    *       *       *   *         *   *       *        *   *        "<<endl;
	cout<<"    *       *  *   *    *   *    *    *    *  *       *         *           * *         *          *          "<<endl;
	cout<<"     *        *    *    *  ********   *      **       *         *           *   *       *        *   *        "<<endl;
	cout<<"      ********  *  ****** *        *  *       *       *******   *           *     *     *      *       *      "<<endl;
    // sleep(0);
    SetColor(0,2);
    gotoXY(40, 5);
    cout << "1. Ngon ngu Tieng Viet"<< endl;
    gotoXY(40, 6);
    cout << "2. Language English"<< endl;
    gotoXY(40, 7);
    cout << "3. Thoat"<< endl;

}

void giaodien2(){
	SetColor(0,2);
    cout << "Ban da chon ngon ngu Tieng Viet"<< endl;
    cout << "\n\t\t\t1. Nhap thong tin";
    cout << "\n\t\t\t2. Hien thi thong tinh";
    cout << "\n\t\t\t3. Sap xep theo ten";
    cout << "\n\t\t\t4. Tim kiem theo tinh";
    cout << "\n\t\t\t5. Cap nhat thong tin theo ID";
    cout << "\n\t\t\t6. Xoa theo ID";
    cout << "\n\t\t\t7. Tim kiem theo ID";
    cout << "\n\t\t\t8. Tinh tong tien";
    cout << "\n\t\t\t9. Thoat ";
    cout << "\n\t\t\t Nhap lua chon: ";
}

void giaodien3(){
	SetColor(0,2);
    cout << "You have selected the English language"<< endl;
    cout << "\n\t\t\t1. Enter information";
    cout << "\n\t\t\t2. Display information";
    cout << "\n\t\t\t3. Sort by name";
    cout << "\n\t\t\t4. Search by address";
    cout << "\n\t\t\t5. Update by ID";
    cout << "\n\t\t\t6. Delete by ID";
    cout << "\n\t\t\t7. Search by ID";
    cout << "\n\t\t\t8. Total Money";
    cout << "\n\t\t\t9. Exit ";
    cout << "\n\t\t\t Enter Choose: ";
}

class Dormitory{
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
    void sapxepName();
    void SortName();
    void capnhatThongtin();
    void updateInformation();
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
    void write_file();
    void read_file();
};

Dormitory::Dormitory(){
}

Dormitory::~Dormitory(){
}

void Dormitory::Nhap(){
    int i=1, Luachon, n;
        inmenu1();
         while (i)
    {
        cout << "\n \n   Nhap lua chon: ";
        cin >> Luachon;
        Person *p;
        switch (Luachon)
        {
        case 1:  
		  {
            system("cls");
        	inmenu1();
            int a = SoluongSinhvien(n);
            for(int i=0; i<a; i++){
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
            inmenu1();
            int b= SoluongQuanly(n);
            for(int i=0; i<b; i++){
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
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::input(){
    int i=1, Selection , n;
        inmenu2();
         while (i)
    {
        cout << "\n \n  Enter selection: ";
        cin >> Selection;
        Person *p;
        switch (Selection)
        {
        case 1:  
		  {
            system("cls");
        	inmenu2();
            int a = numberStudent(n);
            for(int i=0; i<a; i++){
            p = new Student[n];
            p->input(i);
            p->selection(true);
            list_person.push_back(p);
            }
            
            break;
        }
        case 2:
        {   
            system("cls");
            inmenu2();
            int b= numberManage(n);
            for(int i=0; i<b; i++){
            p = new Manage[n];
            p->input(i);
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
            cout << "Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::Xuat(){   
    system("cls");
	// inkhung();
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->Xuat(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->Xuat(i);
    }
}

void Dormitory::output(){   
    system("cls");
	// inkhung();
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->output(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->output(i);
    }
}

void Dormitory::sapxepName(){
    for(int i=0;  i<list_person.size()-1  ;  i++){
        for(int j= list_person.size()-1  ;  j>i ;  j--){
            //TÃ¡ÂºÂ¡o biÃ¡ÂºÂ¿n lÃ†Â°u tÃƒÂªn dÃ†Â°Ã¡Â»â€ºi dÃ¡ÂºÂ¡ng mÃ¡ÂºÂ£ng kÃƒÂ­ tÃ¡Â»Â±
            char* name1= new char[list_person[j]->getName().length()];
            strcpy(name1,list_person[j]->getName().c_str());
            char* name2= new char[list_person[j-1]->getName().length()];
            strcpy(name2,list_person[j-1]->getName().c_str());
            //SÃ¡ÂºÂ¯p xÃ¡ÂºÂ¿p tÃƒÂªn theo mÃ¡ÂºÂ£ng kÃƒÂ­ tÃ¡Â»Â±
            if(strcmp(name1,name2)<0){
                Person * mtp;
                mtp = list_person[j];
                list_person[j]=list_person[j-1];
                list_person[j-1] = mtp;
            }
        }
    }
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->Xuat(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->Xuat(i);
        
    }
}
void Dormitory::SortName(){
    for(int i=0;  i<list_person.size()-1  ;  i++){
        for(int j= list_person.size()-1  ;  j>i ;  j--){
            //TÃ¡ÂºÂ¡o biÃ¡ÂºÂ¿n lÃ†Â°u tÃƒÂªn dÃ†Â°Ã¡Â»â€ºi dÃ¡ÂºÂ¡ng mÃ¡ÂºÂ£ng kÃƒÂ­ tÃ¡Â»Â±
            char* name1= new char[list_person[j]->getName().length()];
            strcpy(name1,list_person[j]->getName().c_str());
            char* name2= new char[list_person[j-1]->getName().length()];
            strcpy(name2,list_person[j-1]->getName().c_str());
            //SÃ¡ÂºÂ¯p xÃ¡ÂºÂ¿p tÃƒÂªn theo mÃ¡ÂºÂ£ng kÃƒÂ­ tÃ¡Â»Â±
            if(strcmp(name1,name2)<0){
                Person * mtp;
                mtp = list_person[j];
                list_person[j]=list_person[j-1];
                list_person[j-1] = mtp;
            }
        }
    }
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true)
            list_person[i]->output(i);
        
    }
    for (int i = 0; i < list_person.size(); i++){
        
		
		if (list_person[i]->selection() == false)
            list_person[i]->output(i);
        
    }
}
void Dormitory::timkiemAddress(){
    int dem = 0;
    string timkiem;
    cout << "Nhap dia chi day du de tim: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getAddress())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "Sinh vien!\n\n " << endl;
            else
                cout << "Ban quan ly!\n\n " << endl;
            // inkhung();
            list_person[i]->Xuat(i);
        }
    }
    if (dem == 0)
        cout << "\nKhong tim duoc theo yeu cau!!!\n\n" << endl;
}

void Dormitory::findAddress(){
    int dem = 0;
    string timkiem;
    cout << "Enter the full address to search: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getAddress())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "Student!\n\n " << endl;
            else
                cout << "Manage!\n\n " << endl;
            // inkhung();
            list_person[i]->output(i);
        }
    }
    if (dem == 0)
        cout << "\nThe request could not be found!!!\n\n" << endl;
}

void Dormitory::timkiemID(){
    int dem = 0;
    string timkiem;
    cout << "Nhap dia chi day du de tim: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getId())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "\nSinh vien!\n " << endl;
            else
                cout << "\nBan quan ly!\n " << endl;
            // inkhung();
            list_person[i]->Xuat(i);
        }
    }
    if (dem == 0)
        cout << "\nKhong tim duoc theo yeu cau!!!\n\n" << endl;
}

void Dormitory::findID(){
    int dem = 0;
    string timkiem;
    cout << "Enter the full ID to search: " << endl;
    cin.ignore();
    getline(cin, timkiem);
    for (int i = 0; i < list_person.size(); i++)
    {
        if (timkiem == list_person[i]->getId())
        {
            dem++;
            if (list_person[i]->selection())
                cout << "\nStudent!\n " << endl;
            else
                cout << "\nManage!\n " << endl;
            // inkhung();
            list_person[i]->output(i);
        }
    }
    if (dem == 0)
        cout << "\nThe request could not be found!!!\n\n" << endl;
}

void Dormitory::capnhatThongtin(){
    int i;
        if(list_person[i]->selection()==true){
            list_person[i]->capnhatThongtin();
        }
        else if ((list_person[i]->selection()==false)){
            list_person[i]->capnhatThongtin();
        }
}

void Dormitory::updateInformation(){
    int i;
        if(list_person[i]->selection()==true){
            list_person[i]->updateInformation();
        }
        else if ((list_person[i]->selection()==false)){
            list_person[i]->updateInformation();
        }
}

void Dormitory::capnhatID(){
    int found=0;
    string timkiem;
    cout << "Nhap ID day du de cap nhat: ";
    fflush(stdin);
    getline(cin, timkiem);
    for(int i=0;i<=list_person.size()-1;i++){
        if(timkiem==list_person[i]->getId()){
            found = 1;
            cout << "Cap nhat thong tin co ID: " << timkiem << endl;
            capnhatThongtin();
            break;
        }
    }
    if(found == 0){
        cout << "Khong ton tai!"<< endl;
    }
}

void Dormitory::updateID(){
    int found=0;
    string find;
    cout << "Enter the full ID to update: ";
    fflush(stdin);
    getline(cin, find);
    for(int i=0;i<=list_person.size()-1;i++){
        if(find==list_person[i]->getId()){
            found = 1;
            cout << "Update information with ID " << find << endl;
            updateInformation();
            break;
        }
    }
    if(found == 0){
        cout << "ID does not exist!"<< endl;
    }
}

void Dormitory::xoaID(){
    int found = 0;
    string xoa;
    cout << "Nhap ID day du de xoa: ";
    cin.ignore();
    getline(cin, xoa);
    for (int i = 0; i <= list_person.size()-1; i++){
        if (xoa == list_person[i]->getId()){
            found = 1;
            list_person.erase(list_person.begin()+i);
            cout << "\nDa xoa ID " << xoa << " ra khoi he thong!!!"<< endl;
            break;
        }
    }
    if(found == 0){
        cout << "ID khong ton tai!!!"<< endl;
    }
}

void Dormitory::deleteID(){
    int found = 0;
    string xoa;
    cout << "Enter the full ID to delete: ";
    cin.ignore();
    getline(cin, xoa);
    for (int i = 0; i <= list_person.size()-1; i++){
        if (xoa == list_person[i]->getId()){
            found = 1;
            list_person.erase(list_person.begin()+i);
            cout << "\nRemoved ID " << xoa << " from the system!!!"<< endl;
            break;
        }
    }
    if(found == 0){
        cout << "ID does not exist!!!"<< endl;
    }
}

void Dormitory::TongTien(){
    unsigned long int Tongluong=0;
    unsigned long int Tongphi=0;
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true){
            //list_person[i]->Xuat(i);
            list_person[i]->tinhtien();
            Tongphi=Tongphi+list_person[i]->getMoney();
        }else{
            list_person[i]->tinhtien();
            Tongluong=Tongluong+list_person[i]->getMoney();
        }
    }
    cout<<"Tong tien luong quan ly la: "<<Tongluong<<endl;
    cout<<"Tong tien phi ktx la: "<<Tongphi;
}
void Dormitory::TotalMoney(){
    unsigned long int Tongluong=0;
    unsigned long int Tongphi=0;
    for (int i = 0; i < list_person.size(); i++){
    	
        if (list_person[i]->selection() == true){
            //list_person[i]->Xuat(i);
            list_person[i]->tinhtien();
            Tongphi=Tongphi+list_person[i]->getMoney();
        }
        else{
            list_person[i]->tinhtien();
            Tongluong=Tongluong+list_person[i]->getMoney();
        }    
    }
    cout<<"Manager's total salary: "<<Tongluong<<endl;
    cout<<"Total dormitory rent: "<<Tongphi;
}
// void Dormitory::write_file(){
//     fstream f; 
//     f.open("sinhvien.dat", ios::binary|ios::app|ios::out);
//     f.write((char*)this, sizeof(*this));
//     f.close();
// }
// void Dormitory::read_file(){
//     fstream f;
//     f.open("sinhvien.dat",ios::binary|ios::in);
//     f.seekg(* sizeof(Dormitory));
//     f.read((char*)this,sizeof(*this));
//     f.close();
// }
void menu(){
	
    giaodien();
    int chon;
    int i=1;
    cout << "Nhap lua chon: ";
    cin >> chon;
    while(i){
    switch (chon){
        case 1:{ 
            Dormitory p;
            bool check;
            int Luachon, i=1; 
            giaodien2();
            while (i){
            cin >> Luachon;
            system("Color 71");
            switch (Luachon){
            case 1:{
                system("cls");
                giaodien2();
                system("cls");
                p.Nhap();
                check = true;
                system("cls");
                break;
            }
            case 2:{
                
                if (check){
					// system("cls");
					giaodien2();
					// system("cls");
                    p.Xuat();
                    system("pause");
                    system("cls");
                }
                else{
                    cout << "Ban chua nhap thong tin vao!" << endl;
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 3:{
                system("cls");
                giaodien2();
                // system("cls");
                if(check){
                    cout << "\t\t Sap xep theo ten: " << endl;
                    p.sapxepName();
                    system("pause");
                    system("cls");
                }
                else{
                    cout << "Ban chua nhap thong tin vao!" << endl;
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 4:{
                system("cls");
                giaodien2();
                // system("cls");
                cout << "\t\t Tim kiem theo tinh: " << endl;
                p.timkiemAddress();
                system("pause");
                break;
            }
            case 5:{
                system("cls");
                giaodien2();
                // system("cls");
                cout << "\t\t Cap nhat theo ID: " << endl;
                p.capnhatID();
                system("pause");
                break;
            }
            case 6:{
                system("cls");
                giaodien2();
                // system("cls");
                cout << "Xoa ID: "<< endl;
                p.xoaID();
                system("pause");
                break;
            }
            case 7:{
                system("cls");
                giaodien2();
                // system("cls");
                cout << "\t\t Tim kiem theo ID: " << endl;
                p.timkiemID();
                system("pause");
                break;
            }
            case 8:{
                system("cls");
				giaodien2();
                cout<<"=======Tong Tien======="<<endl;
                p.TongTien();
                system("pause");
                break;
            }
            case 9:{
                 system("cls");
                 cout << "\t\tTam biet!!!" << endl;
                 cout << "\t";
                 system("pause");
                 break;
            }
            default:{
                cout << "Lua chon khong hop le!!!" << endl;
                break;
            }
            }
            }
            system("pause");
           
        }
        case 2:{
            Dormitory p;
            bool check;
            int Luachon, i=1;
                giaodien3();
            while (i){
                cin >> Luachon;
                system("Color 71");
                switch (Luachon){
                case 1:{
                    system("cls");
                    giaodien3();
                    system("cls");
                    p.input();
                    check = true;
                    break;
                }
                case 2:{
                    system("cls");
                    giaodien3();
                    if (check){
                        p.output();
                        system("pause");
                    }
                    else{
                        cout << "You have not entered information!" << endl;
                        system("pause");
                    }
                    break;
                }
                case 3:{
                    system("cls");
                    giaodien3();
                    cout << "\t\tSort by Name: " << endl;
                    p.SortName();
                    system("pause");
                    break;
                }
                case 4:{
                    system("cls");
                    giaodien3();
                    cout << "\t\t Search by province: " << endl;
                    p.findAddress();
                    system("pause");
                    break;
                }
                case 5:{
                    system("cls");
                    giaodien3();
                    cout << "\t\t Update by ID: " << endl;
                    p.updateID();
                    system("pause");
                    break;
                }
                case 6:{
                    system("cls");
                    giaodien3();
                    cout << "Delete by ID: "<< endl;
                    p.deleteID();
                    system("pause");
                    break;
                }
                case 7:{
                    system("cls");
                    giaodien3();
                    cout << "\t\t Search by ID: " << endl;
                    p.findID();
                    system("pause");
                    break;
                }
                case 8:{
                    system("cls");
                    cout<<"=======Total Money======="<<endl;
                    p.TotalMoney();
                    system("pause");
                    break;
                }
                case 9:{
                    system("cls");
                    cout << "\t\tTam biet!!!" << endl;
                    cout << "\t";
                    system("pause");
                    break;
                }

                default:{
                    cout << "Invalid selection!!!" << endl;
                    break;
                }
                }
            }
            break;
            giaodien();
        }
        case 3:{
            i--;
            break;
        }
        default:
            cout << "Nhap sai! Nhap lai"<< endl;
            break;
        }
    }
}
int main(){
    SetColor(0,2);
	bool logic = true;
	string user="admin";
	string pass="123456";
	string u, p;
    gotoXY(40, 8);
	cout<<"Tai Khoan/ Account:"<<endl;
    gotoXY(40, 9);
	getline(cin,u);
    gotoXY(40, 10);
	cout<<"Mat Khau/ Password:"<<endl;
    gotoXY(40, 11);
	getline(cin,p);
	while(logic == true){
		if ((user!=u) || (pass!=p)){
            gotoXY(40, 12);
            cout<<"Vui long nhap lai!/ Please try again!";
            gotoXY(40, 13);
			cout<<"Tai Khoan/ Account: "<<endl;
            gotoXY(40, 14);
			cout<<"Mat Khau/ Password:"<<endl;
            gotoXY(40, 15);
			getline(cin,u);
            gotoXY(40, 16);
			cout<<"moi ban nhap pass"<<endl;
            gotoXY(40, 17);
		    getline(cin,p);
			continue;	
		}
		else{
			cout<<"Dang nhap thanh cong"<<endl;
			menu();
		}
		
	}
    system("pause");  
    return 0; 
}