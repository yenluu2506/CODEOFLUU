////Ho va ten: Bui Thi Yen Luu
////Ma sinh vien: 6151071011
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Sinhvien {
//private:
//	string msv;
//	string hoten;
//	int namsinh;
//	string lop;
//	double dtb;
//public:
//	void nhap(Sinhvien a[], int& n);
//	void xuat(Sinhvien a[], int& n);
//	friend istream& operator >> (istream& is, Sinhvien& sv);
//	friend ostream& operator << (ostream& os, Sinhvien& sv);
//	double getDtb();
//	int getNamsinh();
//	void sapxepTheoDTB(Sinhvien a[], int n);
//	void sapxepNamsinh(Sinhvien a[], int n);
//	void thongke(Sinhvien a[], int n);
//};
//
//istream& operator >> (istream& is, Sinhvien& sv) {
//	cout << "Nhap MSV: ";
//	getline(is, sv.msv);
//	fflush(stdin);
//	cout << "Ho va ten";
//	getline(is, sv.hoten);
//	fflush(stdin);
//	cout << "Lop: ";
//	getline(is, sv.lop);
//	cout << "Nam sinh: ";
//	is >> sv.namsinh;
//	fflush(stdin);
//	cout << "Nhap diem trung binh: ";
//	is >> sv.dtb;
//}
//void nhap(Sinhvien a[], int& n) {
//	cout << "Nhap so sinh vien: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//}
//ostream& operator << (ostream& os, Sinhvien& sv) {
//	os << "Ma sinh vien: " << sv.msv;
//	os << "Ho va ten: " << sv.hoten;
//	os << "Nam sinh: " << sv.namsinh;
//	os << "Lop: " << sv.lop;
//	os << "Diem trung binh: " << sv.dtb;
//}
//void xuat(Sinhvien a[], int n) {
//	for (int i = 0; i < n; i++) {
//		cout << a[i];
//	}
//}
//double Sinhvien::getDtb() {
//	return dtb;
//}
//int Sinhvien::getNamsinh() {
//	return namsinh;
//}
//void sapxepTheoDTB(Sinhvien a[], int n) {
//	Sinhvien tmp;
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i].getDtb() < a[j].getDtb()) {
//				tmp = a[i];
//				a[i] = a[j];
//				a[j] = tmp;
//			}
//		}
//	}
//}
//
//void sapxepNamsinh(Sinhvien a[], int n) {
//	Sinhvien tmp;
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i].getNamsinh() > a[j].getNamsinh()) {
//				tmp = a[i];
//				a[i] = a[j];
//				a[j] = tmp;
//			}
//		}
//	}
//}
//
//int main() {
//	Sinhvien a[1000];
//	Sinhvien sv1;
//	int n;
//	nhap(a, n);
//	xuat(a, n);
//	sapxepTheoDTB(a, n);
//	xuat(a, n);
//	sapxepNamsinh(a, n);
//	xuat(a, n);
//	system("pause");
//	return 0;
//}