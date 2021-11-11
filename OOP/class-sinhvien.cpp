//Ho va ten: Bui Thi Yen Luu
//MSV: 6151071011

#include <iostream>
#include <string>
using namespace std;

class Sinhvien {
private:
	string hoten;
	string gioitinh;
	int ngaysinh;
	double dtb;
public:
	void Nhap();
	void Xuat();
};
void Sinhvien::Nhap() {
	cout << "Nhap ho va ten: ";
	getline(cin, hoten);
	cout << "Nhap gioi tinh: ";
	getline(cin, gioitinh);
	cout << "Nhap ngay sinh: ";
	cin >> ngaysinh;
	cout << "Nhap diem trung binh: ";
	cin >> dtb;
}
void Sinhvien::Xuat() {
	cout << "\nThong tin da nhap la: " << endl;
	cout << "Ho va Ten: " << hoten << endl;
	cout << "Gioi tinh: " << gioitinh << endl;
	cout << "Ngay sinh: " << ngaysinh << endl;
	cout << "Diem trung binh: " << dtb << endl;
}
int main() {
	Sinhvien sv1;
	sv1.Nhap();
	sv1.Xuat();
}