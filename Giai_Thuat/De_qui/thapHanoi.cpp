#include <iostream>
using namespace std;

void move(int n, char A, char B, char C){
    //neu chi co 1 thi chuyen truc tiep tu a qua c
    if(n==1){
        cout << A << "==>" << C << "\n";
    }
    else{
        move(n-1, A, C, B);
        cout << A<<"==>"<<C<< "\n";
        move(n-1, B, A, C);
    }
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    move(n, 'A', 'B', 'C');
}