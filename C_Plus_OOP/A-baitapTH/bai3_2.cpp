#include <iostream>
#include <string>
using namespace std;

class SV
{
    protected:
        string room, fullName;
    public:
        virtual void input()
        {

        }
        virtual void output()
        {

        }
};
class SVSP : public SV
{
    private:
        string scholarship;
    public:
        void input();
        void output();
};

void SVSP::input()
{
    cout<<"Nhap lop hoc: "<<endl;
    getline(cin, room);
    cout<<"Nhap ho va ten: "<<endl;
    getline(cin, fullName);
    cout<<"Nhap hoc bong: "<<endl;
    getline(cin, scholarship);
}
void SVSP::output()
{
    cout<<"Lop hoc: "<<room<<endl;
    cout<<"Ho va ten: "<<fullName<<endl;
    cout<<"Hoc bong: "<<scholarship<<endl;
}

class SVTC : public SV
{
    private: 
        long int tuition;
    public:
        void input();
        void output();
};

void SVTC::input()
{
    cout<<"Nhap lop hoc: "<<endl;
    getline(cin, room);
    cout<<"Nhap ho va ten: "<<endl;
    getline(cin, fullName);
    cout<<"Nhap hoc phi: "<<endl;
    cin>>tuition;
}
void SVTC::output()
{
    cout<<"Lop hoc: "<<room<<endl;
    cout<<"Ho va ten: "<<fullName<<endl;
    cout<<"Hoc phi: "<<tuition<<endl;
}

int main()
{
    SV *svsp = new SVSP;
    SV *svtc = new SVTC;
    svsp->input();
    svsp->output();
    svtc->input();
    svtc->output();
}