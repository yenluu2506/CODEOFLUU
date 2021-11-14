#include <iostream>
using namespace std;

class Phanso {
private:
	int tu, mau;
public:
	//void nhap();
	friend istream& operator >> (istream& is, Phanso& ps);
	friend ostream& operator << (ostream& os, const Phanso& ps);
	//friend Phanso operator + (Phanso ps1, Phanso ps2);
	Phanso operator + (Phanso ps);
	Phanso operator - (Phanso ps);
	Phanso operator * (Phanso ps);
	Phanso operator / (Phanso ps);
	friend Phanso operator += (Phanso ps1, Phanso ps2);
	friend Phanso operator -= (Phanso ps1, Phanso ps2);
	friend Phanso operator *= (Phanso ps1, Phanso ps2);
	friend Phanso operator /= (Phanso ps1, Phanso ps2);
	//Phanso cong(Phanso ps);
	int operator > (Phanso ps);
	//int operator == (Phanso ps);
	Phanso operator ++ (int);
	//++a
	Phanso operator ++ ();
};

//void Phanso::nhap() {
//	cout << "Nhap tu: ";
//	cin >> tu;
//	cout << "Nhap mau: ";
//	cin >> mau;
//}

istream& operator >> (istream& is, Phanso& ps) {
	cout << "Nhap tu: ";
	is >> ps.tu;
	cout << "Nhap mau: ";
	is >> ps.mau;
	return is;
}

ostream& operator << (ostream& os, const Phanso& ps) {
	os << ps.tu << "/" << ps.mau << endl;
	return os;
}

//void Phanso::xuat() {
//	cout << tu << "/" << mau;
//}

Phanso Phanso::operator+(Phanso ps) {
	Phanso t;
	t.tu = tu * ps.mau + mau * ps.tu;
	t.mau = mau * ps.mau;
	return t;
}

//Phanso Phanso::cong(Phanso ps) {
//	Phanso t;
//	t.tu = tu * ps.mau + mau * ps.tu;
//	t.mau = mau * ps.mau;
//	return t;
//}

int Phanso::operator > (Phanso ps) {
	if (tu / mau > (ps.tu / ps.mau))
		return 1;
	else
		return 0;
}

//int Phanso::operator == (Phanso ps) {
//	if (tu / mau == (ps.tu / ps.mau))
//		return 1;
//	else
//		return 0;
//}

Phanso Phanso::operator-(Phanso ps) {
	Phanso t;
	t.tu = tu * ps.mau - mau * ps.tu;
	t.mau = mau * ps.mau;
	return t;
}

Phanso Phanso::operator*(Phanso ps) {
	Phanso t;
	t.tu = tu * ps.tu;
	t.mau = mau * ps.mau;
	return t;
}

Phanso Phanso::operator/(Phanso ps) {
	Phanso t;
	t.tu = tu * ps.mau;
	t.mau = mau * ps.tu;
	return t;
}

Phanso operator += (Phanso ps1, Phanso ps2) {
	ps1.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
	ps1.mau = ps1.mau * ps2.mau;
	return ps1;
}
Phanso operator -= (Phanso ps1, Phanso ps2) {
	ps1.tu = ps1.tu * ps2.mau - ps1.mau * ps2.tu;
	ps1.mau = ps1.mau * ps2.mau;
	return ps1;
}
Phanso operator *= (Phanso ps1, Phanso ps2) {
	ps1.tu = ps1.tu * ps2.tu;
	ps1.mau = ps1.mau * ps2.mau;
}
Phanso Phanso:: operator++(int) {
	tu = tu + 1;
	mau = mau + 1;
	return *this;
}
Phanso Phanso:: operator++() {
	tu = tu + 1;
	mau = mau + 1;
	return *this;
}

int main() {
	Phanso a, b, c;
	cout << "Nhap phan so a: " << endl;
	cin >> a;

	cout << "Nhap phan so b: " << endl;
	cin >> b;
	//phanso.nhap();
	cout << "Phan so da nhap la: ";
	cout << a;
	cout << b;
	// c = a.cong(b);
	c = a + b;
	cout << "Tong la: ";
	cout << c;
	if (a > b) {
		cout << "Lon hon." << endl;
	}
	else {
		cout << "Be hon hoac bang." << endl;
	}
	c = a - b;
	cout << "Hieu la: ";
	cout << c;
	c = a * b;
	cout << "Tich la: ";
	cout << c;
	c = a / b;
	cout << "Thuong la: ";
	cout << c;
	c = (a + b);
	cout << "+=: ";
	cout << c;
	c = (a - b);
	cout << "-=: ";
	cout << c;
	cout << "a++ = " << a++ << endl;
	cout << "++a = " << ++a << endl;
	system("pause");
}