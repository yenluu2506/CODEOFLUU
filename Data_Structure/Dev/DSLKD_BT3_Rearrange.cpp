//Cho một danh sách được liên kết, hãy di chuyển nút cuối cùng của nó lên phía trước.
//Ví dụ: Input: 1,2,3,4
//Output: 4,1,2,3

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

void rearrange(Node **head){
    //kiem tra va chi tiep tuc thuc hien khi danh sach hop le
    if(!*head || !(*head)->next){
        return;
    }
    Node *ptr = *head;
    //chuyen den nut cuoi cung thu hai
    while(ptr->next->next){
        ptr = ptr->next;
    }
    //chuyen danh sach thanh hinh tron
    ptr->next->next = *head;
    //sua con tro dau
    *head = ptr->next;
    //end thay doi
    ptr->next = NULL;
}

int main(){
    int key[] = {1,2,3,4};
    int n = sizeof(key)/sizeof(key[0]);
    Node *head = NULL;
    for(int i=n-1; i>=0; i--){
        push(&head, key[i]);
    }
    rearrange(&head);
    print(head);
}