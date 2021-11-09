#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
class Mathang{
    private:
            int maMatHang;
            string tenMatHang, tenNhomHang;
            double giaMua, giaBan, loiNhuan;
    public:
            Mathang(){
                this->maMatHang = 0;
                this->tenMatHang = "tenMatHang";
                this->tenNhomHang = "tenNhomHang";
                this->giaMua = 1000.5;
                this->giaBan = 2000.6;
                this->loiNhuan = 1000.1;
            }
            Mathang(int maMatHang, string tenMatHang, string tenNhomHang, double giaMua, double giaBan, double loiNhuan){
                this->maMatHang = maMatHang;
                this->tenMatHang = tenMatHang;
                this->tenNhomHang = tenNhomHang;
                this->giaMua = giaMua;
                this->giaBan = giaBan;
                this->loiNhuan = loiNhuan;
            }
            void setMaMatHang(int a){
                this->maMatHang = a;
            }
            void setLoiNhuan(){
                this->loiNhuan = giaBan-giaMua;
            }
            double getLoiNhuan(){
                return loiNhuan;
            }
            // friend istream &operator>>(istream &input, Mathang &mathang){
            //     fflush(stdin);
            //     getline(cin, mathang.tenMatHang);
            //     fflush(stdin);
            //     getline(cin, mathang.tenNhomHang);
            //     fflush(stdin);
            //     cin>>mathang.giaMua;
            //     cin>>mathang.giaBan;
            // }
            void setName(){
                cin>>tenMatHang;
                cin>>tenNhomHang;
                cin>>giaMua;
                cin>>giaBan;
            }
            void display(){
                cout<<maMatHang<<" "<<tenMatHang<<" "<<tenNhomHang<<" "<<loiNhuan;
            }
};
class MATHANG{
    private:
            vector<Mathang> list;
    public:
            MATHANG(){
                list = vector<Mathang>();
            }
            void add(Mathang mathang){
                this->list.push_back(mathang);
            }
            void sort(){
                for(int i=0;i<list.size()-1;i++){
                    for(int j=i+1; j<list.size();j++){
                        if(list[i].getLoiNhuan()<list[j].getLoiNhuan()){
                            swap(list[i],list[j]);
                        }
                    }
                }
            }
            void display(){
                for(auto i : list){
                    i.display();
                    cout<<endl;
                }
            }
};
int main(){
    Mathang mathang;
    MATHANG arr = MATHANG();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        //cin>>mathang;
        //clock_t startTime = clock();
        mathang.setName();
        mathang.setMaMatHang(i);
        mathang.setLoiNhuan();
        arr.add(mathang);
        //cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    }
    //clock_t startTime = clock();
    arr.sort();
    arr.display();
    //cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
}
