#include <iostream>
using namespace std;

int giaiThua(int n){
    if(n<=1)
        return(1);
        return n*giaiThua(n-1);//goi de qui
}

int main(){
    
}