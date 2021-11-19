//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
#include <iostream>
using namespace std;

typedef int Item;

struct Node{
	Item data;
	Node *next;
};

struct stack{
	Node *top;
	long size;
	
	stack();
	Node* CreateNode(Item v);		
	void push(Item v);
	Item pop();
};
stack::stack() {
	top = NULL;
	size = 0;
}
Node* stack::CreateNode(Item v) {
	Node* p = new Node;
	p->data = v;	
	p->next = NULL;	
	return p; 
}	
void stack::push(Item v) {
	Node* p = CreateNode(v);
	p->next = top;
	top = p;	
	size++;
}
Item stack::pop() {	
	Node *t = top;
	Item data = top->data;
	top = top->next;
	delete t;
	size--;	
	return data;
}
stack dec2bin(int x) {
	stack s;
	int t;
	while (x != 0) {
		t = x % 2;
		s.push(t);
		x /= 2;
	}
	return s;
}
void printBin(stack s) {
	  Node* p = s.top;
		while (p != NULL) {
			cout << p->data;
			p = p->next;
		}
		cout << endl;
		delete p;
}
int main() {
    int n;
    cout<< "Enter value n: ";
    cin>>n;
    cout << n << " = " ;
    printBin(dec2bin(n));
	return 0;
}