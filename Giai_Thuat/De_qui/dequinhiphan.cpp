//de qui nhi phan
#include <iostream>
using namespace std;

int Fib(int n) {
    if(n<=2) return 1;
    return Fib(n-1) + Fib(n-2);
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int kq = Fib(n);
    cout << kq;
    return 0;
}