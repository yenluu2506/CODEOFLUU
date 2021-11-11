//ham thuan ao, khong cai dat gi het chi khai bao thoi

//  virtual <function> = 0;

#include <iostream>

using namespace std;

class A{
    public:
        virtual void show(){
            cout << "Hello A"<< endl;
        }
        virtual void show1() = 0;
};

class B:public A{
    public:
        void show(){
            cout << "Hello B"<< endl;
        }
        void show1(){
            cout << "Hello B"<< endl;
        }
};

class C:public A{
    public:
        void show(){
            cout << "Hello C"<< endl;
        }
        void show1(){
            cout << "Hello C"<< endl;
        }
};

int main(){
    A *a = new B;
    // A a1;
    // // a1->show();
    // B b1;
    // C c1;
    // a = &c1;
    a->show();
}