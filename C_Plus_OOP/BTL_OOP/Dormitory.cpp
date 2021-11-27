#include <iostream>
#include <vector>
#include <cstdlib>
#include"Giao_dien.cpp"
#include"Person.cpp"
#include"Student.cpp"
#include "menu.cpp"

using namespace std;
class Dormitory
{
private:
    vector<Person *> list_person;

public:
    Dormitory();
    ~Dormitory();
    void Nhap();
    void Xuat();
    void input();
    void output();
    friend void inkhung();
    friend void inmenu1();
    friend void inkhung1();
    friend void inmenu2();
    friend void inkhung3();
    friend void inmenu3();
    friend void inkhung4();
    friend void inmenu4();
    void sapxepName();
    void SortName();
    void capnhatThongtin();
    void capnhatID();
    void updateID();
    void timkiemAddress();
    void findAddress();
    void timkiemID();
    void findID();
    void xoaID();
    void deleteID();
    void TongTien();
    void TotalMoney();
};

Dormitory::Dormitory()
{}

Dormitory::~Dormitory()
{}

void Dormitory::Nhap()
{
    int i = 1, n;
    int Luachon;
    inmenu1();
    while (i)
    {
        cout << "\n \n \n   Nhap lua chon: ";
        cin>>Luachon;
        Person *p;
        switch (Luachon)
        {
        case 1:
        {
            system("cls");
            inkhung();
            inmenu1();
            cout << "\n\n\n  Nhap so luong sinh vien: " << endl;    
            cin>>n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Student[n];
                p->Nhap(i);
                p->selection(true);
                list_person.push_back(p);
            }
            break;
        }
        case 2:
        {
            system("cls");
            inkhung1();
            inmenu1();
            cout << "\n\n\n  Nhap so luong quan ly: " << endl;
            cin >> n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Manage[n];
                p->Nhap(i);
                p->selection(false);
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
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::input()
{
    int i = 1, Selection, n;
    inmenu2();
    while (i)
    {
        cout << "\n \n\n  Enter selection: ";
        cin >> Selection;
        Person *p;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inkhung3();
            inmenu2();
            cout << "\n\n\n  Enter number of students: " << endl;
            cin >> n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Student[n];
                p->Nhap(i);
                p->selection(true);
                list_person.push_back(p);
            }

            break;
        }
        case 2:
        {
            system("cls");
            inkhung4();
            inmenu2();
            cout << "\n\n\n  Enter number of manages: " << endl;
            cin >> n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                p = new Manage[n];
                p->Nhap(i);
                p->selection(false);
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
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::Xuat()
{
    int i = 1, Luachon, n;
    inmenu3();
    while (i)
    {
        cout << "\n \n\n  Nhap lua chon: ";
        cin >> Luachon;
        switch (Luachon)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung1();
                    list_person[i]->Xuat(i);
                }
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
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::output()
{
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n \n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung3();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung4();
                    list_person[i]->Xuat(i);
                }
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
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}


void inkhung(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(124,i);
		putchar(219);
		gotoXY(134,i);
		putchar(219);
        gotoXY(144,i);
		putchar(219);
        gotoXY(161,i);
		putchar(219);
        gotoXY(177,i);
        putchar(219);
	}

    for(int i=35; i <177; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<" Ho va ten";
	gotoXY(60,2);
	cout<<" Tuoi";
	gotoXY(70,2);
	cout<<" Dia chi";
	gotoXY(85,2);
	cout<<" Ma ID";
	gotoXY(100,2);
	cout<<" CMND/CCCD";
	gotoXY(115,2);
	cout<<" Phong";
	gotoXY(125,2);
	cout<<" Thang";
    gotoXY(135,2);
    cout <<" Don gia";
    gotoXY(145,2);
    cout<<" So lan vi pham";
    gotoXY(162,2);
    cout<<" Tien can dong";
}


void inkhung1(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(129,i);
		putchar(219);
		gotoXY(144,i);
		putchar(219);
        gotoXY(159,i);
		putchar(219);
        gotoXY(175,i);
		putchar(219);
	}

    for(int i=35; i <175; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<" Ho va ten";
	gotoXY(60,2);
	cout<<" Tuoi";
	gotoXY(70,2);
	cout<<" Dia chi";
	gotoXY(85,2);
	cout<<" Ma ID";
	gotoXY(100,2);
	cout<<" So DT";
	gotoXY(115,2);
	cout<<" Tham nien";
	gotoXY(130,2);
	cout<<" He so luong";
    gotoXY(145,2);
    cout <<" Chuc vu";
    gotoXY(160,2);
    cout<<" Tien luong";
}


void inkhung3(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(124,i);
		putchar(219);
		gotoXY(134,i);
		putchar(219);
        gotoXY(147,i);
		putchar(219);
        gotoXY(161,i);
		putchar(219);
        gotoXY(177,i);
        putchar(219);
	}

    for(int i=35; i <177; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<" First and last name";
	gotoXY(60,2);
	cout<<" Age";
	gotoXY(70,2);
	cout<<" Address";
	gotoXY(85,2);
	cout<<" ID code";
	gotoXY(100,2);
	cout<<" Identity card";
	gotoXY(115,2);
	cout<<" Room";
	gotoXY(125,2);
	cout<<" Months";
    gotoXY(135,2);
    cout <<" Unit price";
    gotoXY(148,2);
    cout<<" Violations";
    gotoXY(162,2);
    cout<<"Money to pay";
}


void inkhung4(){
    for(int i=1; i <25; i++){
		gotoXY(34,i);
		putchar(219);
		gotoXY(59,i);
		putchar(219);
		gotoXY(69,i);
		putchar(219);
		gotoXY(84,i);
		putchar(219);
		gotoXY(99,i);
		putchar(219);
		gotoXY(114,i);
		putchar(219);
        gotoXY(129,i);
		putchar(219);
		gotoXY(144,i);
		putchar(219);
        gotoXY(159,i);
		putchar(219);
        gotoXY(175,i);
		putchar(219);
	}

    for(int i=35; i <175; i++){
		gotoXY(i,1);
		putchar(223);
		gotoXY(i,24);
		putchar(220);
		gotoXY(i,3);
		putchar(220);
	}
	gotoXY(35,2);
	cout<<"First and last name";
	gotoXY(60,2);
	cout<<"Age";
	gotoXY(70,2);
	cout<<"Address";
	gotoXY(85,2);
	cout<<"ID code";
	gotoXY(100,2);
	cout<<"Phone";
	gotoXY(115,2);
	cout<<"Seniority";
	gotoXY(130,2);
	cout<<"Coefficients";
    gotoXY(145,2);
    cout <<"Position";
    gotoXY(160,2);
    cout<<"Salary";
}

void Dormitory::sapxepName()
{
    for (int i = 0; i < list_person.size() - 1; i++)
    {
        for (int j = list_person.size() - 1; j > i; j--)
        {
            char *name1 = new char[list_person[j]->getName().length()];
            strcpy(name1, list_person[j]->getName().c_str());
            char *name2 = new char[list_person[j - 1]->getName().length()];
            strcpy(name2, list_person[j - 1]->getName().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Person *mtp;
                mtp = list_person[j];
                list_person[j] = list_person[j - 1];
                list_person[j - 1] = mtp;
            }
        }
    }
    int i = 1, Luachon, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Luachon;
        switch (Luachon)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung1();
                    list_person[i]->Xuat(i);
                }
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
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::SortName()
{
    for (int i = 0; i < list_person.size() - 1; i++)
    {
        for (int j = list_person.size() - 1; j > i; j--)
        {
            char *name1 = new char[list_person[j]->getName().length()];
            strcpy(name1, list_person[j]->getName().c_str());
            char *name2 = new char[list_person[j - 1]->getName().length()];
            strcpy(name2, list_person[j - 1]->getName().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Person *mtp;
                mtp = list_person[j];
                list_person[j] = list_person[j - 1];
                list_person[j - 1] = mtp;
            }
        }
    }
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(list_person[i]->selection()==true){
                    inkhung3();
                    list_person[i]->Xuat(i);
                }
            }

            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            for (int i = 0; i < list_person.size(); i++)
            {
                    if(list_person[i]->selection()==false){
                    inkhung4();
                    list_person[i]->Xuat(i);
                }
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
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::timkiemAddress()
{
    int i = 1, Selection, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Nhap dia chi day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  Khong tim duoc theo yeu cau!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Nhap dia chi day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung1();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                    cout << "\n  Khong tim duoc theo yeu cau!!!";
                    break;
                }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
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
            cout << "  Lua chon khong hop le!!!";
            break;
        }
        }
    }
}

void Dormitory::findAddress()
{

    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Enter address to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung3();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Enter address to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getAddress()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung4();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
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
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}



void Dormitory::timkiemID()
{
    int i = 1, Selection, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  Khong tim duoc theo yeu cau!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID day du de tim: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung1();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  Khong tim duoc theo yeu cau!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  Khong tim duoc theo yeu cau!!!\n\n"<< endl;
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
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::findID()
{
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {   
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==true){
                        inkhung3();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int dem = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to search: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i < list_person.size(); i++)
            {
                if(timkiem == list_person[i]->getId()){
                    dem++;
                    if(list_person[i]->selection()==false){
                        inkhung4();
                        list_person[i]->Xuat(i);
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  The request could not be found!!!";
                        break;
                    }
                }
            }
            if (dem == 0){
                cout << "\n  The request could not be found!!!\n\n"<< endl;
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
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::capnhatThongtin()
{
    int i;
    if (list_person[i]->selection() == true)
    {
        list_person[i]->capnhatThongtin();
    }
    else if ((list_person[i]->selection() == false))
    {
        list_person[i]->capnhatThongtin();
    }
}


void Dormitory::capnhatID()
{

    int i = 1, Selection, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  Nhap ID day du de cap nhat: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        inkhung();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Da cap nhat thanh cong!!!" << endl;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID Khong ton tai!!!";
                        break;
                    }
                    
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID Khong ton tai!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID day du de cap nhat: " << endl;
            cin.ignore();
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        inkhung1();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Da cap nhat thanh cong!!!" << endl;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID Khong ton tai!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID Khong ton tai!!!\n\n"<< endl;
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
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::updateID()
{
    int i = 1, Selection, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Enter selection: ";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << " \n\n\nEnter ID to update: " << endl;
            fflush(stdin);
            // gotoXY(2, 6);
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        inkhung3();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Successfully updated!!!" << endl;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string timkiem;
            gotoXY(1, 5);
            cout << " \n\n\nEnter ID to update: " << endl;
            cin.ignore();
            // gotoXY(2, 6);
            getline(cin, timkiem);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (timkiem == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        inkhung4();
                        list_person[i]->capnhatThongtin();
                        cout << "\n  Successfully updated!!!" << endl;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
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
            cout << "  Invalid selection!!!" << endl;
            break;
        }
        }
    }
}

void Dormitory::xoaID()
{
    int i = 1, luachon, n;
    inmenu3();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  \n\n\nNhap ID de xoa: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Da xoa ID " << xoa << " ra khoi he thong!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID khong ton tai!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID khong ton tai!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu3();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  Nhap ID de xoa: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Da xoa ID " << xoa << " ra khoi he thong!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID khong ton tai!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID khong ton tai!!!\n\n"<< endl;
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
            cout << "  Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::deleteID()
{
    int i = 1, luachon, n;
    inmenu4();
    while (i)
    {
        cout << "\n\n\n  Nhap lua chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to delete: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == true)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Removed ID " << xoa << " from the system!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==false){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            inmenu4();
            int found = 0;
            string xoa;
            gotoXY(1, 5);
            cout << "  \n\n\nEnter ID to delete: " << endl;
            cin.ignore();
            getline(cin, xoa);
            for (int i = 0; i <= list_person.size() - 1; i++)
            {
                if (xoa == list_person[i]->getId())
                {
                    found = 1;
                    if (list_person[i]->selection() == false)
                    {
                        list_person.erase(list_person.begin() + i);
                        cout << "\n  Removed ID " << xoa << " from the system!!!" << endl;
                        break;
                    }
                    else if (list_person[i]->selection()==true){
                        cout << "\n  ID does not exist!!!";
                        break;
                    }
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID does not exist!!!\n\n"<< endl;
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
            cout << "  Invalid selection !!!" << endl;
            break;
        }
        }
    }
}


void Dormitory::TongTien()
{
    unsigned long int Tongluong = 0;
    unsigned long int Tongphi = 0;
    for (int i = 0; i < list_person.size(); i++)
    {

        if (list_person[i]->selection() == true)
        {
            list_person[i]->tinhtien();
            Tongphi = Tongphi + list_person[i]->getMoney();
        }
        else
        {
            list_person[i]->tinhtien();
            Tongluong = Tongluong + list_person[i]->getMoney();
        }
    }
    gotoXY(70,3);
    cout << "  Tong tien luong quan ly la: " << Tongluong << endl;
    gotoXY(70,4);
    cout << "  Tong tien phi ktx la: " << Tongphi<< endl;
}
void Dormitory::TotalMoney()
{
    unsigned long int Tongluong = 0;
    unsigned long int Tongphi = 0;
    for (int i = 0; i < list_person.size(); i++)
    {

        if (list_person[i]->selection() == true)
        {
            list_person[i]->tinhtien();
            Tongphi = Tongphi + list_person[i]->getMoney();
        }
        else
        {
            list_person[i]->tinhtien();
            Tongluong = Tongluong + list_person[i]->getMoney();
        }
    }
    gotoXY(70,3);
    cout << "  Manager's total salary: " << Tongluong << endl;
    gotoXY(70,4);
    cout << "  Total dormitory rent: " << Tongphi<<endl;
}
