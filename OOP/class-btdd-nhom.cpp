//Ho va Ten: Bui Thi Yen Luu
//MSV: 6151071011

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//ham nhap so luong nhan vien chinh thuc
int soluong1(int &n){
	cin>>n;
	return n;
}
//ham nhap so luong nhan vien thuc tap
int soluong2(int &n){
	cin>>n;
	return n;
}

class GiangVien{
protected:
    string MaSo;
    string HoTen;
    int Tuoi;
    double Luong;
    bool Check;
public:
    GiangVien();
    ~GiangVien();
    int soluong1(int &n);
    int soluong2(int &n);
    virtual void Nhap(int &);
    virtual void Xuat(int &);
    virtual double TinhLuong() = 0;
    bool Get_KieuGV(){
        return this->Check;
    }
    void Set_KieuGV(bool check){
        this->Check = check;
    }
    string Get_Hoten(){
        return this->HoTen;
    }
    double Get_Luong(){
        return this->Luong = Luong;
    }
};
GiangVien::GiangVien(){
    MaSo = "";
    HoTen = "";
    Tuoi = 0;
    Luong = 0;
}
GiangVien::~GiangVien(){}

void GiangVien::Nhap(int &n){   
    cin.ignore();
    cout << "Nhap ma so: ";
    getline(cin, MaSo);
    cout << "Nhap ho va ten: ";
    getline(cin, HoTen);
    cout << "Nhap tuoi: ";
    cin >> Tuoi;
    cout << "Luong: ";
    cin >> Luong;
}



void GiangVien::Xuat(int &n){
    cout<< "Ma so: "<< MaSo;
    cout<<"Ho va ten: "<< HoTen;
    cout <<"Tuoi: "<< Tuoi;
    cout << "Luong: " << TinhLuong();
    cout<<"\n\n\n";
}

class GiangVienCoHuu : public GiangVien{
   
  private:
    double HeSoLuong;
    int ThamNien;

  public:
    GiangVienCoHuu();
    ~GiangVienCoHuu();
    void Nhap(int &n);
    void Xuat(int &n);
    double TinhLuong();
    
};
GiangVienCoHuu::GiangVienCoHuu(){
    ThamNien = 0;
}

GiangVienCoHuu::~GiangVienCoHuu(){}

double GiangVienCoHuu::TinhLuong(){
    return (Get_Luong() * 1600 + ThamNien*500);
}

void GiangVienCoHuu::Nhap(int &n){
    GiangVien::Nhap(n);
    cout << "Nhap Tham Nien: " << endl;
    cin >> ThamNien;
}


void GiangVienCoHuu::Xuat(int &n){
    GiangVien::Xuat(n);
    cout<< "Tham nien: " <<ThamNien;
    cout <<"Luong: " << TinhLuong();
    cout<<"\n\n\n";
}







class GiangVienThinhGiang : public GiangVien{
private:
    int SoTiet;
    double DonGia;

public:
    GiangVienThinhGiang();
    ~GiangVienThinhGiang();
    void Nhap(int &n);
    void Xuat(int &n);
    double TinhLuong();
};
GiangVienThinhGiang::GiangVienThinhGiang(){
    SoTiet = 0;
    DonGia = 0;
}

GiangVienThinhGiang::~GiangVienThinhGiang(){
}

void GiangVienThinhGiang::Nhap(int &n){
    GiangVien::Nhap(n);
    cout << "Nhap so tiet: " << endl;
    cin >> SoTiet;
    cout << "Nhap don gia: "<< endl;
    cin >> DonGia;
}

void GiangVienThinhGiang::Xuat(int &n){
    GiangVien::Xuat(n);
    cout << "So Tiet: " << SoTiet;
    cout << "Don Gia: " << DonGia;
    cout << "Luong: " << TinhLuong();
    cout<<"\n\n\n";
}

double GiangVienThinhGiang::TinhLuong(){
    return (SoTiet*DonGia);
}

class DanhSachGiangVien{
private:
    vector<GiangVien *> list;

public:
    DanhSachGiangVien();
    ~DanhSachGiangVien();
    void Nhap();
    void Xuat();
    double TongLuongGiangVien();
    void LuongLonNhat();
    void SapxepLuongTangDan();
};

DanhSachGiangVien::DanhSachGiangVien(){
}

DanhSachGiangVien::~DanhSachGiangVien(){
}

void DanhSachGiangVien::Nhap(){
        int i=1,Luachon,n;
         while (i)
        {
        	
        cout << "\n \n   Nhap lua chon: ";
        cin >> Luachon;
        cout<<"1.Nhap giang vien co huu"<<endl;
        cout<<"2.Nhap giang vien thinh giang"<<endl;
        cout<<"3. Thoat";
        GiangVien *x;
        switch (Luachon)
        {
        case 1:  
		  {
            system("cls");
            cout<<"\n\n\n Nhap so luong giang vien co huu: ";
            int a= soluong1(n);
            for(int i=0; i<a; i++){
            x = new GiangVienCoHuu[n];
            x->Nhap(i);
            x->Set_KieuGV(true);
            list.push_back(x);
            }
            
            break;
        }
        case 2:
        {   
            system("cls");
        	cout<<"\n\n\n Nhap so luong giang vien thinh giang: ";
            int b= soluong2(n);
            for(int i=0; i<b; i++){
            x = new GiangVienThinhGiang[n];
            x->Nhap(i);
            x->Set_KieuGV(false);
            list.push_back(x);
            }
			break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}
double DanhSachGiangVien::TongLuongGiangVien(){
    float sum = 0;
    for (int i = 0; i < list.size(); i++)
    {
        sum = sum + list[i]->TinhLuong();
    }
    return sum;
}
void DanhSachGiangVien::Xuat(){   
    system("cls");
    for (int i = 0; i < list.size(); i++){
    	
        if (list[i]->Get_KieuGV() == true)
            list[i]->Xuat(i);
        
    }
    for (int i = 0; i < list.size(); i++){
        
		
		if (list[i]->Get_KieuGV() == false)
            list[i]->Xuat(i);
        
    }
}
void DanhSachGiangVien::LuongLonNhat(){
    float max;
    int temp = 0;
    max = list[0]->TinhLuong();
    for (int i = 1; i < list.size(); i++){
        if (list[i]->TinhLuong() > max){
            max = list[i]->TinhLuong();
            temp = i;
        }
    }
    list[temp]->Xuat(temp);
}
void DanhSachGiangVien::SapxepLuongTangDan(){
    for (int i = 0; i < list.size() - 1; i++){
        for (int j = i + 1; j < list.size(); j++){
            if (list[i]->TinhLuong() > list[j]->TinhLuong()){
                GiangVien *temp;
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
int main()
{	
   DanhSachGiangVien dsgv;
    bool check;
    int Luachon;
    while (true){ 
        cin >> Luachon;
        switch (Luachon)
        {
        case 1:
        {
        	system("cls");
            dsgv.Nhap();
            check = true;
            break;
        }
        case 2:
        {
            if (check)
            {
                dsgv.Xuat();
                system("pause");
            }
            else
            {
                cout << "Ban chua nhap thong tin vao!" << endl;
                system("pause");
            }
            break;
        }
        case 3:
        {          
            dsgv.Xuat();
            cout << "Tong muc luong la: " << (size_t)dsgv.TongLuongGiangVien() << endl;
            system("pause");
            break;
        }
        case 4:
        {
        	system("cls");
            cout << "\n\n giang vien co luong cao nhat la: " << endl;
            dsgv.LuongLonNhat();
            system("pause");
            break;
        }
        case 5:
        {
            cout << "\t\t Xep luong tang dan theo giang vien: " << endl;
            dsgv.SapxepLuongTangDan();
            dsgv.Xuat();
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            cout << "\t\tTam biet!!!" << endl;
            cout << "\t";
            system("pause");
            exit(0);
        }
        default:
        {
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
        }
}
    system("pause");  
    return 0; 
}