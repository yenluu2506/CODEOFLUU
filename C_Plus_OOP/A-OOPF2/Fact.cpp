#include <iostream>
using namespace std;

class Frac{
    private:
        float a, b;
    public:
        Frac();
        ~Frac();
        void input();
        void output();
        int operator =(Frac sp);
        friend inline bool operator>(const Frac &h1, const Frac &h2);
};

Frac::Frac(){

}
Frac::~Frac(){

}
void Frac::input()
{
    do
    {
        cout<<"Nhap tu so, mauso: ";
        cin>>this->a>>this->b;
        if(this->b == 0)
        cout<<"Nhap lai mauso"<<endl;
    }while(this->b == 0);
}

void Frac::output()
{
    cout<<"Phan so: "<<this->a<<"/"<<this->b<<endl;
}
bool operator>(const Frac &h1, const Frac &h2)
{
    float a;
    a = h1.a * h2.b - h1.b * h2.a;
    if(a>0) return 1;
    else return 0;
}
int Frac::operator = (Frac sp)
{
	a=sp.a;
	b=sp.b;
}
int main(){
    Frac d1, d2;
    cout<<"Nhap phan so thu 1: "<<endl;
    d1.input();
    cout<<"Nhap phan so thu 2: "<<endl;
    d2.input();
    d1.output();
    d2.output();
    if(d1 > d2)
        cout<<"d1>d2"<<endl;
    else
        cout<<"d1<d2"<<endl;
    system("pause");
}