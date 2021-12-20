#include<iostream>
#include"FunctionTemplate.h"
#include"PhanSo.h"
int main(){
    int a=9,b=-2;
    double c=3.6,d=8.9;
    PHANSO ps1(3,5),ps2(-1,8);
    int intArr[4]={-1,3,-9,8};
    double doubleArr[7]={-1.2,3.4,-9.5,8.1,19.4,2,15};
    PHANSO psArr[3]={PHANSO(7,8),PHANSO(-2,4),PHANSO(1,2)};
    cout<<"Min int a,b: "<<Min(a,b)<<endl;
    cout<<"Min double c,d: "<<Min(c,d)<<endl;
    cout<<"Min ps c,d: "<<Min(ps1,ps2)<<endl;
    cout<<"Max int a,b: "<<Max(a,b)<<endl;
    cout<<"Max double c,d: "<<Max(c,d)<<endl;
    cout<<"Max ps c,d: "<<Max(ps1,ps2)<<endl;
    cout<<"Max in int arr: "<<MaxInArr(intArr,4)<<endl;
    cout<<"Max in double arr: "<<MaxInArr(doubleArr,7)<<endl;
    cout<<"Max in ps arr: "<<MaxInArr(psArr,3);
    cout<<"Sort int arr: ";
    SortArr(intArr,4);
    for(int i=0;i<4;i++){
        cout<<intArr[i]<<" ";
    }
    cout<<endl;
    cout<<"Sort double arr: ";
    SortArr(doubleArr,7);
    for(int i=0;i<7;i++){
        cout<<doubleArr[i]<<" ";
    }
    cout<<endl;
    cout<<"Sort ps arr: ";
    SortArr(psArr,3);
    for(int i=0;i<3;i++){
        cout<<psArr[i]<<" ";
    }
    cout<<endl;
    return 0;
}