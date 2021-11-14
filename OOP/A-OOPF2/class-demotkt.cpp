#include <iostream>
using namespace std;
class A{
    private: 
        int x;
    protected:
        int y;
    public: 
        int z;
};

class B : protected A{
    private: 
        int v;
    public: void show();
};
class C:public B{
    public:
        void show(){
            cout << y;
        }
}
void B::show(){
    cout << z;
}
int main(){
    A a;
    B b;
    C c;
    b.show();
    c.show();
}