#include "functions.h"
#include "main.h"

CauTrucBang CTBang;
CauTrucO **CTO;

void nhapMang2chieuDong(){
    CTO = new CauTrucO*[CTBang.Dong];
    for (int i=0; i<CTBang.Dong; i++){
        CTO[i] = new CauTrucO[CTBang.Cot];
    }
}
void xoaMang2chieuDOng(){
    for (int i=0; i<CTBang.Dong; i++){
        delete[] CTO[i];
    }
    delete[] CTO;
}