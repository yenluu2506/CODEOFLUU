//Ho va ten: Bui Thi Yen Luu
//MSV: 6151071011

#include <iostream>
using namespace std;

class A{
    private:
        int x,y;
    public:
        A();
        A(int x, int y);
        A(A const &k);
        ~A();
        friend istream& operator >> (istream& is, A& a);
	    friend ostream& operator << (ostream& os, const A& a);
        A operator + (A a);
        bool operator > ();
}

A::~A(){

}
A::A(){
    x = 0; 
    y = 0;
}
A::A(int x, int y){
    this->x=x;
    this->y=y;
}
A::A(const A &k){
    x=k.x;
    y=k.y;
}
istream& operator >> (istream& is, A& a){
    cout << "Nhap x: ";
	is >> a.x;
	cout << "Nhap y: ";
	is >> a.y;
	return is;
}
ostream& operator << (ostream& os, const A& a){
    os << a.x << endl;
    os << a.y << endl;
	return os;
}

bool A:: operator >(A a){
    if((a.x+a.y)>(x+y))
        true;
    else false;
    
}

A A:: operator +(A a){
    A b;
    b.x=x+a.x;
    b.y=y+a.y;
    return b;
}

A A:: operator +(A a){
    // A b;
    // b.x=x+a.x;
    // b.y=y+a.y;
    return a(x+a.x, y+a.y);
}

bool A::operator > (A &a){
    return (this->x > a.x) ? true : false;
}

class B : public A{
    private:
        int z;
    public:
        B();
        B(int z, int x, int y);
        B(B const &i);
        ~B();
        friend istream& operator >> (istream& is, B& b);
	    friend ostream& operator << (ostream& os, const B& b);
        B operator + (B &b);
        bool operator > (B &b);
}

B::~B(){

}
B::B()::A(){
    z = 0;
}
B::B(int z, int x, int y):A(x,y){
    this->z=z;
}
B::B(const B &i){
    z=i.z;
    //*this = b;
}
istream& operator >> (istream& is, B& b){
    //goi toan tu nhap a
    A*a = static_cast<A*>(&b);
    is>>a*;
    cout << "Nhap z: ";
	is >> b.z;
	return is;
}
ostream& operator << (ostream& os, const B& b){
    A a=static_cast<A>(b); // nhuư 103 cung duoc
    os<<*a;
    os << b.z << endl;
	return os;
}
bool B::operator > (B b) {
	if ( z > b.z)
		return true;
	else
		return false;
}
B B::operator+(B &b){
    // return B(z + b.z);
    //x+b.x
    //y+b.y
    //z+b.z
    B t;
    A *a = static_cast<A *>(&b);
    A *a1 = static_cast<A *>(this);
    A *t1 = static_cast<A *>(&t);
    *t1  = *a1+*a2;
    t.z = z+b.z;
    return t;
}
bool B::operator > (B &b){
    A *a = static_cast<A *>(&b);
    A *a1 = static_cast<A *>(this);
    if(*a<*this && z> b.z)
        return true;
    else
        return false;
}
int main(){
    // A a1, a2, a3;
    // B b1, b2, b3;
    // cout << "Nhap a1: " << endl;
	// cin >> a1;

	// cout << "Nhap a2: " << endl;
	// cin >> a2;
    // if (a1 > a2) {
	// 	cout << "Lon hon." << endl;
	// }
	// else {
	// 	cout << "Be hon hoac bang." << endl;
	// }
    // a3 = a1 + a2;
	// cout << "Tong la: ";
    // cout << "Nhap b1: " << endl;
	// cin >> b1;

	// cout << "Nhap b2: " << endl;
	// cin >> b2;
    // if (b1 > b2) {
	// 	cout << "Lon hon." << endl;
	// }
	// else {
	// 	cout << "Be hon hoac bang." << endl;
	// }
    // b3 = b1 + b2;
	// cout << "Tong la: ";

    B b1, b2;
    cout << "Enter b1: ";
    cin >> b1;
    cout << "Enter b2: ";
    cin >> b2;
    b3=b1+b2;
    cout << "Sum: "<< b3;
    if(b1>b2) cout <<"Lon hon";
    else cout << "Be hon";

}