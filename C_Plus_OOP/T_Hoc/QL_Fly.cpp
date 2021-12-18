#include <iostream>
using namespace std;

class Date{
    private:
        int date, month, year;
    public:
        Date();
        ~Date();
        void nhap();
        void xuat();
};
Date::Date(){
    date = 0;
    month = 0;
    year = 0;
}
Date::~Date(){}
void Date::nhap(){
    cout << "Nhap ngay: ";
    cin >> date;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;
}
void Date::xuat(){
    cout << "Ngay " << date << " Thang " << month << " Nam "<< year;
}
class Vemaybay {
    private:
        string tenchuyen;
        Date ngaybay;
        double giave;
    public:
     Vemaybay();
     ~Vemaybay();
    void nhap();
    void xuat();
    double getGiave();
    void setGiave();
};
Vemaybay::Vemaybay(){
    tenchuyen = "";
    giave = 0;
}
Vemaybay::~Vemaybay(){}
void Vemaybay::nhap(){
    cout << "Nhap ten chuyen bay: ";
    fflush(stdin);
    getline(cin, tenchuyen);
    cout << "Nhap ngay bay: ";
    cin.ignore();
    ngaybay.nhap();
    cout << "Nhap gia ve: ";
    cin.ignore();
    cin >> giave;
}
void Vemaybay::xuat(){
    cout << "Ten chuyen bay: "<< tenchuyen << endl;
    cout << "Ngay bay: " << endl;
    this->ngaybay.xuat();
    cout << "Gia ve: " << giave<<endl;
}
double Vemaybay::getGiave(){
    return giave;
}
void Vemaybay::setGiave(){
    this->giave = giave;
}

class Nguoi{
    protected:
        string hoten;
        string gioitinh;
        int tuoi;
    public:
        Nguoi();
        ~Nguoi();
        void nhap();
        void xuat();
};

Nguoi::Nguoi(){
    hoten = "";
    gioitinh = "";
    tuoi = 0;
}

Nguoi::~Nguoi(){

}

void Nguoi::nhap(){
    cout << "Nhap ho va ten: ";
    cin.ignore();
    getline(cin, hoten);
    cout << "Nhap gioi tinh: ";
    cin.ignore();
    getline(cin, gioitinh);
    cout << "Nhap tuoi: ";
    cin.ignore();
    cin >> tuoi;
}

void Nguoi::xuat(){
    cout << "Ho va Ten: "<< hoten<<endl;
    cout << "Gioi tinh: "<< gioitinh<< endl;
    cout << "Tuoi: "<< tuoi << endl;
}

class HanhKhach : public Nguoi{
    private:
        Vemaybay *ve;
        int soluong;
        int tongtien;
    public:
        HanhKhach();
        ~HanhKhach();
        void nhap();
        void xuat();
        bool operator < (const HanhKhach &hk);
};
HanhKhach::HanhKhach(){
    *(ve + soluong);
    soluong = 0;
    tongtien = 0;
}
HanhKhach::~HanhKhach(){

}
void HanhKhach::nhap(){
    Nguoi::nhap();
    cout << "Nhap so luong ve hanh khach da mua: ";
    cin >> soluong;
    *(ve + soluong);
    for(int i=0; i<soluong; i++){
        ve[i].nhap();
        tongtien += ve[i].getGiave();
    }
}
void HanhKhach::xuat(){
    cout << "Thong tin hanh khach"<<endl;
    Nguoi::xuat();
    cout << "Thong tin chuyen bay" << endl;
    for(int i=0; i<soluong; i++){
        ve[i].xuat();
    }
    cout << "Tong tien"<< this->tongtien;
}
bool HanhKhach::operator < (const HanhKhach &hk){
    if(this->tongtien < hk.tongtien)
        return true;
    else return false;
}
void swap(HanhKhach &a, HanhKhach &b){
    HanhKhach temp = a;
    a = b;
    b = temp;
}
void BubbleSort(HanhKhach HK[], int n){
    for(int i = 0; i<n; i++){
        for (int j = 0; j<n-i-1; j++){
            if(HK[i]<HK[j+1]){
                swap(HK[i], HK[j+1]);
            }
        }
    }
}
int main(){
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    HanhKhach *HK = new HanhKhach[n];
    for(int i=0; i<n; i++){
        HK[i].nhap();
    }
    for(int i=0; i<n; i++){
        HK[i].xuat();
    }
    cout << "Bubble Sort";
    BubbleSort(HK, n);
    for(int i=0; i<n; i++){
        HK[i].xuat();
    }
}