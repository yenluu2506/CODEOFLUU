#include<iostream>
#include<conio.h>
using namespace std;
class mytime
{
    private:
        int d,m,y;
    public:
        mytime(int dd=0,int mm=0,int yy=0)
        {
        d=dd; m=mm; y=yy;
        }
        void nhap()
        {
        cout<<"Nhap gio: ";
        cin>>y;
        cout<<"Nhap phut: ";
        cin>>m;
        cout<<"Nhap giay: ";
        cin>>d;
        }
        void in()
        {
        cout<<y<<" : "<<m<<" : "<<d;
        }
        friend int operator >=(mytime &m1,mytime &m2);
};
int operator >=(mytime &m1,mytime &m2)
{
    if (m1.y>m2.y) return 1;
    if (m1.y==m2.y&&m1.m>m2.m) return 1;
    if (m1.y==m2.y&&m1.m==m2.m&&m1.d>=m2.d) return 1;
    return 0;
};
int main()
{
    mytime M[5],max,min;
    int i;
    for(i=0;i<5;i++)
    {
        cout<<"Nhap phan tu thu: "<<i+1<<"\n";
        M[i].nhap();
    }

    max=M[0];
    for(i=1;i<5;i++)
    if (M[i]>=max) 
        max=M[i];
    cout<<"Thoi gian lon nhat: ";
    max.in();
    min=M[0];
    for(i=1;i<5;i++)
    if (min>=M[i]) 
        min=M[i];
    cout<<"\nThoi gian nho nhat: ";
    min.in();
    getch();
}