//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include <iostream>
using namespace std;

typedef int Item;

struct Sinhvien{
    char MSV[50];
    char hovaten[100];
    float toan, ly, hoa, dtb;

};
struct Node{
	Sinhvien *data;
	Node *next;
};

struct SList{
    Node *head;
    Node *tail;
};

void Init(SList *&list){
    list = new SList;
    list->head = NULL;
}

Sinhvien *Nhap(){
    Sinhvien *sv = new Sinhvien;
    cout << "Nhap ma sinh vien: ";
    fflush(stdin);
    gets(sv->MSV);
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    gets(sv->hovaten);
    cout << "Nhap diem toan: ";
    fflush(stdin);
    cin >> sv->toan;
    cout << "Nhap diem ly: ";
    fflush(stdin);
    cin >> sv->ly;
    cout << "Nhap diem hoa: ";
    fflush(stdin);
    cin >> sv->hoa;
    return sv;
}

Node *CreateNode(Sinhvien *sv){
    Node *node = new Node;
    if(node != NULL){
        node->data = sv;
        node->next = NULL;
    }
    else{
        cout<< "Cap phat bo nho khong thanh cong.";
    }
    return node;
}

void InsertLast(SList *&list, Sinhvien *sv)
{
    Node *node=CreateNode(sv);
    if(list->head==NULL)
    {
        list->head=node;
    }
    else
    {
        Node *temp=list->head;
         
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next= node;
    }
}

void input(SList *&list, Sinhvien *sv){
    char test;
    cout<<"Nhan phim bat ki de tiep tuc.";
    cout<<"\nNhan 0 de dung nhap.";
    do{
        test=getchar();
        if(test=='0')
            break;
            Nhap();
            Node *p=CreateNode(sv);
            InsertLast(list, sv);

    }while (1);
}

float DTB(SList *list, Sinhvien *sv){
    sv->dtb = (sv->toan + sv->ly + sv->hoa)/3;
    return sv->dtb;
}

void PrintList(SList *list){
    Node *temp=list->head;
    if(temp = NULL){
        cout << "Danh sach rong.";
        return;
    }
    while(temp!=NULL){
        Sinhvien *sv = temp->data;
        cout << sv->MSV << "\t|\t" << sv->hovaten << "\t|\t" << sv->toan << 
        "\t|\t" << sv->ly << "\t|\t" << sv->hoa <<  "\t|\t" << DTB(list, sv) << endl;
        temp = temp->next;
    }
}

int main(){
    SList *list;
    Sinhvien *sv;
    // Init(list);
    // Sinhvien *a = Nhap();
    // InsertLast(list, a);
    // Sinhvien *b = Nhap();
    // InsertLast(list, b);
    // Sinhvien *c = Nhap();
    // InsertLast(list, c);
    // Sinhvien *d = Nhap();
    // InsertLast(list, d);
    // Sinhvien *e = Nhap();
    // InsertLast(list, e);
    // Sinhvien *f = Nhap();
    // InsertLast(list, f);
    // Sinhvien *g = Nhap();
    // InsertLast(list, g);
    input(list, sv);
    cout <<"MSV\t|\tHo va Ten\t|\tDiem toan\t|\tDiem Ly\t|\tDiem Hoa\t|\tDiem TB"<< endl;
    PrintList(list);
}