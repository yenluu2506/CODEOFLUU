//ho va ten: Bui Thi Yen Luu
//msv: 6151071011
#include <iostream>
#include <string>

using namespace std;

class hocsinh {
private:
	string name;
	double diemvan, diemtoan;
public:
    hocsinh();
    hocsinh(string name, double diemvan, double diemtoan);
    hocsinh(const hocsinh &hs);
    ~hocsinh();
	string getname();
	void setname(string name);
	double getdiemvan();
	void setdiemvan(double diemvan);
	double getdiemtoan();
	void setdiemtoan(double diemtoan);
	friend istream & operator>>(istream &vao, hocsinh&hs);
    friend ostream& operator <<(ostream &ra, const hocsinh hs);
	double dtb();
    bool operator > (hocsinh hs);
    bool operator < (hocsinh hs);
    bool operator == (hocsinh hs);
    bool operator >= (hocsinh hs);
    bool operator <= (hocsinh hs);
    bool operator != (hocsinh hs);
    bool operator = (hocsinh hs);
};
hocsinh::hocsinh(){
    name = "Null";
    diemvan = 0;
    diemtoan = 0;
}
hocsinh::hocsinh(string name, double diemvan, double diemtoan){
    this->name = name;
    this-> diemvan = diemvan;
    this-> diemtoan = diemtoan;
}
hocsinh::hocsinh(const hocsinh &hs){
    name = hs.name;
    diemvan = hs.diemvan;
    diemtoan = hs.diemtoan;
}    
hocsinh::~hocsinh(){

}
string hocsinh::getname() {
	return name;
}
void hocsinh::setname(string name) {
	this->name = name;
}
double hocsinh::getdiemvan() {
	return diemvan;
}
void hocsinh::setdiemvan(double diemvan) {
	this->diemvan = diemvan;
}
double hocsinh::getdiemtoan() {
	return diemtoan;
}
void hocsinh::setdiemtoan(double diemtoan) {
	this->diemtoan = diemtoan;
}
istream& operator >> (istream &vao, hocsinh &hs){
    cout << "nhap thong tin hoc sinh: " << endl;
	cout << "ho va ten: ";
	getline(vao, hs.name);
	while (true) {
		cout << "diem van: ";
		vao >> diemvan;
		cout << "diem toan: ";
		vao >> diemtoan;
		if (diemtoan > 10 || diemvan > 10 || diemtoan < 0 || diemvan < 0) {
			cout << "Nhap lai ";
		}
		else break;
	}
    return vao;
}
friend ostream& operator <<(ostream &ra, const hocsinh hs){
    cout << endl;
	// cout << "thong tin sinh vien da nhap. " << endl;
	cout << "ho va ten: " << ra.name << endl;
	cout << "diem van: " << ra.diemvan << endl;
	cout << "diem toan: " << ra.diemtoan << endl;
}
void nhap(int n, hocsinh a[]){
    for(int i=0; i<n; i++){
        cout <<"Nhap hoc sinh thu "<<i+1<<":"<< endl;
        cin>>a[i];
    }
}
void xuat(int n, hocsinh a[]){
    cout<<"*********************";
    for(int i=0; i<n; i++){
        cout <<"Hoc sinh thu"<<i+1<<":"<<endl<<a[i]<<endl;
    }
}
double hocsinh::dtb(){
	return (diemtoan+diemvan)/2;
}
bool hocsinh::operator > (hocsinh hs){
    if(dtb()>hs.dtb())
        return true;
    else 
        return false;
}
bool hocsinh::operator < (hocsinh hs){
    if(dtb()>hs.dtb())
        return true;
    else 
        return false;
}
 bool hocsinh::operator == (hocsinh hs){
     if(dtb()==hs.dtb())
        return true;
    else 
        return false;
}
bool hocsinh::operator >= (hocsinh hs){
    if(dtb()>=hs.dtb())
        return true;
    else 
        return false;
}
bool hocsinh::operator <= (hocsinh hs){
    if(dtb()<=hs.dtb())
        return true;
    else 
        return false;
}
bool hocsinh::operator != (hocsinh hs){
    if(dtb()!=hs.dtb())
        return true;
    else 
        return false;
}
bool hocsinh::operator = (hocsinh hs){
    if(dtb()=hs.dtb())
        return true;
    else 
        return false;
}
int main() {
	hocsinh a[100];
    int n;
    cout<<"Nhap so hoc sinh: ";
    cin>> n;
    nhap(n,a);
    xuat(n,a);
    // hocsinh a("A", 2.4, 8.4);
    // hocsinh b("B", 7.6, 7.8);
    if(a>b) cout <<"Lon hon"<< endl;
    if(a<b) cout <<"Be hon"<< endl;
    if(a==b) cout <<"bang hon"<< endl;
    if(a>=b) cout <<"Lon hon hoac bang"<< endl;
    if(a<=b) cout <<"Be hon hoac bang"<< endl;
    if(a!=b) cout <<"Khac"<< endl;

    return 0;
}