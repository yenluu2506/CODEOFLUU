#include <bits/stdc++.h>
using namespace std;

class VanDongVien{
    protected:
        string hoten;
        int tuoi;
        string monthidau;
        double cannang, chieucao;
    public:
        VanDongVien();
        VanDongVien(string hoten, int tuoi, string monthidau, double cannang, double chieucao);
        ~VanDongVien();
        friend istream& operator >> (istream &nhap, VanDongVien &vdv);
        friend ostream& operator >> (ostream &xuat, VanDongVien vdv);
        bool operator > (const VanDongVien &vdv);
};

VanDongVien::VanDongVien(){
    this->hoten = this->monthidau = "";
    this->tuoi = 0;
    this->cannang = this->chieucao = 0;
}

VanDongVien::VanDongVien(string hoten, int tuoi, string monthidau, double cannang, double chieucao){
    this->hoten = hoten;
    this->tuoi = tuoi;
    this->monthidau = monthidau;
    this->cannang = cannang;
    this->chieucao = chieucao;
}

VanDongVien::~VanDongVien(){
    this->hoten = this->monthidau = "";
    this->tuoi = 0;
    this->cannang = this->chieucao = 0;
}

istream& operator >> (istream &nhap, VanDongVien &vdv){
    cout << "Nhap ten: ";
    nhap >> vdv.hoten;
    cout << "Nhap tuoi: ";
    nhap>> vdv.tuoi;
    cout << "Nhap mon thi dau: ";
    nhap >> vdv.monthidau;
    cout << "Nhap can nang: ";
    nhap >> vdv.cannang;
    cout << "Nhap chieu cao: ";
    nhap >> vdv.chieucao;
}

ostream& operator >> (ostream &xuat, VanDongVien vdv){
    xuat << "Ho ten: "<< vdv.hoten;
    xuat << "Tuoi" << vdv.tuoi;
    xuat << "Mon thi dau: "<< vdv.monthidau;
    xuat << "Can nang: " << vdv.cannang;
    xuat << "Chieu cao: " << vdv.chieucao;
}

bool VanDongVien::operator> (const VanDongVien &vdv){
    if (this->chieucao > vdv.chieucao){
        return true;
    }
    else if (this->chieucao < vdv.chieucao){
        return false;
    }
    else if (this->cannang > vdv.cannang){
        return true;
    }
    else{
        return false;
    }
}

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSort(VanDongVien VDV[], int n){
    for(int i = 0; i<n; i++){
        for (int j = 0; j<n-i-1; j++){
            if (VDV[i]>VDV[j+1]){
                swap(VDV[i], VDV[j+1]);
            }
        }
    }
}

int main(){
    VanDongVien p("Yen Luu", 19, "Cau Long",  41.5, 1.58);
    cout << p;

    int n;
    cout << "Nhap so luong van dong vien: ";
    cin >> n;
    VanDongVien *VDV = new VanDongVien[n];
    for(int i=0; i<n; i++){
        cin >> VDV [i];
    }
    for(int i=0; i<n; i++){
        cout <<  VDV [i] << endl;
    }
    cout << "Bubble Sort: ";
    BubbleSort(VDV, n);
    for(int i=0; i<n; i++){
        cout << VDV[i] << endl;
    }
}