#pragma once 
#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;
        string address;
    public:
		string getName();
        void setName(string name);
        int getAge();
        void setAge(int age);
        string getAddress();
        void setAddress(string address);
        void input1();
        void output1();
};

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
void Person::input1(){
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
void Person::output1(){
    cout << "Ho va ten: "<< name<<endl;
    cout << "Nam sinh: "<< age<<endl;
    cout << "Dia chi: "<< address<<endl;
}