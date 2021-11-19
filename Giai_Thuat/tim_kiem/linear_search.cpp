#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int key){
    for(int i=0; i<n; i++){
        if(a[i]==key)
            return i;
    }
    return -1;
    // int i=0;
    // while(i<n){
    //     if(a[i]==key) return i;
    //     i++;
    // }
}