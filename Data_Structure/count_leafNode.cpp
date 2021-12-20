#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *t, int x){
    if (t==NULL){
        Node *tmp = new Node;
        tmp->data = x;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    else{
        if(x<t->data){
            t->left = insert (t->left, x);
        }
        else{
            t->right = insert(t->right, x);
        }
    }
}
bool isLeafNode(Node *l){
    return (l->left==NULL && l->right==NULL);
}
int countLeafNode(Node *t){
    if(t==NULL)
        return 0;
    if(isLeafNode(t))
        return 1;
    return countLeafNode(t->left) + countLeafNode(t->right);
}

int main(){
    int n, x;
    cin >> n;
    Node *t = NULL;
    for(int i=0; i<n; i++){
        cin >> x;
        t = insert(t, x);
    }
    cout << "So nut la: " << countLeafNode(t);
}