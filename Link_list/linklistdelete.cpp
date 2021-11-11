#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node *next;
        int data;
};

void push(Node **head, int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = *head;
    *head = newnode;
}

void deleteNode(Node **head, int key){
    //luu tru nut dau
    Node *temp = *head;
    Node *prev = NULL;
    //neu chinh nut dau giu, khoa se bi xoa
    if(temp!=NULL && temp->data==key){
        *head = temp->next; // da thay doi dau
        delete temp; //dau cu giai phong
        return;
    }
    //nguoc lai tim kiem key se bi xoa
    //giu nut truoc do, can thay doi "prev->next"
    else{
        while(temp!=NULL && temp->data!=key){
            prev = temp;
            temp = temp->next;
        }
        //neu key khong co trong danh sach lien ket
        if(temp==NULL)
            return;
        //bo lien ket node khoi danh sach duoc lien ket
        prev->next = temp->next;
        //giai phong bo nho
        delete temp;
    }
}

void printList(Node *node){
    while(node!=NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

int main(){
    Node *head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);

    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}