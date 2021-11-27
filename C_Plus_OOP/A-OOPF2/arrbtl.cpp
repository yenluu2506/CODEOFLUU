#include <iostream>
#include <string>
#include <cstdio>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
using namespace std;

class Person{
    protected:
        string name;
        int age;
        string address;
    public:
		string getName(){
		    return name;
		}
		void setName(string name){
		    this->name = name;
		}
		int getAge(){
		    return age;
		}
		void setAge(int age){
		    this->age = age;
		}
		string getAddress(){
		    return address;
		}
		void setAddress(string address){
		    this->address = address;
		}
		friend istream &operator>>(istream &vao, Person &p);
	    friend ostream &operator<<(ostream &ra,  const Person p);
};

istream &operator>>(istream &vao, Person &p){
	fflush(stdin);
    cout <<"Nhap ho va ten: ";
    getline(vao,p.name);
	fflush(stdin);
	cout<<"Nhap dia chi: ";
    vao>>p.address;
	fflush(stdin);
    cout<<"Nam sinh: ";
    vao>> p.age;
}
ostream &operator<<(ostream &ra,  const Person p){
	ra<<"Ho va ten: "<<p.name<<endl;
    ra<<"Nam sinh: "<<p.age<<endl;
    ra<<"Dia chi: "<<p.address<<endl;
}

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
		friend istream &operator>>(istream &vao, Student &sv);
	    friend ostream &operator<<(ostream &ra,  const Student sv);
};
istream &operator >> (istream &vao, Student &sv){
	Person p;
    //Tên, năm sinh, địa chỉ, mã sv, CMND, số phòng ở, phí ăn ở, số lần vi phạm
	// fflush(stdin);
    // cout <<"Nhap ho va ten: ";
    // getline(vao,sv.name);
	fflush(stdin);
    cout<<"Nhap ma sinh vien: ";
    getline(vao,sv.id);
	// fflush(stdin);
    // cout<<"Nam sinh: ";
    // vao>> sv.age;
	fflush(stdin);
    cout<<"Nhap so CMND: ";
    getline(vao, sv.identitycard);
	// fflush(stdin);
    // cout<<"Nhap dia chi: ";
    // vao>>sv.address;
	fflush(stdin);
    cout<<"Nhap so phong: ";
    vao>>sv.room;
	fflush(stdin);
    cout<<"Nhap tien phong: ";
    vao>>sv.boardingfee;
	fflush(stdin);
    cout<<"Nhap so lan vi pham: ";
    vao>>sv.violations;
	fflush(stdin);
    return vao;
}

ostream &operator <<(ostream &ra, const Student sv){
	Person p;
    //Tên, năm sinh, địa chỉ, mã sv, CMND, số phòng ở, phí ăn ở, số lần vi phạm
    // ra<<"Ho va ten: "<<sv.name<<endl;
    ra<<"Ma sinh vien: "<<sv.id<<endl;
    // ra<<"Nam sinh: "<<sv.age<<endl;
    ra<<"So CMND: "<<sv.identitycard<<endl;
    // ra<<"Dia chi: "<<sv.address<<endl;
    ra<<"So phong: "<<sv.room<<endl;
    ra<<"Tien phong: "<<sv.boardingfee<<endl;
    ra<<"So lan vi pham: "<<sv.violations<<endl;
    return ra;
}
//Khai báo phương thức bên ngoài lớp
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

//NHẬP DANH SÁCH SINH VIÊN

void input_list(int n, Student sv[]){
	for(int i=0;i<n;i++){
		cout<<"Nhap sv thu "<< i+1<<": "<<endl;
		cin>>sv[i];
	}
}

void output_list(int n, Student sv[]){
	cout<<"Danh sach sinh vien la: \n";
	for(int i=0;i<n;i++){
		cout<<"Sinh vien thu "<<i+1<<":\n"<<endl<<sv[i];
	}
}

class Manage : public Person{
private:
    unsigned long int salary; //Tiền lương
    string position; //Chức vụ
	string phone; //CMND
public: 
    unsigned long int getSalary();
    void setSalary(unsigned long int salary);
    string getPosition();
    void setPosition(string position);
	string getPhone();
	void setPhone(string phone);
	friend istream &operator>>(istream &vao, Manage &Ban_QL);
	friend ostream &operator<<(ostream &ra,  const Manage Ban_QL);
};

istream &operator >> (istream &vao, Manage &Ban_QL){
	//Tên, năm sinh, địa chỉ, CMND, tiền lương, chức vụ
	fflush(stdin);
    cout <<"Nhap ho va ten: ";
    getline(vao,Ban_QL.name);
	fflush(stdin);
    cout<<"Nam sinh: ";
    vao>> Ban_QL.age;
	fflush(stdin);
    cout<<"Nhap so dien thoai: ";
    getline(vao, Ban_QL.phone);
	fflush(stdin);
    cout<<"Nhap dia chi: ";
    vao>>Ban_QL.address;
	fflush(stdin);
	cout<<"Nhap tien luong: ";
	vao>>Ban_QL.salary;
	fflush(stdin);
	cout<<"Nhap chuc vu: ";
	getline(vao,Ban_QL.position);
    return vao;
}

ostream &operator <<(ostream &ra, const Manage Ban_QL){
    //Tên, năm sinh, địa chỉ, CMND, tiền lương, chức vụ
    ra<<"Ho va ten: "<<Ban_QL.name<<endl;
    ra<<"Nam sinh: "<<Ban_QL.age<<endl;
    ra<<"So CMND: "<<Ban_QL.phone<<endl;
    ra<<"Dia chi: "<<Ban_QL.address<<endl;
	ra<<"Tien luong: "<<Ban_QL.salary<<endl;
	ra<<"Chuc vu: "<<Ban_QL.position<<endl;
    return ra;
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

//NHẬP DANH SÁCH NGƯỜI QUẢN LÝ

void input_list(int n, Manage Ban_QL[]){
	for(int i=0;i<n;i++){
		cout<<"Nhap quan ly "<< i+1<<": "<<endl;
		cin>>Ban_QL[i];
	}
}

void output_list(int n, Manage Ban_QL[]){
	cout<<"\nDanh sach quan ly la: \n";
	for(int i=0;i<n;i++){
		cout<<"Quan ly "<<i+1<<":\n"<<endl<<Ban_QL[i];
	}
}

void Thongke_DS(int n, Student sv[]){
	//DS Sinh vien
	// cout<<"\n|\tSTT\t|\tMa SV\t|\tHo va ten\t|\tNam Sinh\t|\tDia Chi\t|\tCMND\t|\tSo Phong\t|\tTien Phong\t|\tSo lan vi pham\t|"<<endl;
    printf("\n%10s %15s %20s %15s %15s %15s %15s %15s %15s\n", "STT", "MA SINH VIEN", "HO VA TEN", "NAM SINH","DIA CHI", "CNMD", "SO PHONG", "TIEN PHONG", "SO LAN VI PHAM");
	for(int i=0;i<n;i++){
		// cout<<"|\t"<<i+1<<"\t|\t"<<sv->getId()<<"\t|\t" << sv->getName()<<"\t|\t"<< sv->getAge()<<"\t|\t"<< sv->getAddress() <<"\t|\t" << sv->getIdentitycard()<<"\t|\t"<< sv->getRoom()<<"\t|\t"<< sv->getBoardingfee()<<"|\t"<<sv->getViolations()<< endl;
        // printf("\n%10d %15s %20s %15d %15s %15s %15d %15d %15d\n", i+1, sv->getId(), sv->getName(), sv->getAge(), sv->getAddress(), sv->getIdentitycard(), sv->getRoom(), sv->getBoardingfee(), sv->getViolations());
		cout << endl;
		cout << setw(10) << i+1<<setw(15)<<(sv+i)->getId()<<setw(20)<<(sv+i)->getName()<<setw(15)<<(sv+i)->getAge()<<setw(15)<<(sv+i)->getAddress()<<setw(15)<<(sv+i)->getIdentitycard()<<setw(15)<<(sv+i)->getRoom()<<setw(15)<<(sv+i)->getBoardingfee()<<setw(15)<<(sv+i)->getViolations();
	}
	//DS Quan ly
}

int main(){
	int n,m;
	cout<<"Nhap so luong sinh vien: ";
	cin>>n;
	Student sv[n];
	cout<<"Nhap thong tin sinh vien: \n";
	input_list(n,sv);
	
	cout<<"Nhap so luong nguoi quan ly: ";
	cin>>m;
	Manage Ban_QL[m];
	cout<<"Nhap thong tin quan ly: \n";
	input_list(m,Ban_QL);
	// output_list(n,sv);
	Thongke_DS(n, sv);
	output_list(m,Ban_QL);
}