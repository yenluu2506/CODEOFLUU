#include <iostream>
#include <string>

using namespace std;

//Định nghĩa lớp
class Student {
private:
	string name; //tên
	int age; //tuổi
	string address; //địa chỉ
	double id; //mã sinh viên
	string dayofjoiningtheYouthUnion; //Ngày vào đoàn
	double identitycard; //số CMND
	int roomnumber; // số phòng ở
	double amounttopayforboarding; //số tiền cần phải đóng nội trú
	int numberofViolations; //số lần vi phạm
public:
	void init(string name, int age, string address, double id, string dayofjoiningtheYouthUnion, double identitycardnumber, int roomnumber, double amounttopayforboarding, int numberofViolations);
	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge();
	void setAddress(string address);
	string getAdress();
	void setId(double id);
	double getId();
	void setDayofjoiningtheYouthUnion(string dayofjoiningtheYouthUnion);
	string getDayofjoiningtheYouthUnion();
	void setIdentitycardnumber(double identitycardnumber);
	double getIdentitycardnumber();
	void setRoomnumber(int roomnumber);
	int getRoomnumber();
	void setAmounttopayforboarding(double amounttopayforboarding);
	double getAmounttopayforboarding();
	void setNumberofViolations(int numberofViolations);
	int getNumberofViolations();
	void Nhap();
	void Xuat();
};
//Khai báo phương thức bên ngoài lớp

void Student::init(string name, int age, string address, double id, string dayofjoiningtheYouthUnion, double identitycardnumber, int roomnumber, double amounttopayforboarding, int numberofViolations) {
	this->name = name;
	this->age = age;
	this->address = address;
	this->id = id;
	this->dayofjoiningtheYouthUnion = dayofjoiningtheYouthUnion;
	this->identitycard = identitycardnumber;
	this->roomnumber = roomnumber;
	this->amounttopayforboarding = amounttopayforboarding;
	this->numberofViolations = numberofViolations;
}
string Student::getName() {
	return name;
}
void Student::setName(string name) {
	this->name = name;
}
int Student::getAge() {
	return age;
}
void Student::setAge(int age) {
	this->age = age;
}
string Student::getAdress() {
	return address;
}
void Student::setAddress(string address) {
	this->address = address;
}
double Student::getId() {
	return id;
}
void Student::setId(double id) {
	this->id = id;
}
string Student::getDayofjoiningtheYouthUnion() {
	return dayofjoiningtheYouthUnion;
}
void Student::setDayofjoiningtheYouthUnion(string dayofjoiningtheYouthUnion) {
	this->dayofjoiningtheYouthUnion = dayofjoiningtheYouthUnion;
}
double Student::getIdentitycardnumber() {
	return identitycard;
}
void Student::setIdentitycardnumber(double identitycardnumber) {
	this->identitycard = identitycardnumber;
}
int Student::getRoomnumber() {
	return roomnumber;
}
void Student::setRoomnumber(int roomnumber) {
	this->roomnumber = roomnumber;
}
double Student::getAmounttopayforboarding() {
	return amounttopayforboarding;
}
void Student::setAmounttopayforboarding(double amounttopayforboarding) {
	this->amounttopayforboarding = amounttopayforboarding;
}
int Student::getNumberofViolations() {
	return numberofViolations;
}
void Student::setNumberofViolations(int numberofViolations) {
	this->numberofViolations = numberofViolations;
}
void Student::Nhap() {
	Student* student;
	int length;
	cout << "Nhap so luong sinh vien: ";
	cin >> length;
	student = new Student[length];
	for (int i = 0; i < length; i++) {
		string name; //tên
		int age; //tuổi
		string address; //địa chỉ
		double id; //mã sinh viên
		string dayofjoiningtheYouthUnion; //Ngày vào đoàn
		double identitycardnumber; //số CMND
		int roomnumber; // số phòng ở
		double amounttopayforboarding; //số tiền cần phải đóng nội trú
		int numberofViolations; //số lần vi phạm
		cout << "Sinh vien thu " << i + 1 << ": " << endl;
		cout << "Ho va Ten: " << endl;
		getline(cin, name);
		student[i].setName(name);
		cout << "Tuoi: " << endl;
		cin >> age;
		student[i].setAge(age);
		cout << "Dia chi: " << endl;
		getline(cin, address);
		student[i].setAddress(address);
		cout << "Ma sinh vien: " << endl;
		cin >> id;
		student[i].setId(id);
		cout << "Ngay vao doan: " << endl;
		getline(cin, dayofjoiningtheYouthUnion);
		student[i].setDayofjoiningtheYouthUnion(dayofjoiningtheYouthUnion);
		cout << "So CMND/CCCD: " << endl;
		cin >> identitycardnumber;
		student[i].setIdentitycardnumber(identitycardnumber);
		cout << "So phong o la: " << endl;
		cin >> roomnumber;
		student[i].setRoomnumber(roomnumber);
		cout << "So tien noi tru can phai dong: " << endl;
		cin >> amounttopayforboarding;
		student[i].setAmounttopayforboarding(amounttopayforboarding);
		cout << "So la vi pham trong ki tuc xa: " << endl;
		cin >> numberofViolations;
		student[i].setNumberofViolations(numberofViolations);
	}
}

int main() {
	
	Student* student;

	student.Nhap();
	delete[] student;
	system("pause");
	return 0;
}