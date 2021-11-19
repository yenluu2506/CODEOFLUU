//chỉ thực hiện được trên dãy đã được sắp xếp

#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key){
    int left = 0, right = n-1, mid;
    while(left<=right){
        mid = (left+right)/2;
        if(a[mid]==key)
            return mid;
        if(a[mid]<key)
            left = mid +1;
        else
            right = mid -1;
    }
    return -1;
}