#include <iostream>
using namespace std;

class Person{
    private:
        string name;
        int age;
        string address;
    public:
        void input1();
        void output1();
        string getName();
};
class Student:public Person{
    private:
        float score;
        string id;
    public:
        void input2();
        void output2();
        void rank();
};
class Teacher:public Person{
    public:
        void teach();
};
string Person::getName(){
    return name;
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
void Student::input2(){
    input1();
    cout << "Nhap ma sinh vien: ";
    getline(cin, id);
    cout << "Nhap diem: ";
    cin >> score;
}
void Student::output2(){
    output1();
    cout << "Ma sinh vien: "<< id<< endl;
    cout << "Diem: "<< score<<endl;
}
void Student::rank() {
	if (score >= 8.0) {
		cout << "dat loai gioi." << endl;
	}
	else if (score >= 7.0) {
		cout << "dat loai kha." << endl;
	}
	else if (score >= 5.0) {
		cout << "dat loai trung binh." << endl;
	}
	else {
		cout << "dat loai yeu." << endl;
	}
}
void Teacher::teach(){
    if(getName() == "Tran Thi Dung"){
        cout << "Co van k62.";
    }
    if(getName() == "Pham Thi Mien"){
        cout << "Co van k61.";
    }
    if(getName() == "Nguyen Le Minh"){
        cout << "Co van k60.";
    }
    if(getName() == "Tran Phong Nha"){
        cout << "Co van k59.";
    }
}
int main(){
    Person p;
    Student sv;
    Teacher t;
    cout << "Nhap sinh vien: "<< endl;
    // sv.input1();
    sv.input2();
    cout << "Nhap giang vien: "<< endl;
    t.input1();
    cout << "Thong tin sinh vien da nhap: "<< endl;
    // sv.output1();
    sv.output2();
    cout << "Danh gia xep loai: "<< endl;
    sv.rank();
    cout << "Thong tin giang vien: "<< endl;
    t.output1();
    t.teach();
}