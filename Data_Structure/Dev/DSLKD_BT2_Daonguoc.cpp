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

//Hàm lặp lại để đảo ngược k nút đầu tiên của danh sách liên kết
Node *revereK(Node **current, int k){
    Node *prev = NULL;
    int count = 0;
    // Lặp lại danh sách và di chuyển / chèn từng nút vào 
    // phía trước danh sách kết quả (giống như một lần đẩy nút)
    while(*current && count++ < k){
        // tricky: lưu ý nút tiếp theo
        Node *next = (*current)->next;
        // di chuyển nút hiện tại vào kết quả
        (*current)->next = prev;
        // cập nhật con trỏ trước đó thành nút hiện tại
        prev = *current;
        // di chuyển đến nút tiếp theo trong danh sách
        *current = next;
    }
    // trả về nút được xử lý cuối cùng
    return prev;
}

//Chức năng đảo ngược mọi nhóm k nút trong danh sách liên kết đã cho
Node *reverseInGroups(Node *head, int k){
    if(head == NULL)
        return NULL;
    // bắt đầu với nút current
    Node *current = head;
    // đảo ngược k nút tiếp theo
    Node *prev = revereK(&current, k);
    // lặp lại cho các nút còn lại
    head->next = reverseInGroups(current, k);
    return prev;
}

int main(){
    int keys[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(keys)/sizeof(keys[0]);
    
    Node *head = NULL;
    for(int i=n-1; i>=0; i--){
        push(&head, keys[i]);
    }
    head = reverseInGroups(head, 3);
    print(head);
}