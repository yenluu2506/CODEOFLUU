#include <iostream>
#include "console.h"
#include "main.h"

using namespace std;

int main(){
    setColorBGTextXY(0*2, 0, 0, 8, " " );
    setColorBGTextXY(1*2, 0, 0, 7, " ");
    setColorBGTextXY(2*2, 0, 0, 8, " ");

    setColorBGTextXY(0*2, 1, 0, 7, " ");
    setColorBGTextXY(1*2, 1, 0, 8, " ");
    setColorBGTextXY(2*2, 1, 0, 7, " ");

    cout << endl;
    system("pause");
    return 0;
}