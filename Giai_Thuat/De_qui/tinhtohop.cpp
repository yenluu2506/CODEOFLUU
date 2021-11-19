#include <iostream>

using namespace std;

int choose(int n, int k){
    if(k==0 || n==k)
        return 1;
    return choose(n-1, k)+choose(n-1, k-1);
}

int main (){
    int n, k, kq;
    cout << "Nhao vao n, k: ";
    cin >> n >> k;
    kq=choose(n,k);
    cout << "Ket qua: "<< kq;
}