//Ho va ten: Bui Thi Yen Luu
//MSV: 6151071011

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class MH{
    private:
        string tmh;
        int sl;
        float dg;
    public:
        MH();
        ~MH();
        void nhap();
        void In();
        float tien();
};

MH::MH(){
    tmh = "";
    sl = 0;
    dg = 0;
}

MH::~MH(){

}

void MH::nhap(){
    cout << "Nhap ten mat hang: ";
    fflush(stdin);
    getline(cin, tmh);
    cout << "Nhap so luong: ";
    cin >> sl;
    fflush(stdin);
    cout << "Nhap don gia: ";
    cin >> dg;
}

void MH::In(){
    cout << setw(10) << tmh << setw(15) << sl << setw(15) << dg << setw(15) << this->tien() << endl;
}

float MH::tien(){
    return sl*dg;
}

class HD{
private:
    string thd;
    MH *dsmh;
    int slmh;
public:
    HD();
    ~HD();
    void nhap();
    void In();
    float tongt(float *t, int n);
    float tien();
    string getThd();
};

HD::HD(){
    thd = "";
    slmh = 0;
}

HD::~HD(){

}

void HD::nhap(){
    cout << "Nhap ten hoa don: ";
    fflush(stdin);
    getline(cin, thd);
    cout << "Nhap so luong mat hang: ";
    cin >> slmh;
    fflush(stdin);
    dsmh = new MH[slmh];
    for(int i=0; i<slmh; i++) {
        cout << "Nhap mat hang thu " << i+1<< ":" << endl;
        dsmh[i].nhap();
    }
}

void HD::In(){
    float *t;
    int n;
    cout << setw(30) << thd << endl;
    cout << "So luong mat hang: " << slmh << endl;
    cout << setw(10) << "Ten mat hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(15) << "Thanh tien" << endl;
    for(int i=0; i<slmh; i++) {
        dsmh[i].In();
    }
    cout << endl;
    cout << setw(20) << "Tong tien: " << this->tongt(t, n) << endl;
}

float HD::tien(){
    float t;
    t=dsmh->tien();
    return t;
}

float HD::tongt(float *t, int n){
    float tong = 0;
    for(int i=0; i<slmh; i++) {
        *t=tien();
        tong+=*t;
    }
    return tong;
}

string HD::getThd(){
    return thd;
}

void nhap(HD hd[], int n){
    for(int i=0; i<n; i++) {
        cout << "Nhap hoa don thu " << i+1 << ":" << endl;
        hd[i].nhap();

    }
}
void In(HD hd[], int n){
    for(int i=0; i<n; i++) {
        cout << "Thong tin hoa don thu " << i+1 << ":" << endl;
        hd[i].In();
        cout << endl;
    }
}

void MaxMin(HD hd[], int n){
    float *t;
    HD Max = hd[0];
    for(int i=1; i<n; i++) {
        if(hd[i].tongt(t,n) > Max.tongt(t, n))
            Max = hd[i];
    }
    Max.In();
    HD Min = hd[0];
    for(int i=1; i<n; i++) {
        if(hd[i].tongt(t, n) < Min.tongt(t, n))
            Min = hd[i];
    }
    Min.In();
}

void timkiem(HD hd[], int n){
	string tenhoadon;
	int j=1;
	fflush(stdin);
	cout<<"Nhap ten hoa don: "<< endl;
	getline(cin,tenhoadon);
	for(int i=0;i<n;i++){
		if(hd[i].getThd()==tenhoadon){
			hd[i].In();
		}else j++;
	}
	fflush(stdin);
	if(j>=n-1){
		cout<<"Khong co hoa don can tim"<< endl;
	}
}

int main(){
    HD *hd;
    int n;
    cout << "Nhap so luong hoa don: ";
    cin >> n;
    hd = new HD[n];
    nhap(hd, n);
    In(hd, n);
    cout<<"Hoa don co gia lon nhat, nho nhat la: "<<endl;
    MaxMin(hd, n);
    cout<<"Tim kiem hoa don"<< endl;
    timkiem(hd, n);
    return 0;
}