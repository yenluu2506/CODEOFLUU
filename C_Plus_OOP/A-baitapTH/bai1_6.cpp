#include<iostream>

using namespace std;

class Phanso
{
    private:
        int tuso;
        int mauso;
    public:
        void nhap();
        Phanso()
        {
        tuso = mauso = 1;
        }
        Phanso(int a, int b)
        {
        tuso = a;
        mauso = b;
        }
        void in();
        friend inline bool operator>(const Phanso &h1, const Phanso &h2);
};

void Phanso::nhap()
{
    do
    {
        cout<<"Nhap tu so, mauso: ";
        cin>>this->tuso>>this->mauso;
        if(this->mauso == 0)
        cout<<"Nhap lai mauso"<<endl;
    }while(this->mauso == 0);
}

void Phanso::in()
{
    cout<<"Phan so: "<<this->tuso<<"/"<<this->mauso<<endl;
}
bool operator>(const Phanso &h1, const Phanso &h2)
{
    float a;
    a = h1.tuso * h2.mauso - h1.mauso * h2.tuso;
    if(a>0) return 1;
    else return 0;
}

int main()
{
//Khoi tao 2 phan so va so sanh >=
    Phanso d1, d2;
    cout<<"Nhap phan so thu 1: "<<endl;
    d1.nhap();
    cout<<"Nhap phan so thu 2: "<<endl;
    d2.nhap();
    d1.in();
    d2.in();

    if(d1 > d2)
        cout<<"d1>d2"<<endl;
    else
        cout<<"d1<d2"<<endl;
    
    system("pause");

    Phanso *p, tmp;
    int n;
    cout <<"Nhap vao gia tri cua n: ";
    cin >> n;
    p = new Phanso[n];
    for(int i = 0; i<5; i++)
    {
        cout<<"Nhap phan so thu "<<i<<": "<<endl;
        p[i].nhap();
    }
    for(int i=0; i<n; i++){
        for(int j=0; i<n; i++){
            if(p[i] < p[j]){
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
    cout << "Mang sap xep tang dan la: ";
    p->in();
}
