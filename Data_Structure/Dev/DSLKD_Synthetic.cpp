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

void insertAfter(Node *prev, int newdata){
    if(prev == NULL){
        cout << "The given previous cannot be NULL.";
        return;
    }
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = prev->next;
    prev->next = newnode;
}

void append(Node **head, int newdata){
    Node *newnode = new Node();
    Node *tail = *head;
    newnode->data = newdata;
    newnode->next = NULL;
    if(*head==NULL){
        tail = *head;
        return;
    }
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newnode;
    return;
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
    while(node!=NULL){
        cout << "\t"<< node->data;
        node = node->next;
    }
}

int Count(Node *head){
    Node *current = head;
    int count = 0;
    while(current!=NULL){
        current = current->next;
        count ++;
    }
    return count;
}

bool Search(Node *head, int x){
    Node *current = head;
    while(current!=NULL){
        if(current->data == x)
            return true;
        current = current->next;
    }
    if(current == NULL)
        return false;
}

int main(){
    Node *head = NULL;
    push(&head, 8);
    append(&head, 12);
    insertAfter(head, 1);
    push(&head, 9);
    push(&head, 4);
    append(&head, 18);
    insertAfter(head, 10);
    append(&head, 5);
    cout << "Create Link list is: ";
    print(head);
    cout << endl;
    cout << "Delete: ";
    deleteNode(&head, 4);
    print(head);
    cout << "\nCount list node is: "<< Count(head);
    cout << endl;
    Search(head, 1) ? cout << "Yes" : cout << "No";
}