#include <iostream>

using namespace std;

void CD(int n){
    if(n>0){
        int du=n%2;
        n=n/2;
        //goi de qui luu so du vao stack
        CD(n);
        //goi stack lay so du ra
        cout << du;
    }
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    CD(n);
}