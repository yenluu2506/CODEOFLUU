#pragma once
#include<iostream>
using namespace std;
template<typename T>
T Min( T a, T b){
    return (a<b)?a:b;
}
template<typename T>
T Max( T  a, T b){
    return (a>b)?a:b;
}
template<typename T>
T MaxInArr( T arr[],int n){
    T max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    T min=0;
    if(max<0){
        max=0;
    }
    return max;
}
template<typename T>
void SortArr( T  arr[],int n){
    for(int i =0;i <n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                T temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
