#include <iostream>
#include <string>
#include<string.h>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "setcolor.h"
#include<conio.h>

using namespace std;

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


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
	private:
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
	for(int i=1; i <5; i++){
		gotoXY(1,i);
		putchar(179);
	}
	
	for(int i=1; i <5; i++){
		gotoXY(30,i);
		putchar(179);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,0);
		putchar(95);
	}
	for(int i=2; i <30; i++){
		gotoXY(i,4);
		putchar(95);
	}
	// in menu o lua chon 1
		gotoXY(2,1);
        cout << "1. Nhap sinh vien"<< endl;
        gotoXY(2,2);
        cout << "2. Nhap ban quan ly"<< endl;
        gotoXY(2,3);
        cout << "3. Thoat "<< endl;
}

void inkhung1(){
//in bien doc
    for(int i=1; i <25; i++){
		gotoXY(35,i);
		putchar(179);
		gotoXY(115,i);
		putchar(179);
		gotoXY(58,i);
		putchar(179);
		gotoXY(68,i);
		putchar(179);
		gotoXY(85,i);
		putchar(179);
		gotoXY(101,i);
		putchar(179);
        gotoXY(190,i);
		putchar(179);
        gotoXY(200,i);
		putchar(179);
	}

    //in bien ngang
    for(int i=35; i <600; i++){
		gotoXY(i,0);
		putchar(95);
		gotoXY(i,25);
		putchar(95);
		gotoXY(i,4);
		putchar(95);
	}
	// in cac tieu de
	gotoXY(36,2);
	cout << "Nhap ho va ten: ";
	gotoXY(60,2);
	cout << "Nhap tuoi: ";
	gotoXY(72,2);
	cout << "Nhap dia chi: ";
	gotoXY(88,2);
	cout<<"Nhap ma sinh vien: ";
	gotoXY(108,2);
	cout<<"Nhap so CMND: ";
    gotoXY(125, 2);
    cout<<"Nhap so phong: ";
    gotoXY(145,2);
    cout<<"Nhap tien phong: ";
    gotoXY(170,2);
    cout<<"Nhap so lan vi pham: ";

}

void inkhung2(){
//in bien doc
    for(int i=1; i <25; i++){
		gotoXY(35,i);
		putchar(179);
		gotoXY(115,i);
		putchar(179);
		gotoXY(58,i);
		putchar(179);
		gotoXY(68,i);
		putchar(179);
		gotoXY(85,i);
		putchar(179);
		gotoXY(101,i);
		putchar(179);
        gotoXY(190,i);
		putchar(179);
        gotoXY(200,i);
		putchar(179);
	}

    //in bien ngang
    for(int i=35; i <600; i++){
		gotoXY(i,0);
		putchar(95);
		gotoXY(i,25);
		putchar(95);
		gotoXY(i,4);
		putchar(95);
	}
	// in cac tieu de
	gotoXY(36,2);
	cout << "Nhap ho va ten: ";
	gotoXY(60,2);
	cout << "Nhap tuoi: ";
	gotoXY(72,2);
	cout << "Nhap dia chi: ";
	gotoXY(88,2);
	cout<<"Nhap so dien thoai: ";
	gotoXY(108,2);
	cout<<"Nhap tien luong: ";
    gotoXY(125, 2);
    cout<<"Nhap chuc vu: ";

}

void giaodien(){
	while(true){
	system("cls");
	srand(time(NULL));
	SetColor(0, 1+rand()%15);
	cout<<"   *       *      **      *      *      **      * * * *  * * * *     * * * *  * * * *      **      * * * *  * * * *" <<endl;          
	cout<<"   * *   * *     *  *     * *    *     *  *     *        *           *           *        *  *     *        *      " <<endl;
	cout<<"   *   *   *    * ** *    *   *  *    * ** *    *   * *  * * * *     * * * *     *       * ** *    * * * *  * * * *" <<endl;
	cout<<"   *       *   *      *   *    * *   *      *   *     *  *                 *     *      *      *   *        *      " <<endl;
	cout<<"   *       *  *        *  *      *  *        *  * * * *  * * * *     * * * *     *     *        *  *        *      " <<endl;
    Sleep(0);
	SetColor(0,2); //doi mau chu
        cout << "\n\t\t\t1. Nhap thong tin";
        cout << "\n\t\t\t2. Hien thi thong tin";
        cout << "\n\t\t\t3. Sap xep (theo ten)";
        cout << "\n\t\t\t4. Thoat ";
        cout << "\n\t\t\t Nhap lua chon: "; 
    if(kbhit())
		break;
  }
}

class Dormitory{
private:
    vector<Student*> list_student;
    vector<Person *> list_person;

public:
    Dormitory();
    ~Dormitory();
    void Nhap();
    void Xuat();
    void capnhat();
    void xuatcapnhat();
    // void Sapxep();
    // void Timkiem();
    friend void inkhung();
    friend void inmenu1();
    void sapxep();
    void timkiem();
};
// void CongTy::Sapxep(){
//     for (int i = 0; i < dsnv.size() - 1; i++){
//         for (int j = i + 1; j < dsnv.size(); j++){
//             if (dsnv[i]->Luong() < dsnv[j]->Luong()){
//                 NhanVien *temp;
//                 temp = dsnv[i];
//                 dsnv[i] = dsnv[j];
//                 dsnv[j] = temp;
//             }
//         }
//     }
// }

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
        	inkhung1();
        	inmenu1();
            // cout<<"\n\n\n Nhap so luong sinh vien: ";
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
        	inkhung2();
            inmenu1();
        	// cout<<"\n\n\n Nhap so luong ban quan ly: ";
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
void Dormitory::sapxep(){
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
// void Dormitory::capnhat(){
//     int i=1, Luachon, n;
//     int found = 0;
//     string msv;
//         inmenu1();
//          while (i)
//     {
//         cout << "\n \n   Nhap lua chon: ";
//         cin >> Luachon;
//         Person *p;
//         switch (Luachon)
//         {
//         case 1:  
// 		  {
//             system("cls");
//         	// inkhung();
//         	inmenu1();
//             for(int i=0; i<n; i++){
//                 strcpy(msv, p[i].getId())
//                 if(strstr(strupr(msv), strupr(getId()))){
//                     found = 1;
//                     cout << "Cap nhat thong tin co ma sinh vien "<< getId() << ": ";
//                     capnhatSV(p[i]);
//                     break;
//                 }
//             }
//             if(found == 0){
//                 cout << "Sinh vien co ma id "<< getId() << " khong ton tai !!"<< endl;
//             }
            
//             break;
//         }
//         case 2:
//         {   
//             system("cls");
//         	// inkhung();
//             inmenu1();
//         	// cout<<"\n\n\n Nhap so luong ban quan ly: ";
//             // int b= numberManage(n);
//             // for(int i=0; i<b; i++){
//             //     cout << "Quan li thu " <<i+1<<":";
//             //     p = new Manage[n];
//             //     p->Nhap(i);
//             //     p->selection(false);
//             //     list_person.push_back(p);
//             // }
// 			// break;
            
//         }
//         case 3:
//         {
//             i--;
//             break;
//         }
//         default:
//         {
//             cout << "Lua chon khong hop le!!!" << endl;
//             break;
//         }
//         }
//     }
// }

// void Dormitory::xuatcapnhat(){   
//     system("cls");
// 	// inkhung();
//     for (int i = 0; i < list_person.size(); i++){
//     	cout << "xuat sinh vien thu "<< i+1<<":";
//         if (list_person[i]->selection() == true)
//             list_person[i]->Xuat(i);
        
//     }
//     for (int i = 0; i < list_person.size(); i++){
// 		cout << "xuat quan ly thu "<< i+1<<":";
// 		if (list_person[i]->selection() == false)
//             list_person[i]->Xuat(i);
        
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
        	inkhung1();
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
        
        // case 4:{
        //     cout << "Cap nhat sinh vien"<< endl;
        //     system("cls");
        // 	inkhung();
        //     p.capnhat();
        //     check = true;
        //     break;

        // }
        case 3:{
            cout << "\t\t sap xep sinh vien theo id: " << endl;
            p.sapxep();
            //p.Xuat();
            system("pause");
            break;
        }
        case 4:{
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