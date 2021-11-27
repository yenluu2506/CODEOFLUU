#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class MatHang {
    private:
        string TenMH;
        float DonGia;
        int SoLuong;
    public:
        MatHang();
        ~MatHang();
        void Nhap();
        void Xuat();
        float ThanhTien();
};


//Mat hang
MatHang::MatHang() {
    TenMH = "";
    DonGia = 0;
    SoLuong = 0;
}

MatHang::~MatHang() {}

void MatHang::Nhap() {
    cout << "Nhap ten mat hang: ";
    cin.ignore();
    getline(cin, TenMH);
    cout << "Nhap don gia: ";
    cin >> DonGia;
    cout << "Nhap so luong: ";
    cin >> SoLuong;
}

void MatHang::Xuat() {
    cout << setw(15) << TenMH << setw(18) << DonGia << setw(15) << SoLuong << setw(15) << this->ThanhTien() << endl;
}

float MatHang::ThanhTien() {
    return DonGia*SoLuong;
}

//Hoa don
class HoaDon {
    private:
        string TenHD;
        int SoLuongMH;
        MatHang *MH;
    public:
        HoaDon();
        ~HoaDon();
        void Nhap();
        void Xuat();
        float TongTien();
        string getTenHD();
};

HoaDon::HoaDon() {
    TenHD = "";
    SoLuongMH = 0;
}

HoaDon::~HoaDon() {}

void HoaDon::Nhap() {
    cout << "Nhap ten hoa don: ";
    cin.ignore();
    getline(cin, TenHD);
    cout << "Nhap so luong mat hang: ";
    cin >> SoLuongMH;
    MH = new MatHang[SoLuongMH];
    for(int i=0; i<SoLuongMH; i++) {
        cout << "Nhap mat hang thu " << i+1<< ":" << endl;
        MH[i].Nhap();
    }
}

void HoaDon::Xuat() {
    cout << setw(40) << TenHD << endl;
    cout << "So luong mat hang: " << SoLuongMH << endl;
    cout << setw(20) << "Ten mat hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(15) << "Thanh tien" << endl;
    for(int i=0; i<SoLuongMH; i++) {
        MH[i].Xuat();
    }
    cout << endl;
    cout << setw(60) << "Tong tien: " << this->TongTien() << endl;
}

float HoaDon::TongTien() {
    float Tong = 0;
    for(int i=0; i<SoLuongMH; i++) {
        Tong += MH[i].ThanhTien();
    }
    return Tong;
}

string HoaDon::getTenHD() {
    return TenHD;
}

void Nhap(HoaDon HD[], int n) {
    for(int i=0; i<n; i++) {
        cout << "Nhap hoa don thu " << i+1 << ":" << endl;
        HD[i].Nhap();

    }
}
void Xuat(HoaDon HD[], int n) {
    for(int i=0; i<n; i++) {
        cout << "Thong tin hoa don thu " << i+1 << ":" << endl;
        HD[i].Xuat();
        cout << endl;
    }
}

void MaxMin(HoaDon HD[], int n) {
   
        HoaDon Max = HD[0];
        for(int i=1; i<n; i++) {
            if(HD[i].TongTien() > Max.TongTien())
                Max = HD[i];
        }
        Max.Xuat();
        HoaDon Min = HD[0];
        for(int i=1; i<n; i++) {
            if(HD[i].TongTien() < Min.TongTien())
                Min = HD[i];
        }
        Min.Xuat();
    
}

void TimKiem(HoaDon HD[], int n) {
    string Ten;
    cout << "Nhap ten hoa don can tim: ";
    cin.ignore();
    getline(cin, Ten);
    for(int i=0; i<n; i++) {
        if(HD[i].getTenHD() == Ten) {
            HD[i].Xuat();
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong hoa don: ";
    cin >> n;
    HoaDon *HD;
    HD = new HoaDon[n];
    Nhap(HD, n);
    Xuat(HD, n);
    MaxMin(HD, n);
    TimKiem(HD, n);
    }