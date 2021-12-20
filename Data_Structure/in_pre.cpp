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
void printTree(Node *t){
    if(t != NULL){
        printTree(t->left);
        cout << t->data << " ";
        printTree(t->right);
    }
}

int main(){
    int n, x;
    cin >> n;
    Node *t = NULL;
    for(int i=0; i<n; i++){
        cin >> x;
        t = insert(t, x);
    }
    printTree(t);
}