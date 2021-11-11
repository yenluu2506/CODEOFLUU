#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node *next;
        int data;
};

//chèn node vào đầu danh sách có 4 bước
void push(Node** head, int newdata){
    //1. cấp phát bộ nhớ, phân bổ nút
    Node *newnode = new Node();
    //2. đưa dữ liệu vào
    newnode->data = newdata;
    //3. đặt next của nút mới làm đầu
    newnode->next = (*head);
    //4. di chuyển head để trỏ đến node mới
    (*head) = newnode;
}

void insertAfter(Node *prev_node, int newdata){
    //kiem tra xem nut truoc do co phai la NULL khong
    if(prev_node == NULL){
        cout << "The given previous node can't be NULL";
        return;
    }
    //tao 1 node moi
    Node *newnode = new Node();
    //dua du lieu vao
    newnode->data = newdata;
    //thuc hien next cua node moi la next cua prev_node
    newnode->next = prev_node->next;
    //di chuyen next cua prev_node thanh new node
    prev_node->next = newnode;
}

void append(Node **head, int newdata){

    //cap phat node moi
    Node *newnode = new Node();
    //khoi tao bien cuoi
    Node *last = *head;
    //dua du lieu vao node moi
    newnode->data = newdata;
    //node moi nay se la cuoi cung vi vay gan next cua node la NULL
    newnode->next = NULL;
    //neu dslk trong thi tao node moi lam dau
    if(*head == NULL){
        *head = newnode;
        return;
    }
    //nguoc lai duyet cho den node cuoi cung
    while(last->next!=NULL){
        last = last->next;
    }
    //thay doi next cua node cuoi cung
    last->next = newnode;
    return;
}
//ham in danh sach ra man hinh
void print(Node *node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

int main(){
    //bat dau voi danh sach trong
    Node *Head = NULL;
    //chen 6 vao danh sach tro thanh 6->NULL
    append(&Head, 6);
    //chen 7 vao dau danh sach 7->6->NULL
    push(&Head, 7);
    //chen 1 vao dau danh sach 1->7->6->NULL
    push(&Head, 1);
    //chen 4 vao cuoi danh sach 1->7->6->4->NULL
    append(&Head, 4);
    //chen 8 sau 7 danh sach 1->7->8->6->4->NULL
    insertAfter(Head->next, 8);

    cout << "Create Link List is: ";
    print(Head);
    return 0;
}