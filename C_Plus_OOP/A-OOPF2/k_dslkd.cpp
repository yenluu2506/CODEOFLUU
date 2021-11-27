#include <iostream>
#include "k_dslkd.h"
using namespace std;

//tao node
Node* createNode(Data data) {
	Node* node = new Node;
	if (node == NULL) {
		return NULL;
	}
	node->data = data; //Gan data cho node
	node->pnext = NULL; //pnext tro den NULL
}

//khoi tao danh sach
void initList(List& list) {
	list.pHead = list.pTail = NULL;
}

//kiem tra list rong
bool isEmpty(List list) {
	if (list.pHead == NULL) {
		return true;
	}
	return false;
}

//them phan tu node vao list
void addHead(List& list, Node* pNode) {
	if (isEmpty(list)) { //neu rong
		list.pHead = list.pTail = pNode;
	}
	else {
		pNode->pnext = list.pHead;
		list.pHead = pNode;
	}
}

//xuat danh sach
void printList(List list, char*mess){
	cout << mess << endl;
	if(isEmpty(list)){
		cout << "List rong"<< endl;
	}
	else{
		Node* node = list.pHead;
		while(node != NULL){
		cout << node -> data << endl;
		node = node->pnext;
	}
	}
}
