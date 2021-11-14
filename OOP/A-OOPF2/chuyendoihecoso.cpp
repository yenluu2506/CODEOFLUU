//#include <iostream>
//
//using namespace std;
//
//typedef int Item;
//
//struct Node {
//	Item data;
//	Node* next;
//};
//
//struct stack {
//	Node* top;
//	long size;
//
//	stack();
//	Node* CreateNode(Item v);
//	void push(Item v);
//	Item pop();
//};
//stack::stack() {
//	top = NULL;
//	size = 0;
//}
//Node* stack::CreateNode(Item v) {
//	Node* p = new Node;
//	p->data = v;
//	p->next = NULL;
//	return p;
//}
//void stack::push(Item v) {
//	Node* p = CreateNode(v);
//	p->next = top;
//	top = p;
//	size++;
//}
//Item stack::pop() {
//	Node* t = top;
//	Item data = top->data;
//	top = top->next;
//	delete t;
//	size--;
//	return data;
//}
//// Ham doi thap phan sang nhi phan
////void Convertbinary(int x) {
////	Stack Binary;
////	int temp;
////	Newstack(Binary);
////	while (x != 0) {
////		Push(Binary, (x % 2));
////		x = x / 2;
////	}
////	printf("\nKet qua: ");
////	while (Binary.Top != NULL)
////		printf("%d", Pop(Binary));
////}
//stack dec2bin(int x) {
//	// WRITE YOUR CODE HERE
//	int t;
//	stack s;
//	while (x != 0) {
//		Item t = x % 2;
//		s.push(x);
//		x /= 2;
//	}
//}
//void printBin(stack s) {
//	// WRITE YOUR CODE HERE
//	Node* p = s.top;
//		while (p != NULL) {
//			cout << p->data;
//			p = p->next;
//		}
//		cout << endl;
//		delete p;
//}
//// =====================================================================================
//// DO NOT MODIFY THE MAIN FUNCTION
//int main() {
//	int n = 10;
//	cout << n << " = ";
//	printBin(dec2bin(n));
//
//	n = 15;
//	cout << n << " = ";
//	printBin(dec2bin(n));
//
//	n = 123;
//	cout << n << " = ";
//	printBin(dec2bin(n));
//
//	n = 67;
//	cout << n << " = ";
//	printBin(dec2bin(n));
//
//	n = 865;
//	cout << n << " = ";
//	printBin(dec2bin(n));
//	return 0;
//}