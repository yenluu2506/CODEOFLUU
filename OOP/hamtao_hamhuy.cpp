#include <iostream>
using namespace std;
class phanso{
    private:
        int tu, mau;
    public:
        phanso();//ham tao mac dinh
        phanso(int tu, int mau);//ham tao day du tham so
        phanso(int x);//ham tao khong day du tham so
        phanso(const phanso &x);//ham tao sao chep nen chen tham chieu hang
        void xuat();
        phanso tong(phanso ps);
        ~phanso();//ham huy
};
phanso::~phanso(){
//     delete tu;
}
phanso::phanso(){
    tu =0; 
    mau=1;
}
phanso::phanso(int tu, int mau){
    this->tu=tu;
    this->mau=mau;
}
phanso::phanso(int x){
    tu = x;
    mau = x;
}
phanso::phanso(const phanso &x){
    tu=x.tu;
    mau=x.mau;
}
phanso::phanso(phanso ps){
    // phanso t;
	// t.tu = tu * p.mau + mau * p.tu;
	// t.mau = mau * p.mau;
	// return t;
    return phanso(tu * p.mau + mau * p.tu,mau * p.mau);
}
void phanso::xuat(){
    cout << tu << "/" << mau<< endl;
}
int main(){
    phanso a(3/2), b(2,4);
    // cout<<"Phan so a: ";
    // a.xuat();
    // cout <<"Phan so b: ";
    // b.xuat();
    // cout <<"Phan so c: ";
    cout<<"tong la:";
    (a.tong(b)).xuat();
    // c.xuat();
}