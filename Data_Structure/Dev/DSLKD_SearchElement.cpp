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

void insertAfter(Node *prevnode, int newdata){
    if(prevnode == NULL){
        cout << "This given previous cannot be NULL.";
        return;
    }
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}

void append(Node **head, int newdata){
    Node *newnode = new Node();
    Node *last = *head;
    newnode->data = newdata;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = newnode;
    return;
}

void print(Node *node){
    while(node != NULL){
        cout << "\t" << node->data;
        node = node->next;
    }
}

bool Search(Node *head, int x){
    Node *current = head;
    while(current != NULL){
        if(current->data == x){
            return true;
        }
        else{
            current = current->next;
        }
    }
    return false;
}

int main(){
    Node *head = NULL;
    push(&head, 17);
    append(&head, 7);
    insertAfter(head, 5);
    push(&head, 4);
    append(&head, 7);
    append(&head, 2);
    cout << "Create Linked list is: ";
    print(head);
    cout << endl;
    Search(head, 5) ? cout << "Yes" : cout << "No";
}