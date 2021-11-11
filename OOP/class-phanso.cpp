//#include <iostream>
//using namespace std;
//
//class Phanso {
//private:
//	int tu, mau;
//	int x;
//	int y;
//public:
//	void Nhap();
//	void Xuat();
//	int getTu() {
//		return tu;
//	}
//	int getMau() {
//		return mau;
//	}
//};
//
//void Tong(Phanso ps1, Phanso ps2) {
//	int tu1, mau1;
//	tu1 = (ps1.getTu() * ps2.getMau()) + (ps1.getMau() * ps2.getTu());
//	mau1 = (ps1.getMau() * ps2.getMau());
//	cout << "Phan so: " << tu << "/" << mau << endl;
//}
//void Phanso::Nhap() {
//	cout << "Nhap tu:" << endl;
//	cin >> tu;
//	cout << "Nhap mau: " << endl;
//	cin >> mau;
//}
//void Phanso::Xuat() {
//	cout << "Phan so: " << tu << "/" << mau << endl;
//}
//
//int main() {
//	Phanso ps1;
//	ps1.Nhap();
//	ps1.Xuat();
//}