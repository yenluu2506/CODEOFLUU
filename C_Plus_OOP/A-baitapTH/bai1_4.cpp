#include <iostream>
#include <conio.h>
using namespace std;

class vector
{
    private:
        int n;
        float *v;
    public:
    vector();
    ~vector();
    void nhap();
    void in();
    vector operator + (vector a);
};

vector::vector()
{
    n = 0;
    v = new float[n];
    for (int i=1;i<=n;i++)
    v[i] = 0;
}
vector::~vector()
{
    delete v;
}
void vector::nhap()
{
    cout<<"Nhap so phan tu cua vecto : ";
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cout<<"Nhap phan tu thu "<<i<<" : \n";
        cin>>v[i];
    }
}
// void vector::in()
// {
//     cout<<"v = ( ";
//     for (int i =1;i<=n;i++)
//     {
//         cout<<v[i];

//         if (i<n);
//         cout<<" , ";
//     }
//     cout<<" )";
// }
void vector::in(){
	int i;
	for (i=0;i<n;i++)
	cout<<v[i]<<"       ";
}
vector vector::operator+ (vector a)
{
    vector c;
    if (n!=a.n)
    cout<<"Khong thuc hien dc phep cong vecto \n";
    else

    c.n = a.n;
    for (int i=1;i<=a.n;i++)
    c.v[i] = v[i] + a.v[i];
    return c;
}

int main()
{
    vector a,b,c;
    cout<<"Nhap vecto a :\n";
    a.nhap();
    cout<<"Nhap vecto b:\n";
    b.nhap();
    cout<<"Hai vecto da nhap la:\n";
    a.in();
    cout<<"\n";
    b.in();
    cout<<"\n\n";
    c = a+b;
    cout<<"Tong 2 vecto la: \n";
    c.in();
    getch();
}