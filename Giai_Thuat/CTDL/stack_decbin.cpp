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
// complete the function dec2bin
// this function is for converting decimal to binary
// input of function: an integer number
// output of function: stack s that contains all digits of binary number
stack dec2bin(int x) {
	  // WRITE YOUR CODE HERE
	stack s;
	int t;
	while (x != 0) {
		t = x % 2;
		s.push(t);
		x /= 2;
	}
	return s;
}
// complete printBin function
// this function is used to show the result of conversion
// input of function: stack s that contains all digits of binary number
// example result of the function:
// if the stack s has the following elements: 1, 0, 1, 1.
// printBin function should output 1011 onto the screen.
void printBin(stack s) {
	  // WRITE YOUR CODE HERE
	  Node* p = s.top;
		while (p != NULL) {
			cout << p->data;
			p = p->next;
		}
		cout << endl;
		delete p;
}
// =====================================================================================
// DO NOT MODIFY THE MAIN FUNCTION
int main() {	
	int n = 10;
	cout << n << " = "; 
	printBin(dec2bin(n));
	
	n = 15;
	cout << n << " = ";
	printBin(dec2bin(n));
	
	n = 123;
	cout << n << " = ";
	printBin(dec2bin(n));
	
	n = 67;
	cout << n << " = ";
	printBin(dec2bin(n));
	
	n = 865;
	cout << n << " = ";
	printBin(dec2bin(n));
	return 0;
}