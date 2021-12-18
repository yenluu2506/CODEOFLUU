#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
int main()
{
	ifstream file;
	file.open("C:/Users/PC/Downloads/bdt.txt", ios_base::in);
	string line;
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
		Sleep(90);
	}
	system("pause");
}
