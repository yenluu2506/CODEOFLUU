#include<stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;
class Complex{
    private:
        float phanthuc ,phanao;
    public:
        Complex()
        {
        phanthuc=0; phanao=0;
        }
        void add()
        {
        cout<<"Moi nhap phan thuc: ";
        cin>>phanthuc;
        cout<<"Moi nhap phan ao: ";
        cin>>phanao;
        }
        void display()
        {
        if (phanao<0) cout<<phanthuc<<phanao<<"*i";
        else cout<<phanthuc<<"+"<<phanao<<"*i";
        }
        friend Complex operator +(Complex a,Complex b);
        friend Complex operator -(Complex a,Complex b);
};
Complex operator +(Complex a,Complex b)
{ 
    Complex c;
    c.phanthuc=a.phanthuc+b.phanthuc;
    c.phanao=a.phanao+b.phanao;
    return c;
}
Complex operator -(Complex a,Complex b)
{ 
    Complex c;
    c.phanthuc=a.phanthuc-b.phanthuc;
    c.phanao=a.phanao-b.phanao;
    return c;
}
int main()
{
    Complex x,y;
    x.add();
    y.add();
    x.display();
    cout<<" + ";
    y.display();
    cout<<" = ";
    (x+y).display();
    cout<<"\n";
    x.display();
    cout<<" – ";
    y.display();
    cout<<" = ";
    (x-y).display();
    getch();
}