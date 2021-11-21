//BAI 2.2
#include<iostream>
using namespace std;
///MYtime
class MyTime{
    protected:
        int gio, phut, giay;
    public:
        MyTime();
        ~MyTime();
        void Nhap();
        void Xuat();
        bool operator > (MyTime x);
};
MyTime::MyTime(){
    this->gio = 0;
    this->phut = 0;
    this->giay = 0;
}
MyTime::~MyTime(){}
void MyTime::Nhap() {
    cout<<"Nhap gio: ";
    cin>>gio;
    cout<<"Nhap phut: ";
    cin>>phut;
    cout<<"Nhap giay: ";
    cin>>giay;
 }
void MyTime::Xuat(){
    cout<<"\n gio:phut:giay : ";
    cout<<gio<<":"<<phut<<":"<<giay<<endl;
}
bool MyTime::operator>(MyTime x){
    if(this->giay > x.giay) 
    return true;
    if((this->giay == x.giay)&&(this->phut > x.phut)) 
    return true;
    if((this->giay == x.giay)&&(this->phut == x.phut)&&(this->gio > x.gio))
    return true;
    else
       return 0;
}

// My Date
class MyDate {
	protected:
		unsigned int ngay, thang, nam;
	public:
		MyDate();
		void Nhap();
		void Xuat();
		friend bool operator > (MyDate x1, MyDate x2);
};

MyDate::MyDate() {
    ngay = 0;
    thang = 0;
    nam = 0;
}

void MyDate::Nhap() {
    cout << "\tNhap ngay: "; cin >> ngay;
    cout << "\tNhap thang: "; cin >> thang;
    cout << "\tNhap nam: "; cin >> nam;
}

void MyDate::Xuat() {
    cout << ngay << "-" << thang << "-" << nam << endl;
}

bool operator > (MyDate x1, MyDate x2) {
    if(x1.nam > x2.nam) 
        return true;
    if(x1.nam == x2.nam && x1.thang > x2.thang) 
        return true;
    if(x1.nam == x2.nam && x1.thang == x2.thang && x1.ngay > x2.ngay)
        return true;
    return false;
}


// My File
class MyFile : public MyTime, public MyDate {
	private:
		char *name;
		int filesize;
	public:
		void Nhap();
		void Xuat();	
	
};

void MyFile::Nhap() {
	MyTime::Nhap();
	MyDate::Nhap();
	cout << "Nhap ten tep: ";
	cin >> name;
	cout << "Nhap kich thuoc tep: ";
	cin >> filesize;
	
}

void MyFile::Xuat() {
	MyTime::Xuat();
	MyDate::Xuat();
	cout << "\tTen tep: " << name << endl;
	cout << "Kich thuoc tep: " << filesize << "MB" << endl;
}

int main() {
	MyFile *y = new MyFile[10];
	MyFile *z[4], *tg;
	char ten[255];
	for (int i=0; i < 4; i++) {
		z[i] = new MyFile;
        z[i]->Nhap();
        z[i]->Xuat();
	}
	
	cout<<"\n ====Xem tep truoc khi sap xep:====";
	for(int i=0; i<4; i++){
	cout<<"\n Doi tuong thu" <<i+1<<":" << endl; z[i]->Xuat();
	}
	for(int i=0;i<5;i++) {
		for(int j=i+1; j<6; j++) {
			if(*z[i]>*z[j]) {
			tg=z[i];
			z[i]=z[j];
			z[j]=tg;
			}
		}
	}
	cout<<"\n ===== Xem tep sau khi sap xep =====";
	for(int i=0; i<5; i++) {
		cout<<"\n Doi tuong thu "<<i+1<<":" << endl; z[i]->Xuat();
	}
	
	
	return 0;
}