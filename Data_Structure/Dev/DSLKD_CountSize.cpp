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

void print(Node *node){
    while (node != NULL)
    {
        cout << "\t" << node->data;
        node = node->next;
    }
    
}

int Count(Node *head){
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count ++;
        current = current->next;
    }
    return count;
}

int main(){
    Node *head = NULL;
    push(&head, 3);
    push(&head, 9);
    push(&head, 4);
    push(&head, 6);
    push(&head, 7);
    push(&head, 5);
    push(&head, 1);
    cout << "Create Linked list is: ";
    print(head);
    cout << "\nCout of Nodes is: " << Count(head);
}