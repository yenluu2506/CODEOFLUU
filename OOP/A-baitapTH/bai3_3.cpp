#include <iostream>
using namespace std;

class MatHang
{
    protected:
        string Ten;
    public:
        virtual void input()
        {

        }
        virtual void output()
        {

        }
};
class MayTinh : public MatHang
{
    private:
        int speed;
    public:
        void input();
        void output();
};
void MayTinh::input()
{
    cout<<"Nhap ten mat hang: "<<endl;
    getline(cin, Ten);
    cout<<"Nhap toc do cua may tinh: "<<endl;
    cin>>speed;
}
void MayTinh::output()
{
    cout<<"Ten mat hang: "<<Ten<<endl;
    cout<<"Toc do may tinh: "<<speed<<endl;
}
class MayIn : public MatHang
{
    private:
        int DPI;
    public:
        void input();
        void output();
};
void MayIn::input()
{
    cin.ignore(1);
    cout<<"Nhap ten mat hang: "<<endl;
    getline(cin, Ten);
    cout<<"Nhap DPI: "<<endl;
    cin>>DPI;
}
void MayIn::output()
{
    cout<<"Ten mat hang: "<<Ten<<endl;
    cout<<"DPI: "<<DPI<<endl;
}
int main()
{
    MatHang *computer = new MayTinh;
    MatHang *printer = new MayIn;
    computer->input();
    computer->output();
    printer->input();
    printer->output();
}