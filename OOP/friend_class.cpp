#include <iostream>
using namespace std;

class A {
private:
	int x, y;
public:
	void input();
	void show();
	friend class B;
};
class B {
private:
	int z;
public:
	void input();
	void showA(A a);
};
void A::input() {
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y";
	cin >> y;
}
void A::show() {
	cout << "x = " << x << end << "y = " << y << endl;
}
void B::input() {
	cout << "Nhap z: ";
	cin >> z;
}
void B::showA(A a) {
	cout << "x= " << a.x << endl;
	cout << "y = " << a.y << endl;
	cout << "z = " << this->z << endl;
}
int main() {
	A a;
	B b;
	a.input();
	a.show();
	b.input();
	b.showA();
}