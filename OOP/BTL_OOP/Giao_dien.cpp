#include<iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
void giaodien()
{
    system("cls");
    srand(time(NULL));
    SetColor(0, 1 + rand() % 15);
    gotoXY(40,1);
    cout << "      ########     #      #     #       ##       #       #     #      #        #     #  ########  #       #      " << endl; gotoXY(40,2);
    cout << "     #        #    #      #    #  #     #  #     #       #       #   #         #   #       #        #   #        " << endl;gotoXY(40,3);
    cout << "    #       #  #   #      #   #    #    #    #   #       #         #           # #         #          #          " << endl;gotoXY(40,4);
    cout << "     #        #    #      #  ########   #      # #       #         #           #   #       #        #   #        " << endl;gotoXY(40,5);
    cout << "      ########  #  ######## #        #  #       ##       #######   #           #     #     #      #       #      " << endl;

    SetColor(0, 2);
    gotoXY(73,8);
        for(int i=0;i<=38;i++){
            putchar(219);
        }
        for(int i=0;i<=10;i++){
            cout<<endl;
            gotoXY(73,8+i);
            putchar(219);
        }
        for(int i=0;i<=36;i++){
            putchar(219);
        }
        for(int i=0;i<=10;i++){
            cout<<endl;
            gotoXY(111,8+i);
            putchar(219);
        }
    gotoXY(80, 11);
    cout << "1. Ngon ngu Tieng Viet" << endl;
    gotoXY(80, 12);
    cout << "2. Language English" << endl;
    gotoXY(80, 13);
    cout << "3. Thoat" << endl;
}


void giaodien2()
{
    for(int i=0; i <13; i++){
		gotoXY(64,i);
		putchar(219);
	}
	
	for(int i=0; i <13; i++){
		gotoXY(120,i);
		putchar(219);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,12);
		putchar(220);
	}

    SetColor(0, 2);
    gotoXY(70,1);
    cout << "Ban da chon ngon ngu Tieng Viet" << endl;
    gotoXY(70,2);
    cout << "1. Nhap thong tin";
    gotoXY(70,3);
    cout << "2. Hien thi thong tin";
    gotoXY(70,4);
    cout << "3. Sap xep theo ten";
    gotoXY(70,5);
    cout << "4. Tim kiem theo tinh";
    gotoXY(70,6);
    cout << "5. Cap nhat thong tin theo ID";
    gotoXY(70,7);
    cout << "6. Xoa theo ID";
    gotoXY(70,8);
    cout << "7. Tim kiem theo ID";
    gotoXY(70,9);
    cout << "8. Tinh tong tien";
    gotoXY(70,10);
    cout << "9. Thoat ";
    gotoXY(70,15);
    cout << " Nhap lua chon: ";
}


void giaodien3()
{
    for(int i=0; i <13; i++){
		gotoXY(64,i);
		putchar(219);
	}
	
	for(int i=0; i <13; i++){
		gotoXY(120,i);
		putchar(219);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,0);
		putchar(223);
	}
	for(int i=65; i <120; i++){
		gotoXY(i,12);
		putchar(220);
	}

    SetColor(0, 2);
    gotoXY(70,1);
    cout << "You have selected the English language" << endl;
    gotoXY(70,2);
    cout << "1. Enter information";
    gotoXY(70,3);
    cout << "2. Display information";
    gotoXY(70,4);
    cout << "3. Sort by name";
    gotoXY(70,5);
    cout << "4. Search by address";
    gotoXY(70,6);
    cout << "5. Update by ID";
    gotoXY(70,7);
    cout << "6. Delete by ID";
    gotoXY(70,8);
    cout << "7. Search by ID";
    gotoXY(70,9);
    cout << "8. Total Money";
    gotoXY(70,10);
    cout << "9. Exit ";
    gotoXY(70,15);
    cout <<  "Enter Choose: ";
}
