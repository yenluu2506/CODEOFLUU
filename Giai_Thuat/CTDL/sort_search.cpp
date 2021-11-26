#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *next;
};

struct SList{
    Node *head;
    Node *tail;
};

Node *createNode(int x){
    Node *temp = new Node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void printList(SList *l){
	Node *p = l->head;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

Node *addElement(Node*p, int x){
	Node *temp = createNode(x);
	p->next = temp;
	return temp;
}

void Selection_Sort(SList &l){
	Node *min;
	Node *p, *q;
	p = l.head;
	while(p != l.tail){
		min = p; q = p->next;
		while(q != NULL){
			if(q->data < min->data){
				min = q;
			}
			q= q->next;
    	}
		swap(min->data, p->data);
		p = p->next; 
	}
}

int main(){
	int n, x;
    cout << "Nhap so luong phan tu: ";
	cin >> n;
    cout << "Nhap phan tu thu 1: " << " : ";
	cin >> x;
	SList l;
	Node *p = createNode(x);
	for (int i = 1; i < n; i++){
        cout << "Nhap phan tu thu " << i+1 << " : ";
		cin >> x;
		p = addElement(p, x);
	}
	printList(&l);
    cout<< "Selection Sort: ";
    Selection_Sort(l);
    printList(&l);
	return 0;
}