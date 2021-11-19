#include <iostream>
using namespace std;

typedef int Item;

struct Node{
	Item data;
	Node *next;
};

struct SList{
	Node *head;
	Node *tail;
	long size;
	
	SList();
	
	Node* CreateNode(Item v);
	void addFirst(const Item v);
	void insertAfter(Node *p, Item v);
	void insertBefore(Node *p, Item v);
	void addLast(Item v);
	void removeFirst();
	void removeLast();
	void remove(Node *p);		
	void traverse() const;
	Node* previous(Node *p);
};

SList::SList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

Node* SList::CreateNode(Item v)
{
	Node* p = new Node;
	p->data = v;	
	p->next = NULL;	
	return p; 
}

void SList::addFirst(const Item v){
	Node* p = CreateNode(v);
	p->next = head;
	head = p;
	if (size == 0)
		tail = p;
	size++;
}
void SList::addLast(Item v) {
	Node *p = CreateNode(v);
	if (size == 0) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;	  
	}
	size = size + 1;
}

void SList::traverse() const {
	Node* p = head;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
	delete p;
}
void testAddFirst()
{
	cout << "test addFirst function" << endl;
	SList list;	
	list.addFirst(5);
	list.addFirst(2);
	list.addFirst(7);
	list.traverse();
	cout << "head.data = " << list.head->data << endl;
	cout << "tail.data = " << list.tail->data << endl;
}
void testAddLast()
{
	cout << "test addLast function" << endl;
	SList list;	
	list.addLast(5);
	list.addLast(2);
	list.addLast(7);
	list.traverse();
	cout << "head.data = " << list.head->data << endl;
	cout << "tail.data = " << list.tail->data << endl;
}

int main() {
	testAddFirst();
	testAddLast();
	return 0;
}
