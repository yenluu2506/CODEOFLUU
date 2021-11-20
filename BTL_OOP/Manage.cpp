#include "Person.cpp"
#include <iostream>
using namespace std;

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
    void input3();
    void output3();
    // void nhap(int m, Manage mn[]);
    // void xuat(int m, Manage mn[]);
};

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

void Manage::input3(){
    input1();
    cout<<"Nhap so dien thoai: ";
    getline(cin, phone);
	fflush(stdin);
	cout<<"Nhap tien luong: ";
	cin>>salary;
	fflush(stdin);
	cout<<"Nhap chuc vu: ";
	getline(cin,position);
}

void Manage::output3(){
    output1();
    cout<<"So dien thoai: "<<phone<<endl;
    cout<<"Dia chi: "<<address<<endl;
	cout<<"Tien luong: "<<salary<<endl;
	cout<<"Chuc vu: "<<position<<endl;
}

// void nhap(int m, Manage mn[]){
//     for(int i=0; i<m; i++){
//         cout <<"Nhap sinh vien thu "<<i+1<<":"<< endl;
//         mn[i].input3();
//     }
// }
// void xuat(int m, Manage mn[]){
//     cout<<"*********************";
//     for(int i=0; i<m; i++){
//         cout <<"Sinh vien thu"<<i+1<<":"<<endl;
//         mn[i].output3();
//     }
// }

int numberManage(){
	int n;
	cout << "Enter number of manages: ";
	cin >> n;
}