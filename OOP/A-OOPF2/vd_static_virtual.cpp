#include <iostream>
using namespace std;

class A{
    public:
        virtual void show(){
            cout << "Hello A"<< endl;
        }
};

class B:public A{
    public:
        void show(){
            cout << "Hello B"<< endl;
        }
};

class C:public A{
    public:
        void show(){
            cout << "Hello C"<< endl;
        }
};

int main(){
    A *a = new C;
    A a1;
    //a1->show();
    B b1;
    C c1;
    a = &c1;
    a->show();
}