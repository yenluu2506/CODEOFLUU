//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include<bits/stdc++.h>
using namespace std;
 
struct ToaDo{
    float x, y;
};
void enter(ToaDo *a){
    cout<<"\nNhap hoanh do: ";
    cin>>a->x;
    cout<<"\nNhap tung do: ";
    cin>>a->y;
}
void enterList(ToaDo *a,int &n){
    cout<<"\nNhap so diem toa do: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nNhap toa do thu "<<i+1<<":";
        enter(&*(a+i));
    }
}
void print(ToaDo *a){
    cout<<"("<<a->x<<","<<a->y<<")"<<"; ";
}
float length(ToaDo *a){
    return sqrt(pow(a->x,2)+pow(a->y,2));
}

void sort(ToaDo *a, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(length((a+j)) > length((a+j+1))){
                swap(*(a+j),*(a+j+1));
            }
        }
    }
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

void find(ToaDo *a, int n, int R){
    cout<<"\nCac diem nam trong duong tron tam O ban kinh R: "<<endl;
    for(int i=0;i<n;i++){
        if(length((a+i))<R) print(a+i);
    }
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

void findX(ToaDo *a, int n){
    for(int i=0;i<n;i++){
        if(((a+i)->x>0 && (a+i)->y>0) || ((a+i)->x<0 && (a+i)->y>0)) print(a+i);
    }
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

void findD(ToaDo *a, int n, int d){
    int dem=0;
    for(int i=0;i<n;i++){
        if(length(a+i) == d) {
            print(a+i);
            dem++;
        }
    }
    if(dem==0) cout<<"\nKhong co diem nao bang d";
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int main(){
    int n;
    ToaDo *a=new ToaDo[n];
    enterList(a,n);
    sort(a,n);
    float R;
    cout<<"\nNhap ban kinh duong tron tam O: ";
    cin>>R;
    find(a,n,R);
    cout<<"\nCac diem nam 2 phia ben tren truc hoanh: ";
    findX(a,n);
    float d;
    cout<<"\nNhap d: ";
    cin>>d;
    cout<<"\nCac diem co khoanh cach bang d: ";
    findD(a,n,d);
    delete[] a;
    return 0;
}