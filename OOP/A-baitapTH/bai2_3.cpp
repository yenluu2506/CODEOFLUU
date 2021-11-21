#include <iostream>
using namespace std;

class SV {
    protected:
        string Lop, HoTen;
    public:
        SV();
        ~SV();
        void Nhap();
        void Xuat();
};

class SVSP : public SV {
    protected:
        float DTB;
        string HocBong;
    public:
        SVSP();
        void Nhap();
        void Xuat();
}; 

class SVCN : public SVSP {
    private:
        long HocPhi;
    public:
        SVCN();
        void Nhap();
        void Xuat();
};

//Sinh vien
SV::SV() {
    this->Lop = "";
    this->HoTen = "";
}
SV::~SV() {}

void SV::Nhap() {
    cout << "\tNhap lop: ";
    cin.ignore();
    getline(cin, Lop);
    cout << "\tNhap ho va ten: ";
    getline(cin, HoTen);
}

void SV::Xuat() {
    cout << "\tLop: " << Lop << endl;
    cout << "\tHo va ten: " << HoTen << endl;
}

//Sinh vien su pham
SVSP::SVSP() {
    this->DTB = 0;
    this->HocBong = "";
}

void SVSP::Nhap() {
    SV::Nhap();
    cout << "\tNhap diem trung binh: ";
    cin >> DTB;
    cout << "\tNhap loai hoc bong: ";
    cin.ignore();
    getline(cin, HocBong);
}

void SVSP::Xuat() {
    SV::Xuat();
    cout << "\tDiem trung binh: " << DTB << endl;
    cout << "\tHoc bong: " << HocBong << endl;
}

//Sinh vien cu nhan
SVCN::SVCN() {
    this->HocPhi = 0;
}

void SVCN::Nhap() {
    SVSP::Nhap();
    cout << "\tNhap hoc phi: ";
    cin >> HocPhi;
}

void SVCN::Xuat() {
    SVSP::Xuat();
    cout << "\tHoc phi: " << HocPhi << endl;
}

int main() {
    SVCN *sv[3];
    for(int i=0; i<3; i++) {
        sv[i] = new SVCN;
        cout << "Nhap thong tin sinh vien thu " << i+1 << ": " << endl;
        sv[i]->Nhap();
    }
    cout << "\nThong tin nhan vien: " << endl;
    SVCN *x = sv[0];
    x->Xuat();
}
