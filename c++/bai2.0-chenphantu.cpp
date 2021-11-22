#include <iostream>
using namespace std;
int main(){
    int n, k, x;
    int a[100];
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>> a[i];
    }
    cin >> k>> x;
    for(int i=n; i>=k+1; i--){
        a[i] = a[i-1];
    }
    a[k] = x;
    n++;
    for (int i = 0; i<n; i++){
        cout << a[i]<< " ";
    }
    return 0;
}