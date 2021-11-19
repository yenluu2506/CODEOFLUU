#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    int minV = a[i], pMin = i;
    for(int j = i+1; j<n; j++){
        if(minV > a[j]){
            minV = a[j];
            pMin = j;
        }
        if(i!=pMin){
            swap(a[i], a[pMin]);
        }
    }
}