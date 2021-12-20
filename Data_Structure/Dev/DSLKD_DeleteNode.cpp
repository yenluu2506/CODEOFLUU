#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node *next;
};

void push(Node **head, int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = *head;
    *head = newnode;
}

void deleteNode(Node **head, int key){
    Node *temp = *head, *prev;
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) 
        return;
    prev->next = temp->next;
}

void print(Node *node){
    while(node != NULL){
        cout << "\t" << node->data;
        node = node->next;
    }
}

int main(){
    Node *head = NULL;
    push(&head, 9);
    push(&head, 3);
    push(&head, 7);
    push(&head, 12);
    push(&head, 1);
    push(&head, 8);
    cout << "Create linked list is: ";
    print(head);
    deleteNode(&head, 12);
    cout << "\nAfter delete: ";
    print(head);
}