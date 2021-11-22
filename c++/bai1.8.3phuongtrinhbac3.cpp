#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
/* int main() {

	float a, b, c, d;
	cout << " nhap vao bon gia tri a, b, c, d";
	cin >> a >> b >> c >> d;

	if (a == 0) {

		if (b == 0) {
			if (c == 0 && d == 0) {
				cout << " PHUONG TRINH CO VO SO NGHIEM " << endl;
			}
			else if (c == 0 && d != 0) {
				cout << " PHUONG TRINH VO NGHIEM " << endl;
			}
			else {
				cout << " PHUONG TRINH CO NGHIEM LA: " << " x " << " = " << -d / c << endl;
			}
		}
		else {
			float denta = b * b - (4 * a * c);

			if (denta < 0) {
				cout << " PHUONG TRINH VO NGHIEM: " << endl;
			}
			else if (denta == 0) {
				cout << " PHUONG TRINH CO NGHIEM KEP: " << "x1" << "=" << "x2" << "=" << -b / (2 * a);
			}
			else {
				cout << " PHUONG TRINH CO HAI NGHIEM PHAN BIET: " << endl;
				cout << " x1 " << " = " << (-b - sqrt(denta)) / (2 * a) << endl;
				cout << " x2 " << " = " << (-b - sqrt(denta)) / (2 * a) << endl;
			}
		}

		
	}

	else {
		double dental = b * b - (3 * a * c);
		double k = (9 * a * b * c - 2 * b ^ 3 - 27 * a ^ 2 * d) / 2 * sqrt(abs(dental)) ^ 3;
#define PI 3.14159
		if (dental > 0) {
			if (abs(k) >= 1) {
				cout << " PHUONG TRINH CO BA NGHIEM: " << endl;
				cout << " x1 " << " = " << (2 * (sqrt(dental)) * cos((acos(k)) / 3) - b) / (3 * a) << endl;
				cout << " x2 " << " = " << (2 * (sqrt(dental)) * cos(((acos(k)) / 3) - (2 * PI) / 3) - b) / (3 * a) << endl;
				cout << " x3 " << " = " << (2 * (sqrt(dental)) * cos(((acos(k)) / 3) - (2 * PI) / 3) - b) / (3 * a) << endl;
			}
			else {
				cout << " PHUONG TRINH CO MOT NGHIEM DUY NHAT: " << endl;
				cout << " x " << " = " << ((sqrt(a) * abs(k)) / (3*a*k)) * ((pow((abs(k)) +sqrt( )
			}
		}
	}
	
	system("pause");
} */