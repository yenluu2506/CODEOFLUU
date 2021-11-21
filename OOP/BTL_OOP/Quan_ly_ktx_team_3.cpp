#pragma once
#include"iostream"
#include"menu.cpp"
#include <Windows.h>
using namespace std;

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void gotoXY (int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}




int main()
{
    bool logic = true;
    string user = "admin";
    string pass = "123456";
    string u, p;
    do
    {
        GiaoDien_DangNhap();
        gotoXY(79, 8);
        cout << "Tai Khoan/ Account:" << endl;
        gotoXY(79, 9);
        SET_COLOR(11);
        getline(cin, u);
        gotoXY(79, 10);
        SET_COLOR(2);
        cout << "Mat Khau/ Password:" << endl;
        gotoXY(79, 11);
        SET_COLOR(11);
        getline(cin, p);
        if (user != u || pass != p)
        {
            GiaoDien_DangNhap();
            gotoXY(79, 8);
            SET_COLOR(10);
            cout<<"Tai khoan hoac mat khau sai...";
            gotoXY(79, 9);
            cout << "Vui long nhap lai!"<<endl;
            gotoXY(79, 10);
            cout<< "(Please try again)";
            SET_COLOR(2);
            gotoXY(79, 12);
            SET_COLOR(2);
            cout << "Tai Khoan/ Account: " << endl;
            gotoXY(79, 13);
            SET_COLOR(11);
            getline(cin, u);
            gotoXY(79, 14);
            SET_COLOR(2);
            cout << "Mat Khau/ Password:" << endl;
            gotoXY(79, 15);
            SET_COLOR(14);
            getline(cin, p);
        }

    } while (user != u || pass != p);
    gotoXY(76, 17);
    cout << "Dang nhap thanh cong !!";
    gotoXY(76, 18);
    cout << "Nhan 1 phim bat ky de tiep tuc....";
    menu();
    return 0;
}
