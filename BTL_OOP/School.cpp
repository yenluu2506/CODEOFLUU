#include <iostream>
#include "Person.cpp"
#include "Manage.cpp"
#include "Student.cpp"
#include <vector>
using namespace std;

void inmenu1(){
	// for(int i=1; i <5; i++){
	// 	gotoXY(1,i);
	// 	putchar(179);
	// }
	
	// for(int i=1; i <5; i++){
	// 	gotoXY(30,i);
	// 	putchar(179);
	// }
	// for(int i=2; i <30; i++){
	// 	gotoXY(i,0);
	// 	putchar(95);
	// }
	// for(int i=2; i <30; i++){
	// 	gotoXY(i,4);
	// 	putchar(95);
	// }
	//in menu o lua chon 1
		// gotoXY(2,1);
        cout << "1. Nhap sinh vien";
        // gotoXY(2,2);
        cout << "2. Nhap ban quan ly";
        // gotoXY(2,3);
        cout << "3. Thoat ";
}

class School{
private:
    vector<Person *> list_person;

public:
    School();
    ~School();
    void Nhap();
    void Xuat();
    // float TongLuong();
    // void LuongMax();
    // void Sapxep();
    // void Timkiem();
    // friend void inkhung();
    friend void inmenu1();
};

School::School(){
}

School::~School(){
}

void School::Nhap(){
    int i=1, Luachon, n;
        inmenu1();
         while (i)
    {
        cout << "\n \n   Nhap lua chon: ";
        cin >> Luachon;
        Person *p;
        switch (Luachon)
        {
        case 1:  
		  {
            system("cls");
        	inkhung();
        	inmenu1();
            cout<<"\n\n\n Nhap so luong sinh vien: ";
            int a= numberStudent(n);
            for(int i=0; i<a; i++){
            p = new Student[n];
            p->Nhap(i);
            // x->Set_KieuNV(true);
            list_person.push_back(p);
            }
            
            break;
        }
        case 2:
        {   
            system("cls");
        	inkhung();
            inmenu1();
        	cout<<"\n\n\n Nhap so luong ban quan ly: ";
            int b= numberManage(n);
            for(int i=0; i<b; i++){
            p = new Manage[n];
            p->Nhap(i);
            // p->Set_KieuNV(false);
            list_person.push_back(p);
            }
			break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}