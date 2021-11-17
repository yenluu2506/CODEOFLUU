#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class vector{
	private:
		int n;
		float *v;
	public:
		vector(int size);
		vector(vector &a);
		~vector();
		void nhap();
		void xuat();
		void operator =(vector &a);
		friend vector operator *(float k,vector &b);
};
vector::vector(int size){
	int i;
	n=size;
	v=new float [n];
}
void vector::nhap(){
	int i;
	for (i=0;i<n;i++){
	cout<<"v["<<i<<"]: ";
	cin>>v[i];
   }
}
vector::vector(vector &a){
	int i;
	n=a.n;
	v=new float [n];
	for (i=0;i<n;i++)
	v[i]=a.v[i];
}
vector::~vector()
{
delete v;
}
void vector::xuat(){
	int i;
	for (i=0;i<n;i++)
	cout<<v[i]<<"       ";
}
void vector:: operator =(vector &a){
	int i;
	n=a.n;
	v=new float [n];
	for (i=0;i<n;i++)
	v[i]=a.v[i];
}
vector operator *(float k,vector &b){
	int i;
	vector c=b;
	for (i=0;i<b.n;i++)
	c.v[i]=k*b.v[i];
    return c;
}

int main(){
	int n;
	float k;
	cout<<"Nhap so phan tu cua vector a: ";cin>>n;
	vector a(n);
	cout<<"\nNhap vector a: "; a.nhap();
	cout<<"vector a: ";a.xuat();
	cout <<" \nnhap vao mot so thuc k :";
	cin>>k;
     cout<<"tich k*vecto a la : ";(k*a).xuat
	 ();

getch();
}
