#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int x = 5;
	cout << "Ket qua in ra la: " << endl;
	cout << "Gia tri ban dau"<< right << setw(10)<< "Bieu thuc" << right << setw(10) << "Gia tri cua" << right << setw(10) <<"Gia tri sau" << endl;
	cout << x << "\t\t | \t x++ \t\t | \t" << x <<"\t\t | \t " << x+1 << endl;
	cout << x << "\t\t | \t x-- \t\t | \t" << x << "\t\t | \t " << x-1 << endl;
	cout << x << "\t\t | \t ++x \t\t | \t" << x+1 << "\t\t | \t " << x+1 << endl;
	cout << x << "\t\t | \t --x \t\t | \t" << x-1 << "\t\t | \t " << x-1 << endl;
}