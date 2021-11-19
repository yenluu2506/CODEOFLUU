//de quy da tuyen

#include <iostream>
using namespace std;

void print_array(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i]<<"\t";
    }
    cout << endl;
}
void print_permutation(int arr[], int i, int n){
    int j, swap;
    print_array(arr,n);
    for(j=i+1; j<n; j++){
        if(arr[i]>arr[j]){
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
        print_permutation(arr,n, i+1);//goi de qui
    }
}
int main(){
    int m[3];
    m[0] = 10;
    m[1] = 2;
    m[2] = 5;
    print_permutation(m, 3, 0);
    return 0;
}
