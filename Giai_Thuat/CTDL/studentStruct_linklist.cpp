#include <iostream>
using namespace std;
// Cau truc Date gom ba thanh phan ngay, thang, nam
// Cau truc Date duoc dung de khai bao kieu du lieu cho truong DOB (ngay sinh) trong cau truc sinh vien
struct Date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
};
struct Student {
	unsigned int id;
	string name;
	Date DOB;
	float GPA;
	string sclass;
	string major;
};

typedef Student Item;

struct Node{
	Item data;
	Node *next;
};
// Dinh nghia cau truc SList
struct SList{
	Node *head;
	Node *tail;
	long size;
	
	SList();
	
	Node* CreateNode(Item v);	
	void addLast(Item v);	// Insert a new student at the end of the list.			
	Item SearchByID(unsigned int sid); 	// Find student information using student ID.		
	Item HighestGPA();	// Find one student with highest GPA.	
	int CountLowGPA();	// Count the number of students with low GPA (GPA < 4)
	void traverse() const;
};
// Khoi tao danh sach rong
SList::SList(){
	head = NULL;
	tail = NULL;
	size = 0;
}
// Ham xuat thong tin cua mot sinh vien ra man hinh
void printStudent(Item a) {
	cout << a.id << " | ";
	cout << a.name << " | ";
	cout << a.DOB.day << "/" << a.DOB.month << "/" << a.DOB.year << " | ";
	cout << a.GPA << " | ";
	cout << a.sclass << " | ";
	cout << a.major << endl;
}
// Ham xuat thong tin cua tat ca sinh vien ra man hinh
void SList::traverse() const {
	Node* p = head;
	while (p != NULL) {
		printStudent(p->data);
		p = p->next;
	}
	cout << endl;
	delete p;
}
// ======================================
// Cac ban viet cac ham theo yeu cau cua de bai tai day.
// Chu y: nguyen mau ham phai giong voi phan dinh nghia da neu trong cau truc SList o phia tren
// Cac ban can hoan thien 4 ham sau:
// 1.
// Ham addLast(Item v) de them mot sinh vien moi vao cuoi danh sach
// Ham addLast co input la thong tin cua mot sinh vien (bien v)
// Cac ban co the phai viet them ham CreateNode nhu huong dan tren lop ly thuyet
Node* SList::CreateNode(Item v){
	Node* p=new Node;
	p->data=v;
	p->next=NULL;
	return p;
}
void SList::addLast(Item v){
	Node *temp=CreateNode(v);
    if(size == 0){
        head = tail = temp;
        size++;
    }
    else{
	tail->next=temp;
	tail=temp;
	size++;
    }
}
// 2. 
// Ham SearchByID(unsigned int sid) de tim sinh vien voi ma cho truoc
// Ham SearchByID co input la ma sinh vien can tim (bien sid)
// Output cua ham SearchByID la thong tin cua sinh vien tim duoc
// (goi y: neu thong tin sinh vien can tim la nut co dia chi p, thi ham SearchByID can return p->data)
// Neu khong tim duoc sinh vien co ma cho truoc, tao mot bien kieu Item (gia su bien ten la x), 
// gan id cua bien x = 0, va ham SearchByID se tra ve x trong truong hop khong tim duoc
Item SList::SearchByID(unsigned int sid){
	Item x;
    Node *p = head;
    while(p->data.id !=sid){
        if(p->next == NULL){
            x.id=0;
            return x;
        }
        p=p->next;
    }
    return p->data;
}
// 3.
// Ham HighestGPA() de tim mot sinh vien co diem cao nhat trong danh sach
// Ham HighestGPA() tra ve thong tin cua sinh vien co diem cao nhat
// (goi y: neu thong tin cua sinh vien can tim la nut co dia chi p, thi ham HighestGPA can return p->data)
Item SList::HighestGPA(){
	Node* p = head;
    Node* cur = head->next;
    while(cur != NULL){
        if(cur->data.GPA > p->data.GPA){
            p = cur;
        }
        cur = cur->next;
    }
    return p->data;
}
// 4.
// Ham CountLowGPA() de dem so luong sinh vien co diem GPA duoi 4
// Ham CountLowGPA tra ve so luong dem duoc.
int SList::CountLowGPA(){
	int count=0;
	Node* p=head;
	while(p != NULL){
		if(p->data.GPA < 4.0){
			count ++;
		} 
		p=p->next;
	}
	return count;
}
