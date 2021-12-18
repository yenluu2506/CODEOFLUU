#include <bits/stdc++.h>
using namespace std;
 
class Date
{
protected:
    int day, month, year;
 
public:
    Date()
    {
        this->day = this->month = this->year = 0;
    }
    ~Date()
    {
        this->day = this->month = this->year = 0;
    }
    void input()
    {
        cout << "Nhap Ngay: ";
        cin >> this->day;
        cout << "Nhap Thang: ";
        cin >> this->month;
        cout << "Nhap Nam: ";
        cin >> this->year;
    }
    void output()
    {
        cout << "Ngay/Thang/Nam: " << this->day << "/" << this->month << "/" << this->year << endl;
    }
};
//-------------------------------------------------------------//
class Vemaybay
{
protected:
    string tenchuyen;
    Date ngaybay;
    int giave;
 
public:
    Vemaybay()
    {
        this->tenchuyen = "";
        this->giave = 0;
    }
    ~Vemaybay()
    {
        this->tenchuyen = "";
        this->giave = 0;
    }
    void input()
    {
        cin.ignore();
        cout << "Nhap Ten Chuyen: "; fflush(stdin); getline(cin, this->tenchuyen);
        cout << "Nhap Ngay Bay: " << endl;
        ngaybay.input();
        cout << "Nhap Gia Ve: "; cin >> this->giave;
    }
    void output()
    {
        cout << "Ten Chuyen: " << this->tenchuyen << endl;
        cout << "Ngay Bay: " << endl << "\t";
        this->ngaybay.output();
        cout << "Gia Ve: " << this->giave << endl;
    }
    int getgiave()
    {
        return this->giave;
    }
};
 
class Nguoi
{
protected:
    string hoten, gioitinh;
    int tuoi;
 
public:
    Nguoi()
    {
        this->hoten = this->gioitinh = "";
        this->tuoi = 0;
    }
    ~Nguoi()
    {
        this->hoten = this->gioitinh = "";
        this->tuoi = 0;
    }
    void input()
    {
        cin.ignore();
        cout << "Nhap Ho Ten: "; fflush(stdin); getline(cin, this->hoten);
        cout << "Nhap Gioi Tinh: "; fflush(stdin); getline(cin, this->gioitinh);
        cout << "Nhap Tuoi: "; cin >> this->tuoi;
    }
    void output()
    {
        cout << "Ho Ten: " << this->hoten << endl;
        cout << "Gioi Tinh: " << this->gioitinh << endl;
        cout << "Tuoi: " << this->tuoi << endl;
    }
};
 
class Hanhkhach : public Nguoi
{
protected:
    int soluong;
    //Vemaybay *ve;
    Vemaybay ve[1000];
    int tongtien;
 
public:
    Hanhkhach()
    {
        this->soluong = 0;
        //this->ve = new Vemaybay[this->soluong];
        ve[this->soluong];
        tongtien = 0;
    }
    ~Hanhkhach()
    {
        soluong = 0;
        delete []ve;
        tongtien = 0;
    }
    void input()
    {
        Nguoi :: input();
        cout << "Nhap So Luong Ve Hanh Khach Da Mua: "; cin >> this->soluong;
        //ve = new Vemaybay[this->soluong];
        ve[this->soluong];
        for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].input();
            tongtien += ve[i].getgiave();
        }
    }
    void output()
    {
        cout << "- Thong Tin Khach Hang: " << endl;
        Nguoi :: output();
        cout << "- Thong Tin Chuyen Bay: " << endl;
        for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].output();
            cout << endl;
        }
        cout << "==> Tong Tien = " << this->tongtien;
        cout << endl;
    }
 
    bool operator < (const Hanhkhach &obj)
    {
        if (this->tongtien < obj.tongtien) return true;
        else return false;
    }
};
//----------------------------------------------------------//
 
void swap(Hanhkhach &a, Hanhkhach &b)
{
    Hanhkhach temp = a;
    a = b;
    b = temp;
}
 
 
void Bubblesort(Hanhkhach arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
//----------------------------------------------------------//
int main()
{
    cout << "Nhap So Luong Khach Hang: "; int n; cin >> n;
    Hanhkhach *arr = new Hanhkhach[n];
    for (int i = 0; i < n; ++i) arr[i].input();
    cout << endl << endl << "Output" << endl << endl;
    for (int i = 0; i < n; ++i)
    {
        arr[i].output();
        cout << endl << "------------------" << endl << endl;
    }
 
    cout << "After Sort: " << endl;
    Bubblesort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        arr[i].output();
        cout << endl << "------------------" << endl << endl;
    }
    return 0;
}