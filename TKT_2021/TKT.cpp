#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include<ctime>
#include <vector>
#include "windows.h" 
using namespace std;



void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


int main()
{
	string date;
	while (true)
	{
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\tNGAY NHA GIAO VIET NAM LA NGAY BAO NHIEU ? ";
		getline(cin, date);
		if (date == "20/11")
		{
			cout << "\t\t\t\t\t\t\t\t\t---CHUC THAY CO GIANG VIEN 20/11 VUI VE !---" << endl <<endl;
			cout << "\t\t\t\t\t\t\t\t\tCHUC THAY CO LUON HOAN THANH TOT TRONG SU NGHIEP TRONG NGUOI" << endl;
			Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\tTHANH CONG TREN CON DUONG GIANG DAY" << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\tDAO TAO NEN NHIEU THE HE NHAN TAI" << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\tCUOC SONG HANH PHUC" << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\tCON NGOAN TRO GIOI" << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\tCHUC THAY CO LUON DU TAM-TRI-LUC DE DUA SINH VIEN DEN BO BEN THANH CONG" << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\t..." << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\t..." << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\t..." << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\t..." << endl; Sleep(1000);
			cout << "\t\t\t\t\t\t\t\t\t..." << endl << endl<< endl<< endl;

			vector <int> A;
			A.push_back(6);
			A.push_back(14);
			A.push_back(3);
			A.push_back(12);
			A.push_back(5);
			A.push_back(9);
			A.push_back(7);
			A.push_back(11);
			A.push_back(6);
			A.push_back(10);
			A.push_back(14);
			A.push_back(6);
			A.push_back(12);
			A.push_back(6);
			while(true)
			{
				int i = 0;
				SetColor(A.at(i++ % A.size()));

				ifstream file;
				file.open("F:/TKT8.txt", ios_base::in);
				string line;
				while (getline(file, line)) {
					cout << line << endl;
					Sleep(35); 
				}
				file.close();

				SetColor(A.at(i++ % A.size()));

				ifstream file2;
				file2.open("F:/TKT7.txt", ios_base::in);
				string line2;
				while (getline(file2, line2)) {
					cout << line2 << endl;
					Sleep(35); 
				}
				file2.close();
				
				SetColor(A.at(i++ % A.size()));
				ifstream file12;
				file12.open("F:/TKT21.txt", ios_base::in);
				string line12;
				while (getline(file12, line12)) {
					cout << line12 << endl;
					Sleep(35); 
				}
				file12.close();
				
				SetColor(A.at(i++ % A.size()));
				ifstream file3;
				file3.open("F:/TKT10.txt", ios_base::in);
				string line3;
				while (getline(file3, line3)) {
					cout << line3 << endl;
					Sleep(35); 
				}
				file3.close();


				SetColor(A.at(i++ % A.size()));
				ifstream file4;
				file4.open("F:/TKT11.txt", ios_base::in);
				string line4;
				while (getline(file4, line4)) {
					cout << line4 << endl;
					Sleep(35); 
				}
				file4.close();

				SetColor(A.at(i++ % A.size()));
				ifstream file5;
				file5.open("F:/TKT30.txt", ios_base::in);
				string line5;
				while (getline(file5, line5)) {
					cout << line5 << endl;
					Sleep(35); 
				}
				file5.close();

				SetColor(A.at(i++ % A.size()));
				ifstream file6;
				file6.open("F:/TKT13.txt", ios_base::in);
				string line6;
				while (getline(file6, line6)) {
					cout << line6 << endl;
					Sleep(35); 
				}
				file6.close();

				SetColor(A.at(i++ % A.size()));
				ifstream file7;
				file7.open("F:/TKT24.txt", ios_base::in);
				string line7;
				while (getline(file7, line7)) {
					cout << line7 << endl;
					Sleep(35); 
				}
				file7.close();

				SetColor(A.at(i++ % A.size()));
				ifstream file8;
				file8.open("F:/TKT15.txt", ios_base::in);
				string line8;
				while (getline(file8, line8)) {
					cout << line8 << endl;
					Sleep(35); 
				}
				file8.close();

				SetColor(A.at(i++ % A.size()));
				ifstream file9;
				file9.open("F:/TKT18.txt", ios_base::in);
				string line9;
				while (getline(file9, line9)) {
					cout << line9 << endl;
					Sleep(35); 
				}
				file9.close();
				
				SetColor(A.at(i++ % A.size()));
				ifstream file10;
				file10.open("F:/TKT19.txt", ios_base::in);
				string line10;
				while (getline(file10, line10)) {
					cout << line10 << endl;
					Sleep(35); 
				}
				file10.close();
				
				SetColor(A.at(i++ % A.size()));
				ifstream file11;
				file11.open("F:/TKT27.txt", ios_base::in);
				string line11;
				while (getline(file11, line11)) {
					cout << line11 << endl;
					Sleep(35); 
				}
				file11.close();
				
				SetColor(A.at(i++ % A.size()));
				ifstream file14;
				file14.open("F:/TKT29.txt", ios_base::in);
				string line14;
				while (getline(file14, line14)) {
					cout << line14 << endl;
					Sleep(35); 
				}
				file14.close();
				
				SetColor(A.at(i++ % A.size()));
				ifstream file13;
				file13.open("F:/TKT28.txt", ios_base::in);
				string line13;
				while (getline(file13, line13)) {
					cout << line13 << endl;
					Sleep(35); 
				}
				file13.close();
				
				break;
				
			}
			_getch();
		}
		else
		{
			cout << "\t\tSAI ROI, THU LAI DI NAO :((" << endl << endl;
			system("pause");
		}
	}
}
