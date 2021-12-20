//Cho mot linked list duoc sap xe[] theo thứ tự tăng dần, hãy viết một hàm loại 
//bỏ bất kỳ nút trùng lặp nào khỏi danh sách bằng cách duyệt qua danh sách chỉ một lần
//Cho ví dụ là:  {1, 2, 2, 2, 3, 4, 4, 5} 
//sau khi thực hiện sẽ được kết quả là: {1, 2, 3, 4, 5}

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

void removeDuplicate(Node *head){
    if(head == NULL)
        return;
    Node *current = head;
    while(current->next != NULL){
        if(current->data == current->next->data){
            Node *nextNext = current->next->next;
            current->next = nextNext;
        }
        else{
            current = current->next;
        }
    }
}

void print(Node *node){
    while(node != NULL){
        cout << "\t" << node->data;
        node = node->next;
    }
}

int main(){
    int key[] = {1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(key)/sizeof(key[0]);
    Node *head = NULL;
    for(int i=n-1; i>=0; i--){
        push(&head, key[i]);
    }
    removeDuplicate(head);
    print(head);
}