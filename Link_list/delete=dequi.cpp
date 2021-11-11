/*Để xóa một cách đệ quy một nút của danh sách liên kết, chúng ta cần thực hiện các bước sau.
1.Chúng tôi chuyển nút * (con trỏ nút) làm tham chiếu đến hàm (như trong nút * & head)
2.Bây giờ vì con trỏ nút hiện tại có nguồn gốc từ nút tiếp theo của nút trước (được chuyển bằng tham chiếu) nên bây giờ nếu giá trị của con trỏ nút hiện tại bị thay đổi, giá trị của nút tiếp theo trước đó cũng bị thay đổi, đây là thao tác bắt buộc khi xóa nút ( tức là điểm nút trước đó tiếp theo của nút hiện tại (chứa khóa) tiếp theo).
3.Tìm nút có chứa giá trị đã cho.
4. Lưu trữ nút này để phân bổ nó sau này bằng cách sử dụng hàm free ().
5. Thay đổi con trỏ nút này để nó trỏ đến nó tiếp theo và bằng cách thực hiện tiếp theo của nút trước đó cũng được liên kết đúng cách.*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node *link = NULL;
    node (){}
    node (int a)
        :info(a){

        }
};

void deleteNode(node *&head, int val){
    if(head == NULL){
        cout << "Element not present in the list" << endl;
        return;
    }
    if(head->info == val){
        node *t = head;
        head = head->link;

        delete(t);
        return;
    }
    deleteNode(head->link, val);
}

void push(node*& head, int data){
    node* newnode = new node(data);
    newnode->link = head;
    head = newnode;
}

void print(node*head){
    if(head==NULL && cout << endl)
        return;
    cout << head->info << ' ';
    print(head->link);
}

int main(){
    node *head = NULL;
    push(head, 10);
    push(head, 12);
    push(head, 14);
    push(head, 15);

    print(head);

    deleteNode(head, 20);
    print(head);

    deleteNode(head, 10);
    print(head);

    deleteNode(head, 14);
    print(head);

    return 0;
}