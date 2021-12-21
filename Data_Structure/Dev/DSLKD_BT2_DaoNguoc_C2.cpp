//Bài 2: Đảo ngược mọi nhóm k nút trong danh sách liên kết đã cho
//Cho một danh sách liên kết, đảo ngược mọi nhóm k nút liền kề trong đó với k là số nguyên dương.
//Input: 1>2>3>4>5>6>7>8>null
//k = 3
//Output: 3>2>1>6>5>4>8>7>null

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
    while(node != NULL){
        cout << "\t" << node->data;
        node = node->next;
    }
}

Node *reverse (Node **current, int k){
    Node *prev = NULL;
    int count = 0;
    while(*current && count++ < k){
        Node *next = (*current)->next;
        (*current)->next = prev;
        prev = *current;
        *current = next;
    }
    return prev;
}

void reverseInGroup(Node **head, int k){
    if(*head == NULL){
        return;
    }
    Node *current = *head;
    Node *prev = reverse(&current, k);
    reverseInGroup(&current, k);
    (*head)->next = current;
    *head = prev;
}

int main(){
    int key[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(key)/sizeof(key[0]);

    Node *head = NULL;
    for(int i = n-1; i>=0; i--){
        push(&head, key[i]);
    }
    reverseInGroup(&head, 3);
    print(head);
}