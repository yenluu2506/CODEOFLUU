#include <iostream>
using namespace std;

class SV {
    protected:
        string Lop;
        string Hoten;
    public:
        SV();
        ~SV();
        void XuatThongtin();
};
SV::SV(){
    Lop = "";
    Hoten = "";
}
SV::~SV(){}
void SV::XuatThongtin(){
    cout << "Lop: " << Lop ;
    cout << "Ho ten: " << Hoten ;
}
class SVTC : public SV{
    protected:
        double hocphi;
    public:
        SVTC();
        ~SVTC();
};
SVTC::SVTC(){
    Lop = "";
    Hoten = "";
    hocphi = 0;
}
SVTC::~SVTC(){}

class SVCN : public SVTC{
    private:
        float Hocbong;
        float Dtb;
    public:
        SVCN();
        void Nhap ();
        void Xuat();
        bool operator > (SVCN &a);
        void sapxep();
};
SVCN::SVCN(){
    Lop = "";
    Hoten = "";
    hocphi = 0;
    Hocbong = 0;
    Dtb = 0;
}
void SVCN::Nhap(){
    fflush(stdin);
    cout << "Nhap Lop: ";
    getline(cin,Lop);
    cout << "Nhap Ten: ";
    getline(cin,Hoten);
    cout << "Nhap Hoc phi: ";
    cin >> hocphi;
    cout << "Nhap Hoc Bong: ";
    cin >> Hocbong;
    cout << "Nhap Diem TB: ";
    cin >> Dtb;
}
void SVCN::Xuat(){
    cout << "Lop: "<<Lop<<" Ho va Ten: "<< Hoten <<" Hoc Phi: "<< hocphi<<" Hoc bong: "<< Hocbong << " Diem TB: " << Dtb<<endl;
}
bool SVCN::operator > (SVCN &a){
    if (Dtb > a.Dtb)
        return true;
}

void SVCN::sapxep(){
    SVCN *a;
    SVCN tmp;
    for(int i=0; i < 3; i++){
        for(int j=i+1; j < 4; j++){
            if ((a+i) > (a+j)){
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
        }
    }
    Xuat();
}
int main (){
    SVCN *a= new SVCN[3];
    SVCN p;
    for(int i = 0; i < 3; i++){
        cout << endl<< "Thong tin "<< i+1 << endl;
        (a+i)->Nhap();
    }
    for(int i = 0; i < 3; i++){
        cout << endl<< "Thong tin "<< i+1 << endl;
        (a+i)->Xuat();
    }
    cout<< endl;
    p.sapxep();
    return 0;
}