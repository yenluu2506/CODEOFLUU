//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include <iostream>
using namespace std;

typedef int Item;

struct Node {
    Item data;
    Node* next;
};

struct Slist {
    Node* head;
    Node* tail;
    long size;
    Slist();
    Node* createNode(Item v);
    void addFirst(const Item v);
    void addLast(Item v);
    Node* Previous(Node* p);
    void Traverser();
};

Slist::Slist(){
    head = NULL;
    tail = NULL;
    size = 0;
}

Node* Slist::createNode(Item v){
    Node* p = new Node;
    p->data = v;
    p->next = NULL;
    return p;
}

void Slist::addFirst(const Item v){
    Node* p = createNode(v);
    p->next = head;
    head = p;
    if(size == 0)
        tail = p;
    size++;
}

void Slist::addLast(Item v){
    Node* p = createNode(v);
    if (size == 0){
		head = p;
		tail = p;
	}
	else{
		tail->next = p;
		tail = p;	  
	}
	size++;
}

Node* Slist::Previous(Node* p){
    Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}

void Slist::Traverser(){
    Node* p = head;
    while(p != NULL){
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
    delete p;
}

void Swap(Item &a, Item &b) {
    Item tmp = a;
    a = b;
    b= tmp;
}

//Bubble Sort
void BubbleSort(Slist sl) {
    Node *p, *q;
    p = sl.head;
    while(p != NULL) {
        q = p->next;
        while(q != NULL) {
            if(p->data > q->data)
                Swap(p->data, q->data);
            q = q->next;
        }
        p = p->next;
    }
}

//Selection Sort
void SelectionSort(Slist sl) {
    Node *p, *q, *min;
    p = sl.head;
    while(p != NULL) {
        min = p;
        q = p->next;
        while(q != NULL) {
            if(min->data > q->data)
                min = q;
            q = q->next;
        }
        Swap(p->data, min->data);
        p = p->next;
    }
}

//Linear Search
Item LinearSeach(Slist sl, Item key) {
    Node* p = sl.head;
    Item count = 0;
    while(p != NULL) {
        if(p->data == key)
            return count;
        count++;
        p = p->next;
    }
    return -1;
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int main() {
    Slist list;
    Item key;
    if(list.head == NULL)
        cout << "HEAD = NULL" << endl;
    if(list.tail == NULL)
        cout << "TAIL = NULL" << endl;
    cout << endl;
    list.addFirst(55);
    list.addFirst(25);
    list.addFirst(40);
    list.addLast(45);
    list.addLast(10);
    list.Traverser();
    cout << "\nBuble sort: " << endl;
    BubbleSort(list);
    list.Traverser();
    cout << "\nSelection sort: " << endl;
    SelectionSort(list);
    list.Traverser();
    cout << "\nNhap phan tu: "; cin >> key;
    if(LinearSeach(list, key) == -1)
        cout << "\nKhong co phan tu " << key << " trong danh sach!";
    else
        cout << "\nPhan tu " << key << " o vi tri: " << LinearSeach(list, key) << endl;
}