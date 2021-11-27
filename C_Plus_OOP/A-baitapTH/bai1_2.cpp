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
        Complex cong(Complex u2);
        int operator =(Complex sp);
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
int Complex::operator= (Complex sp)
{
	phanthuc=sp.phanthuc;
	phanao=sp.phanao;
}
Complex Complex::cong(Complex u2)
{
    Complex u;
    u.phanthuc = phanthuc + u2.phanthuc;
    u.phanao = this->phanao + u2.phanao;
    return u;
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
    system("pause");

    Complex *sp, tong;
    int n;
    cout << "Nhap vao so luong phan tu n: ";
    cin >> n;
    sp = new Complex[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap so phuc thu "<<i+1<<": "<<endl;
        sp[i].add();
    }
    for(int i=0; i<n; i++){
        tong = tong.cong(sp[i]);
    }
    tong.display();
}