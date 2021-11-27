#include<iostream>
#include<conio.h>
using namespace std;
class mydate{
	private:
	 int d,m,y;
	public:
	 mydate(int dd=0,int mm=0,int yy=0){
  		d=dd; m=mm; y=yy; 
		}
 	 void nhap(){
       cout<<"Nhap ngay: ";cin>>d;
       cout<<"Nhap thang: ";cin>>m;
       cout<<"Nhap nam: ";cin>>y;
	   }
 	 void in(){
       cout<<d<<" - "<<m<<" - "<<y;
	   }
      friend int operator > (mydate &m1 , mydate &m2);
};
int operator >(mydate &m1,mydate &m2){
	if (m1.y>m2.y) return 1;
	if (m1.y==m2.y){
		if(m1.m>m2.m){
			return 1;
		}
		if (m1.m==m2.m){
		if(m1.d>m2.d) return 1;	
		} 
		}
	return 0;
};
void sapxep(mydate *M, int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(*(M+i)>*(M+j)){
				mydate m=*(M+i);
				*(M+i)=*(M+j);
				*(M+j)=m;
			}
		}
	}
	cout <<"\ncac ngay da duoc xap xep :";
	for(int i=0;i<n;i++){
 		cout<<"\nngay thu "<<i+1<<":";
 		(M+i)->in();
 	}
}
int  main(){
	int n ;
	cout<<"nhap so ngay thang nam ma ban muon nhap: ";
	cin>>n;
	mydate *M=new mydate[n];
	for(int i=0;i<n;i++){
	cout<<"Nhap ngay thu: "<<i+1<<"\n";
	(M+i)->nhap();
	}
	cout<<"\nCac ngay vua nhap la: ";
	for(int i=0;i<n;i++){
	cout<<"\nngay thu "<<i+1<<":";
	(M+i)->in();
	}
	sapxep(M,n);
	getch();
}