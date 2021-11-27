#include <iostream>
#include <Windows.h>
#include"Giao_dien.cpp"
#include"Dormitory.cpp"
#include"Person.cpp"
#include"Student.cpp"

using namespace std;

void menu2(){
	 Dormitory p;
            bool check;
            int Luachon, j = 1;
            while (j)
            {
                system("cls");
                giaodien2();
                cin >> Luachon;
                switch (Luachon)
                {
                case 1:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    p.Nhap();
                    check = true;
                    system("cls");
                    break;
                }
                case 2:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.Xuat();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 3:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.sapxepName();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 4:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.timkiemAddress();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 5:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    
                    if (check)
                    {
                        p.capnhatID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 6:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.xoaID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 7:
                {
                    system("cls");
                    giaodien2();
                    system("cls");
                    if (check)
                    {
                        p.timkiemID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  Ban chua nhap thong tin vao!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 8:
                {
                    system("cls");
                    gotoXY(70,1);
                    cout << "  =======Tong Tien=======" << endl;
                    p.TongTien();
                    system("pause");
                    break;
                }
                case 9:
                {
                    system("cls");
                    j--;
                    break;
                }
                default:
                {
                    cout << "  Lua chon khong hop le!!!" << endl;
                    break;
                }
                }
            }
           
} 
void menu1(){
 Dormitory p;
            bool check;
            int Luachon, k = 1;
            while (k) {
                system("cls");
                giaodien3();
                cin >> Luachon;
                switch (Luachon)
                {
                case 1:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    p.input();
                    check = true;
                    system("cls");
                    break;
                }
                case 2:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.output();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 3:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.SortName();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 4:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.findAddress();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 5:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.updateID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 6:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.deleteID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 7:
                {
                    system("cls");
                    giaodien3();
                    system("cls");
                    if (check)
                    {
                        p.findID();
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "  You have not entered information!" << endl;
                        system("pause");
                        system("cls");
                    }
                    break;
                }
                case 8:
                {
                    system("cls");
                    gotoXY(70,1);
                    cout << "  =======Total Money=======" << endl;
                    p.TotalMoney();
                    system("pause");
                    break;
                }
                case 9:
                {
                    system("cls");
                    k--;
                    break;
                }

                default:
                {
                    cout << "  Invalid selection!!!" << endl;
                    break;
                }
            } 
}
}
void menu(){
    int chon;
    int i = 1;
    while (i)
    {
        giaodien();
        gotoXY(70,23);
        cout << "  Nhap lua chon: ";
        gotoXY(72,24);
        cin >> chon;
        switch (chon)
        {
        case 1:
        {
           system("cls");
           menu2(); 
           system("cls");
           break;
        }
        case 2:
        {
        system("cls");
        menu1();
        system("cls"); 
        break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
            cout << "  Nhap sai! Nhap lai" << endl;
            break;
        }
    }
}

void GiaoDien_DangNhap(){
        system("cls");
        SetColor(0, 2);
        gotoXY(75,3);
        for(int i=0;i<35;i++){
            putchar(223);
        }
        for(int i=0;i<=3;i++){
            cout<<endl;
            gotoXY(74,3+i);
            putchar(219);
        }
        for(int i=0;i<=3;i++){
            cout<<endl;
            gotoXY(110,3+i);
            putchar(219);
        }
        gotoXY(79, 4);
        SET_COLOR(6);
        cout<<"DANG NHAP TAI KHOAN QUAN LY";
        SetColor(0, 2);
        gotoXY(73,6);
        for(int i=0;i<=38;i++){
            putchar(219);
        }
        for(int i=0;i<=15;i++){
            cout<<endl;
            gotoXY(73,6+i);
            putchar(219);
        }
        for(int i=0;i<=36;i++){
            putchar(219);
        }
        for(int i=0;i<=15;i++){
            cout<<endl;
            gotoXY(111,6+i);
            putchar(219);
        }
}
