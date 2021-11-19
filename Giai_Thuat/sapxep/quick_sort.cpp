#include <iostream>
using namespace std;

void QuickSort(int a[], int left, int right){
    //step 1
    int x = a[(left + right)/2];
    int i = left, j=right;
    do{
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i<j);
    
    //step 2
    if(left<j){
        QuickSort(a, left, j);
    }

    //step 3
    if(right>i){
        QuickSort(a, i, right);
    }
}