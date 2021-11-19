#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
struct SingleList{
    Node *head;
};
void init(SingleList &list){
    list.head = NULL;
}

//tao node
Node * CreateNode(int newdata){
    Node *node = new Node;
    if(node!=NULL){
        node->data=newdata;
        node->next=NULL;
    }
    else{
        cout <<"Cap phat bo nho that bai!";
    }
    return node;
}

//xuat danh sach lien ket
void printList(SingleList list){
    Node *temp = list.head;
    if(temp==NULL){
        cout << "Danh sach rong!";
        return;
    }
    while(temp!=NULL){
        cout << temp->data << "  ";
        temp=temp->next;
    }
}

//dem so phan tu trong danh sach
int sizeOfList(SingleList list){
    Node *temp=list.head;
    int size = 0;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    return size;
}

//them phan tu vao dau danh sach
void insertFirst(SingleList list, int newdata){

}

int main(){

}