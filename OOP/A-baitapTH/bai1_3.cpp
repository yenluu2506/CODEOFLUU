#include<iostream>
#include<conio.h>
using namespace std;

class mydate
{
    int d,m,y;
    public:
    mydate(int dd=0,int mm=0,int yy=0)
    {
    d=dd; m=mm; y=yy;
    }
    void nhap()
    {
    cout<<"Nhap ngay: ";
    cin>>d;
    cout<<"Nhap thang: ";
    cin>>m;
    cout<<"Nhap nam: ";
    cin>>y;
    }
    void in()
    {
    cout<<d<<" / "<<m<<" / "<<y;
    }
    friend int operator >=(mydate &m1,mydate &m2);
};
int operator >=(mydate &m1,mydate &m2)
{
    if (m1.y>m2.y) return 1;
    if (m1.y==m2.y&&m1.m>m2.m) return 1;
    if (m1.y==m2.y&&m1.m==m2.m&&m1.d>=m2.d) return 1;
    return 0;
};
int main()
{
    mydate M[5],max;
    int i;
    for(i=0;i<5;i++)
    {
    cout<<"Nhap phan tu thu: "<<i+1<<"\n";
    M[i].nhap();
    }

    max=M[0];
    for(i=1;i<5;i++)
    if (M[i]>=max) max=M[i];
    cout<<"Thoi gian lon nhat: ";
    max.in();
    getch();
}