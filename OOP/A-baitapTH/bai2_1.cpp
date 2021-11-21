#include <iostream>
using namespace std;

// My Attr
class MyAttr {
	protected:
		int attr;
	public:
		MyAttr();
		MyAttr(int attr);
		void Input();
		void Output();
		
};

MyAttr::MyAttr(){
	attr = 0;
}

MyAttr::MyAttr(int attr) {
	this->attr = attr;
}

void MyAttr::Input() {
	cout << "Nhap so hieu tep: ";
	cin >> attr;
}

void MyAttr::Output() {
	cout << "So hieu tep: " << attr << endl;
}

// My Date
class MyDate {
	protected:
		unsigned int ngay, thang, nam;
	public:
		MyDate();
		void Input();
		void Output();
		friend bool operator > (MyDate x1, MyDate x2);
};

MyDate::MyDate() {
    ngay = 0;
    thang = 0;
    nam = 0;
}

void MyDate::Input() {
    cout << "\tNhap ngay: "; cin >> ngay;
    cout << "\tNhap thang: "; cin >> thang;
    cout << "\tNhap nam: "; cin >> nam;
}

void MyDate::Output() {
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
class MyFile : public MyAttr, public MyDate {
	private:
		char *name;
		int filesize;
	public:
		void _Input();
		void _Output();	
	
};

void MyFile::_Input() {
	MyAttr::Input();
	MyDate::Input();
	cout << "Nhap ten tep: ";
	cin >> name;
	cout << "Nhap kich thuoc tep: ";
	cin >> filesize;
	
}

void MyFile::_Output() {
	MyAttr::Output();
	MyDate::Output();
	cout << "\tTen tep: " << name << endl;
	cout << "Kich thuoc tep: " << filesize << "MB" << endl;
}

int main() {
	MyFile *y = new MyFile[10];
	MyFile *z[4], *tg;
	char ten[255];
	for (int i=0; i < 4; i++) {
		z[i] = new MyFile;
        z[i]->_Input();
        z[i]->_Output();
	}
	
	cout<<"\n ====Xem tep truoc khi sap xep:====";
	for(int i=0; i<4; i++){
	cout<<"\n Doi tuong thu" <<i+1<<":" << endl; z[i]->_Output();
	}
	for(int i=0;i<3;i++) {
		for(int j=i+1; j<4; j++) {
			if(*z[i]>*z[j]) {
			tg=z[i];
			z[i]=z[j];
			z[j]=tg;
			}
		}
	}
	cout<<"\n ===== Xem tep sau khi sap xep =====";
	for(int i=0; i<4; i++) {
		cout<<"\n Doi tuong thu "<<i+1<<":" << endl; z[i]->_Output();
	}
	
	
	return 0;
}
