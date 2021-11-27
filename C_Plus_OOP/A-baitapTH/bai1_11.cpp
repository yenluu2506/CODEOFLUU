#include<iostream>
#include<conio.h>
using namespace std;
class ps{
	private:
	 int t;
	 int m;
	public :
	 ps(int tu=0,int mau=0){
		t=tu;
		m=mau;
	 };
	 ~ps(){
	 };
	 void nhap();
	 friend int ucln(int a,int b);
	 void rutgonphanso();
	 void xuat();
	 
	 
};
void ps::nhap(){
	cout<<"nhap tu: ";
	cin>>t;
	do{
	cout<<"\nnhap mau: ";
	cin>>m;
	if(m==0){
		cout<<"\nmau phai khac khong!!! ";
	}
	}while(m==0);
	
}
void ps::xuat(){
	cout<<"\nphan so :";
	cout<<t<<"/"<<m;
}
int ucln(int a,int b){
	if (a%b!=0)
        return ucln(b,(a)%(b));
    else return b;
}
void ps::rutgonphanso(){
	int UCLN=ucln(t,m);
	   t=t/UCLN;
	   m=m/UCLN;
	cout<<t<<"/"<<m;	
}
int main(){
	ps m[5];
	cout<<"nhap cac phan so :";
	for(int i=0;i<5;i++){
		cout<<"\nnhap phan so thu"<<i+1<<":\n";
		m[i].nhap();
	}
	cout<<"\ncac phan so da rut gon: ";
	for(int i=0;i<5;i++){
		cout<<"\nphan so thu"<<i+1<<": ";
		m[i].rutgonphanso();
	}
}
