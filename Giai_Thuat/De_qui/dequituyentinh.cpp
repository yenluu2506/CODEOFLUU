//tinh giai thua
#include <iostream>
using namespace std;
//hoat dong theo co che stack
int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

int main(int argc, char** argv){
    int n;
    cout << "Nhap n: ";
    cin>>n;
    cout << endl;
    int kq = factorial(n);
    cout << n<< "!="<< kq;
    return 0;
}