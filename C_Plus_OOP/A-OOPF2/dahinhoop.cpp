//static method
#include <iostream>

using namespace std;

class A{
    public:
        void xuat(){
            cout << "Lop A";
        }
};

class B:public A{
    public:
        void xuat(){
            cout << "Lop B";
        }
};

class C:public A{
    public: 
        void xuat(){
            cout << "Lop C";
        }
};
int main(){
    // A a;
    // a.xuat();
    // a.B::xuat();
    // a.C::xuat();

    A *p, *q, *r;
    A a;
    B b;
    C c;
    p = &a;
    q = &b;
    r = &c;
    p->xuat();
    q->xuat();
    r->xuat();
}