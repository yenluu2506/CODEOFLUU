//ho va ten: bui thi yen luu
//msv: 6151071011
#include <iostream>
#include <string>

using namespace std;

class hocsinh {
private:
	string name;
	double diemvan, diemtoan;
public:
    hocsinh();
    hocsinh(string name, double diemvan, double diemtoan);
    hocsinh(const hocsinh &hs);
    ~hocsinh();
	string getname();
	void setname(string name);
	double getdiemvan();
	void setdiemvan(double diemvan);
	double getdiemtoan();
	void setdiemtoan(double diemtoan);
	void nhap();
	void xuat();
	void xeploai();
};
hocsinh::hocsinh(){
    name = "Null";
    diemvan = 0;
    diemtoan = 0;
}
hocsinh::hocsinh(string name, double diemvan, double diemtoan){
    this->name = name;
    this-> diemvan = diemvan;
    this-> diemtoan = diemtoan;
}
hocsinh::hocsinh(const hocsinh &hs){
    name = hs.name;
    diemvan = hs.diemvan;
    diemtoan = hs.diemtoan;
}    
hocsinh::~hocsinh(){

}
string hocsinh::getname() {
	return name;
}
void hocsinh::setname(string name) {
	this->name = name;
}
double hocsinh::getdiemvan() {
	return diemvan;
}
void hocsinh::setdiemvan(double diemvan) {
	this->diemvan = diemvan;
}
double hocsinh::getdiemtoan() {
	return diemtoan;
}
void hocsinh::setdiemtoan(double diemtoan) {
	this->diemtoan = diemtoan;
}
void hocsinh::nhap() {
	cout << "nhap thong tin sinh vien: " << endl;
	cout << "ho va ten: ";
	getline(cin, name);
	while (true) {
		cout << "diem van: ";
		cin >> diemvan;
		cout << "diem toan: ";
		cin >> diemtoan;
		if (diemtoan > 10 || diemvan > 10 || diemtoan < 0 || diemvan < 0) {
			cout << "Nhap lai ";
		}
		else break;
	}
	
}
void hocsinh::xuat() {
	cout << endl;
	cout << "thong tin sinh vien da nhap. " << endl;
	cout << "ho va ten: " << name << endl;
	cout << "diem van: " << diemvan << endl;
	cout << "diem toan: " << diemtoan << endl;
}
void hocsinh::xeploai() {
	int dtb;
	dtb = (diemvan + diemtoan) / 2;
	if (dtb >= 8.0) {
		cout << "dat loai gioi." << endl;
	}
	else if (dtb >= 7.0) {
		cout << "dat loai kha." << endl;
	}
	else if (dtb >= 5.0) {
		cout << "dat loai trung binh." << endl;
	}
	else {
		cout << "dat loai yeu." << endl;
	}
}
int main() {
	hocsinh hs;
	hs.nhap();
	hs.xuat();
	hs.xeploai();
}