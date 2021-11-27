#include <iostream>

using namespace std;


class _Vector{
	private:
	 int n;
	 int *v;
	 public:
	 	_Vector();
	 	~_Vector();
	 	void Nhap();
	 	void Xuat();
	 	void sua();
	 	_Vector operator = (_Vector x);
	 	
	 	
};

_Vector::_Vector(){
	v=new int;
}
_Vector::~_Vector(){
	delete v;
}

void _Vector::Nhap(){
	delete v;
	cout<<"Nhap so phan tu vector: ";
	cin>> n;
	v = new int[n];
	cout<<"\t\tNHAP MANG"<<endl;
	for(int i=0; i<n;i++){
		cout<<"\nNhap phan tu thu ["<<i+1<<"]: ";
		cin>>v[i]; //<==> *(v+1)<<v[0]<<v[1]
	}
}

void _Vector::Xuat(){
	cout<<"\t\tXUAT MANG"<<endl;
		for(int i=0; i<n;i++){
		cout<<"\nphan tu thu ["<<i+1<<"]: "<<v[i];
	}
}
void _Vector::sua(){
//	int vt,gt;
//	cout<<"\nNhap vi tri can sua";
//	cin>>vt;
//	cout<<"\nNhap gia tri can sua";
//	cin>>gt;
//	v[vt-1]=gt;
	//sua nhieu phan tu
	int gt;
	for(int i=0; i<n ; i++){
		if(v[i]<0){
			cin>>gt;
			v[i]=gt;
		}
	}
}

_Vector _Vector::operator =(_Vector x){
	this->n=x.n;
	for(int i=0; i<n;i++){
		this->v[i]= x.v[i];
	}	
	return *this;	
	
}
int main(){
	_Vector v;
	v.Nhap();
	v.Xuat();
	v.sua();
	v.Xuat();
	return 0;
}