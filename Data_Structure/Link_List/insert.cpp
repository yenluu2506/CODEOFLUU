#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Slist{
    Node *head;
    Node *tail;
};

Node CreateNode (int newdata){
    Node *node = new Node;
    node ->next = NULL;
    node->data = newdata;
}

void printList(){

}

int main(){

}