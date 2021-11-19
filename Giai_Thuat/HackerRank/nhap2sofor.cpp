#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a,b;
    cin>>a>>b;
    string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i=a; i<=b; i++){
        if(i>9){
            i%2==0 ? cout <<"even"<<endl : cout << "odd"<<endl;
        }
        else{
            cout << num[i]<<endl;
        }
    }
    
    return 0;
}