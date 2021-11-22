#include <iostream>
using namespace std;
int main(){
    int n;
    cout<< "Nhap so: " << endl;
    cin>> n;
    if(n<8 && n>0){
        switch(n){
        case 1:
            cout<< "Chu nhat.";
            break;
        case 2:
            cout<< "Thu hai.";
            break;
        case 3:
            cout<< "Thu ba";
            break;
        case 4:
            cout<< "Thu tu.";
            break;
        case 5:
            cout<< "Thu nam.";
            break;
        case 6:
            cout<< "Thu sau.";
            break;
        case 7:
            cout<< "Thu bay.";
            break;
        default:
            cout << "So da nhap khong hop le vui long nhap lai:"<< endl;
    }
    }
    else {
        cout<< "So nhap chua hop le vui long nhap lai!."<< endl;
        cin>> n;
    }
    
}