#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

//chen vao dau danh sach - co 4 buoc
void push(Node** head, int newdata)
{
    //cap phat bo nho
    Node *newnode = new Node();
    //dua du lieu vao
    newnode->data = newdata;
    //thuc hien tiep theo cua nut moi lam dau 
    newnode->next = *head;
    // di chuyen dau de tro den nut moi
    *head = newnode;
}

//chen vao sau mot nut - 5 buoc
void insertAfter(Node *preNode, int newdata)
{
    //kiem tra xem gia tri da cho co phai la NULL khong
    if(preNode == NULL){
        cout << "The given previous node cannot be NULL.";
        return;
    }
    //cap phat bo nho
    Node *newnode = new Node();
    //dua du lieu vao
    newnode->data = newdata;
    // thuc hien next cua node moi bang preNode
    newnode->next = preNode->next;
    //di chuyen next cua preNode bang newnode
    preNode->next = newnode;
}

//chen node vao cuoi - 6 buoc
void append(Node **head, int newdata)
{
    //cap phat bo nho
    Node *newnode = new Node();

    Node *last = *head;
    //dua du lieu vao
    newnode->data = newdata;
    //nut moi la nut cuoi cung, vi vay nut tiep theo cua no la NULL
    newnode->next = NULL;
    //neu danh sach rong, dat nut moi lam dau
    if(*head == NULL){
        *head = newnode;
        return;
    }
    //mac khac tro cho den nut cuoi cung
    while(last->next!=NULL){
        last = last->next;
    }
    //thay doi next cua node cuoi cung
    last->next = newnode;
    return;
}

void print(Node *node)
{
    while(node != NULL){
        cout << "\t" << node->data;
        node = node->next;
    }
}

int main(){
    Node *head = NULL;
    append(&head, 6);
    push(&head, 8);
    push(&head, 4);
    append(&head, 16);
    insertAfter(head->next, 5);
    cout << "Create Link List is: ";
    print(head);
}