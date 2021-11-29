#include <iostream>
#include <string>
#include<string.h>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
// #include "setcolor.h"
#include<conio.h>

using namespace std;

void gotoXY (int x, int y)
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
    }
// void SetColor(int backgound_color, int text_color)
// {
//     HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

//     int color_code = backgound_color * 16 + text_color;
//     SetConsoleTextAttribute(hStdout, color_code);
// }

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

class Person{
    protected:
        string name;
        int age;
        string address;
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
        int numberStudent(int &n);
        int numberManage(int &n);
        virtual void Nhap(int &);
        virtual void Xuat(int &);
        bool selection();
        void selection(bool check);
};
Person::Person(){
    name = "";
    age = 0;
    address = "";
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

}
void Person::Xuat(int &n){
    cout << "Ho va ten: "<< name<<endl;
    cout << "Nam sinh: "<< age<<endl;
    cout << "Dia chi: "<< address<<endl;
}



class Student : public Person {
	protected:
		string id; //mã sinh viên
		string identitycard; //số CMND
		int room; // số phòng ở
		unsigned long int boardingfee; //phí nội trú
		int violations; //số lần vi phạm
	public:
        Student();
        ~Student();
		void setId(string id);
		string getId();
		void setIdentitycard(string identitycar);
		string getIdentitycard();
		void setRoom(int room);
		int getRoom();
		void setBoardingfee(unsigned long int boardingfee);
		double getBoardingfee();
		void setViolations(int violations);
		int getViolations();
        void Nhap(int &n);
        void Xuat(int &n);
        void capnhatSV(int &n);
        
		// void write_file();
		// void read_file(int sv);
		// int count();
		// void list_student();
};
Student::Student(){
    id="";
    identitycard="";
    room = 0;
    boardingfee = 0;
    violations = 0;
}
Student::~Student(){

}
string Student::getId(){
	return id;
}
void Student::setId(string id){
	this->id = id;
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
double Student::getBoardingfee() {
	return boardingfee;
}
void Student::setBoardingfee(unsigned long int boardingfee) {
	this->boardingfee = boardingfee;
}
int Student::getViolations() {
	return violations;
}
void Student::setViolations(int violations) {
	this->violations = violations;
}

void Student::Nhap(int &n){
    Person::Nhap(n);
    cout<<"Nhap ma sinh vien: ";
    getline(cin, id);
	fflush(stdin);
    cout<<"Nhap so CMND: ";
    getline(cin, identitycard);
	fflush(stdin);
    cout<<"Nhap so phong: ";
    cin>>room;
	fflush(stdin);
    cout<<"Nhap tien phong: ";
    cin>>boardingfee;
	fflush(stdin);
    cout<<"Nhap so lan vi pham: ";
    cin>>violations;
	fflush(stdin);
}

void Student::Xuat(int &n){
    Person::Xuat(n);
    cout<<"Ma sinh vien: "<<id<<endl;
    cout<<"So CMND: "<<identitycard<<endl;
    cout<<"So phong: "<<room<<endl;
    cout<<"Tien phong: "<<boardingfee<<endl;
    cout<<"So lan vi pham: "<<violations<<endl;
}
void Student::capnhatSV(int &n){
    Nhap(n);
}
class Manage : public Person{
private:
    unsigned long int salary; //Tiền lương
    string position; //Chức vụ
	string phone; //CMND
public: 
    Manage();
    ~Manage();
    unsigned long int getSalary();
    void setSalary(unsigned long int salary);
    string getPosition();
    void setPosition(string position);
	string getPhone();
	void setPhone(string phone);
    void Nhap(int &n);
    void Xuat(int &n);
    void capnhatMN(int &n);
};
Manage::Manage(){
    salary = 0;
    position = "";
    phone = "";
}
Manage::~Manage(){

}
unsigned long int Manage::getSalary(){
    return salary;
}
void Manage::setSalary(unsigned long int salary){
    this->salary=salary;
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
    cout<<"Nhap so dien thoai: ";
    getline(cin, phone);
	fflush(stdin);
	cout<<"Nhap tien luong: ";
	cin>>salary;
	fflush(stdin);
	cout<<"Nhap chuc vu: ";
	getline(cin,position);
}

void Manage::Xuat(int &n){
    Person::Xuat(n);
    cout<<"So dien thoai: "<<phone<<endl;
    cout<<"Dia chi: "<<address<<endl;
	cout<<"Tien luong: "<<salary<<endl;
	cout<<"Chuc vu: "<<position<<endl;
}
void Manage::capnhatMN(int &n){
    Nhap(n);
}
void inmenu1(){
		gotoXY(2,1);
        cout << "1. Nhap sinh vien"<< endl;
        gotoXY(2,2);
        cout << "2. Nhap ban quan ly"<< endl;
        gotoXY(2,3);
        cout << "3. Thoat "<< endl;
}



void giaodien(){
	while(true){
	system("cls");
	cout<<"   *       *      **      *      *      **      * * * *  * * * *     * * * *  * * * *      **      * * * *  * * * *" <<endl;          
	cout<<"   * *   * *     *  *     * *    *     *  *     *        *           *           *        *  *     *        *      " <<endl;
	cout<<"   *   *   *    * ** *    *   *  *    * ** *    *   * *  * * * *     * * * *     *       * ** *    * * * *  * * * *" <<endl;
	cout<<"   *       *   *      *   *    * *   *      *   *     *  *                 *     *      *      *   *        *      " <<endl;
	cout<<"   *       *  *        *  *      *  *        *  * * * *  * * * *     * * * *     *     *        *  *        *      " <<endl;
    Sleep(99);
        cout << "\n\t\t\t1. Nhap thong tin";
        cout << "\n\t\t\t2. Hien thi thong tin";
        cout << "\n\t\t\t3. Sap xep (theo ten)";
        cout << "\n\t\t\t4. Sap xep (theo msv)";
        cout << "\n\t\t\t5. Thoat ";
        cout << "\n\t\t\t Nhap lua chon: "; 
		break;
  }
}

class Dormitory{
private:
    vector<Person *> list_person;

public:
    Dormitory();
    ~Dormitory();
    void Nhap();
    void Xuat();
    void capnhat();
    void xuatcapnhat();
    friend void inkhung();
    friend void inmenu1();
    void sapxepName();
    void sapxepID();
    void timkiem();
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
            int a = numberStudent(n);
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
            int b= numberManage(n);
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
void Dormitory::sapxepName(){
    for(int i=0;  i<list_person.size()-1  ;  i++){
        for(int j= list_person.size()-1  ;  j>i ;  j--){
            //Tạo biến lưu tên dưới dạng mảng kí tự
            char* name1= new char[list_person[j]->getName().length()];
            strcpy(name1,list_person[j]->getName().c_str());
            char* name2= new char[list_person[j-1]->getName().length()];
            strcpy(name2,list_person[j-1]->getName().c_str());
            //Sắp xếp tên theo mảng kí tự
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
// void Dormitory::sapxepID(){
//     for(int i=0;  i<list_person.size()-1  ;  i++){
//         for(int j= list_person.size()-1  ;  j>i ;  j--){
//             //Tạo biến lưu tên dưới dạng mảng kí tự
//             char* ID1= new char[list_person[j]->getId().length()];
//             strcpy(ID1,list_person[j]->getId().c_str());
//             char* ID2= new char[list_person[j-1]->getId().length()];
//             strcpy(ID2,list_person[j-1]->getId().c_str());
//             //Sắp xếp Id theo mảng kí tự
//             if(strcmp(ID1,ID2)<0){
//                 Student * mtp;
//                 mtp = list_student[j];
//                 list_student[j]=list_student[j-1];
//                 list_student[j-1] = mtp;
//             }
//         }
//     }
//     for (int i = 0; i < list_person.size(); i++){
    	
//         if (list_person[i]->selection() == true)
//             list_person[i]->Xuat(i);
        
//     }
//     for (int i = 0; i < list_student.size(); i++){
        
		
// 		if (list_student[i]->selection() == false)
//             list_student[i]->Xuat(i);
        
//     }
// }



int main()
{
    Dormitory p;
    bool check;
    int Luachon;
    while (true){ 
        giaodien();
        cin >> Luachon;
        system("Color 71");
        switch (Luachon){
        case 1:{
        	system("cls");
        	// inkhung1();
            p.Nhap();
            check = true;
            break;
        }
        case 2:{
            if (check){
                p.Xuat();
                system("pause");
            }
            else{
                cout << "Ban chua nhap thong tin vao!" << endl;
                system("pause");
            }
            break;
        }
        case 3:{
            cout << "\t\t sap xep sinh vien theo ten: " << endl;
            p.sapxepName();
            //p.Xuat();
            system("pause");
            break;
        }
        case 4:{
            cout << "\t\t sap xep sinh vien theo id: " << endl;
            p.sapxepID();
            //p.Xuat();
            system("pause");
            break;
        }
        case 5:{
            system("cls");
            cout << "\t\tTam biet!!!" << endl;
            cout << "\t";
            system("pause");
            exit(0);
        }
        default:{
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
    }
}
    system("pause");  
    return 0; 
}