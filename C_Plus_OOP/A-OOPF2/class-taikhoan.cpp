//Ho va Ten: Bui Thi Yen Luu
//MSV: 6151071011

#include <iostream>
using namespace std;

class TaiKhoan  {
    private:
         float  m_fSoDu = 0;
    public:
        float baoSoDu() {   
            return m_fSoDu; 
        }
        void napTien(float fSoTien) {   
            m_fSoDu += fSoTien;  
        }
        void rutTien(float fSoTien)  {
        if (fSoTien <= m_fSoDu)
                m_fSoDu -= fSoTien;
        }  
};

class TaiKhoanTietKiem: public TaiKhoan{
    private:
        int kyhan;
        float laisuat;
        int sothang;
    public:
        void input();
        void napTienTietKiem();
        void rutTienKyHan();
        void tangThang();
        float soDuHienTai();
};
void TaiKhoanTietKiem::input(){
    cout << "Tang ky han gui them: ";
    cin >> kyhan;
    sothang = kyhan;
}
void TaiKhoanTietKiem::napTienTietKiem(){
    float fsoTien;
    cout << "Nhap so tien can nap: ";
    cin >> fsoTien;
    napTien(fsoTien);
    sothang = 0;
}
void TaiKhoanTietKiem::rutTienKyHan(){
    if(sothang < kyhan){
        cout << "Chua den han"<<endl;
        return;
    }
    else{
        float fsoTien;
        cout << "Nhap so tien can rut: ";
        cin >> fsoTien;
        if(fsoTien <= baoSoDu()){
            rutTien(fsoTien);
            cout <<"Rut thanh cong."<< fsoTien <<endl;
        }
        else{
            cout<<"Khong du so du."<< endl;
        }
    }
}
void TaiKhoanTietKiem::tangThang(){
    cout << "Ky han gui: ";
    cin >> kyhan;
    sothang += kyhan;
}
float TaiKhoanTietKiem::soDuHienTai(){
    return baoSoDu();
}
int main(){
    TaiKhoanTietKiem tktk;
    tktk.input();
    tktk.napTienTietKiem();
    tktk.tangThang();
    tktk.rutTienKyHan();
    cout << "So du: " << tktk.soDuHienTai() << endl;
}
