#include<iostream>
#include<conio.h>
using namespace std;
class SoPhuc {
    private:
        float thuc,ao;
    public:
        SoPhuc() 
        { 
            this->thuc=0; this->ao=0; 
        }
        void set(float,float);
        void hienthi();
        friend ostream& operator<<(ostream& out,const SoPhuc &s);
        friend istream& operator>>(istream& in,SoPhuc &s);

        int operator ==(SoPhuc s2);

};

ostream& operator<<(ostream& out,const SoPhuc &s)
{
    out<<s.thuc<<"+"<<s.ao<<"i"<<endl;
    return out;
}

istream& operator>>(istream& in,SoPhuc &p)
{
    cout<<"\nNhap so phuc: ";
    cin>>p.thuc>>p.ao;
    return in;
}

int SoPhuc::operator==(SoPhuc s2)
{
    if ((this->thuc==s2.thuc)&&(this->ao==s2.ao))
        return 1;
    else 
        return 0;
}
void SoPhuc::set(float t,float a)
{
    this->thuc=t;
    this->ao=a;
}

void SoPhuc::hienthi()
{
    cout<<thuc<<"+"<<ao<<"i"<<endl;
}

int main()
{
    SoPhuc S[300];
    int i,n;
    float thuc,ao;
    cout<<"\nNhap so phan tu: "; cin>>n;
    for (i=0;i<n;i++) cin>>S[i];
    cout<<"\nDay so phuc: \n";
    for (i=0;i<n;i++) cout<<S[i];
    SoPhuc M;
    cout<<"\nNhap M: "; cin>>M;
    for (i=0;i<n;i++)
    if (M==S[i]) cout<<"\nTim thay "<<S[i]<<"\n Vi tri:"<<i+1;
    else cout<<"\t";

    getch();
}
