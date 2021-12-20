#pragma once
#include<iostream>
using namespace std;
class PHANSO{
    private:
        double TuSo;
        double MauSo;
    public:
        PHANSO();
        PHANSO(double a);
        PHANSO(double a,double b);
        PHANSO(const PHANSO &ps);
        void Reduce();
        PHANSO operator=(const PHANSO & ps);
        PHANSO operator+(const PHANSO & Ps);
        PHANSO operator-(const PHANSO & Ps);
        PHANSO operator*(const PHANSO & Ps);
        PHANSO operator/(const PHANSO & Ps);
        bool operator==(const PHANSO & Ps);
        bool operator!=(const PHANSO & Ps);
        bool operator>(const PHANSO & Ps);
        bool operator<(const PHANSO & Ps);
        bool operator>=(const PHANSO & Ps);
        bool operator<=(const PHANSO & Ps);
        friend ostream & operator<<(ostream &os,const PHANSO &Ps);
        friend istream & operator>>(istream &is,PHANSO& Ps);
        ~PHANSO();
};