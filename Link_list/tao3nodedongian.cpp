#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//khởi tạo Node
class Node{
public: 
    Node *next;
    int data;
};

//hàm in ra nội dung của danh sách liên kết
void printList(Node *n){
    while(n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
}


int main(){
    //gán gia tri NULL cho 3 phần tử
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // cấp phát bộ nhớ
    head = new Node();
    second = new Node();
    third = new Node();

    //gán head = 2
    head->data = 1;
    head->next = second; 

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    //in ra danh sách
    printList(head);
}