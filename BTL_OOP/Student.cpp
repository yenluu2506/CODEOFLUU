#include "Person.cpp"
#include <string>
#include<fstream>
#include <iostream>
using namespace std;

class Student : public Person {
	private:
		string id; //mã sinh viên
		string identitycard; //số CMND
		int room; // số phòng ở
		unsigned long int boardingfee; //phí nội trú
		int violations; //số lần vi phạm
	public:
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
        void input2();
        void output2();
		void write_file();
		void read_file(int sv);
		int count();
		void list_student();
};

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

void Student::input2(){
    input1();
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

void Student::output2(){
    output1();
    cout<<"Ma sinh vien: "<<id<<endl;
    cout<<"So CMND: "<<identitycard<<endl;
    cout<<"So phong: "<<room<<endl;
    cout<<"Tien phong: "<<boardingfee<<endl;
    cout<<"So lan vi pham: "<<violations<<endl;
}

// void nhap(int n, Student sv[]){
//     for(int i=0; i<n; i++){
//         cout <<"Nhap sinh vien thu "<<i+1<<":"<< endl;
//         // cin>>sv[i];
//         sv[i].input2();
//     }
// }
// void xuat(int n, Student sv[]){
//     cout<<"*******************";
//     for(int i=0; i<n; i++){
//         cout <<"Sinh vien thu"<<i+1<<":"<<endl;
//         sv[i].output2();
//     }
// }

void Student::write_file()
{
    fstream f; 
    f.open("sinhvien.dat", ios::binary|ios::app|ios::out);
    f.write((char*)this, sizeof(*this));
    f.close();
}
void Student::read_file(int sv){
    fstream f;
    f.open("sinhvien.dat",ios::binary|ios::in);
    f.seekg(sv* sizeof(Student));
    f.read((char*)this,sizeof(*this));
    f.close();
}

// int Student::count(){
//      ifstream f;
//      f.open("sinhvien.dat", ios::binary);
//      f.seekg(0, ios::end);
//      if(!f)
//         return 0;
//      else
//         return (int)f.tellg() / sizeof(Student);
// }

// void Student::list_student(){
//     Student sv;
//     cout<<"\n Co tat ca "<<Student::count()<<" sinh vien";
//     for (int i=0 ; i<sv.count(); i++){
//         sv.read_file(i);
//         sv.output2();
//     }
// }
// void menu(Student &sv){
// 	cout << "\t HE THONG QUAN LY SINH VIEN KI TUC XA !!!"<< endl;
// 	cout << "\t 1. Nhap sinh vien"<< endl;
// 	cout << "\t 2. Xuat sinh vien"<< endl;
// 	cout << "Ban chon ?"<< endl;
// 	int k;
// 	cin >> k;
// 	switch(k){
// 		case(1): {
// 			sv.input2();
// 			menu(sv);
// 			break;
// 		}
// 		case(2): {
// 			sv.list_student();
// 			menu(sv);
// 			break;
// 		}
// 	}
// }

int numberStudent(){
	int n;
	cout << "Enter number of students: ";
	cin >> n;
}