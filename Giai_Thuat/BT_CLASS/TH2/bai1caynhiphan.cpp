//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include <iostream>
using namespace std;

typedef int Item;
struct Node {
	Item data;
	Node* left;
	Node* right;	
};
class BinaryTree {
public:	
	// methods
	BinaryTree();
	BinaryTree(Item v);
	Node* createNode(Item v);
	bool isEmpty();	
	void preOrder(Node* root);
	void inOrder(Node* root);
	void posOrder(Node* root);	
	Item deleteLeft(Node *p);
    Item deleteRight(Node *p);
	Node* search(Node* p, Item v);
	void insertLeft(Node* p, Item v);
    void insertRight(Node* p, Item v);
    void insert(Node *&root, Item v);
	void deleteTree(Node* &root);
    int height(Node *root);
    int countNode(Node *root);
    int countLa(Node *root);
    int countX(Node *root, int x);
    int MaxNode(Node *root);
    int MinNode(Node *root);
	// variable
	Node* root;	
};
BinaryTree::BinaryTree() {
	root = NULL;
}
BinaryTree::BinaryTree(Item v) {
	root = createNode(v);
}
bool BinaryTree::isEmpty() {
	return (root == NULL);
}
// tao 1 node voi du lieu v
Node* BinaryTree::createNode(Item v) {	
	// WRITE YOUR CODE HERE
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}

// chen 1 not moi bên trai
void BinaryTree::insertLeft(Node* p, Item v) {
    if (p == NULL){
        cout <<"Cannot insert to a NULL node."<< endl;
    }
    else if(p->left!=NULL){
        cout << "Left child existed."<< endl;
    }
    else{
        p->left = createNode(v);
    }
}
// chen 1 not moi ben phai
void BinaryTree::insertRight(Node* p, Item v) {
    if (p == NULL){
        cout <<"Cannot insert to a NULL node."<< endl;
    }
    else if(p->right!=NULL){
        cout << "Left child existed."<< endl;
    }
    else{
        p->right = createNode(v);
    }
}
void BinaryTree::insert(Node *&root, Item v){
	if(root != NULL){
		insert(root, v);
	}else{
		root = new Node;
		root->data = v;
		root->left = NULL;
		root->right = NULL;
	}
}
//xoa 1 node ben trai
Item BinaryTree::deleteLeft(Node *p){
    if(p==NULL){
        cout<<"Current node is NULL"<< endl;
        return -1;
    }
    else if(p->left==NULL){
        cout << "No left child to delete"<<endl;
        return -1;
    }
    else{
        Node *q=p->left;
        if(q->left!=NULL || q->right!=NULL){
            cout <<"Cannot delete non-leaf node"<<endl;
            return -1;
        }
        else{
            Item value = q->data;
            p->left=NULL;
            delete q;
            return value;
        }
    }
}

//xoa 1 node ben phai
Item BinaryTree::deleteRight(Node *p){
    if(p==NULL){
        cout<<"Current node is NULL"<< endl;
        return -1;
    }
    else if(p->right==NULL){
        cout << "No left child to delete"<<endl;
        return -1;
    }
    else{
        Node *q=p->right;
        if(q->left!=NULL || q->right!=NULL){
            cout <<"Cannot delete non-leaf node"<<endl;
            return -1;
        }
        else{
            Item value = q->data;
            p->right=NULL;
            delete q;
            return value;
        }
    }
}

void BinaryTree::deleteTree(Node *&root){
    if(root !=NULL){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

// duyet theo thu tu truoc cua cay
void BinaryTree::preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

// duyet theo thu tu giua cua cay
void BinaryTree::inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout << root->data<<"\t";
        inOrder(root->right);
    }
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//duyet theo thu tu sau
void BinaryTree::posOrder(Node* root){
    if(root!=NULL){
        posOrder(root->left);
        posOrder(root->right);
        cout << root->data<<"\t";
    }
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//tim kiem
Node* BinaryTree::search(Node *p, Item v){
    if(p==NULL)
        return NULL;
    if(p->data==v)
        return p;
    Node *q=search(p->left, v);
    if(q==NULL)
        q=search(p->right, v);
    return q;
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//tao mang
BinaryTree createFromArray(Item a[], int length) {
    BinaryTree b;
    for(int i = 0; i<length; i++){
        b.insert(b.root, a[i]);
    }
    return b;
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//tinh chieu cao
int BinaryTree::height(Node *root){
    if(root==NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    if(h1>h2)
        return h1+1;
    else return h2+1;
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//dem so nut
int BinaryTree::countNode(Node *root){
    if(root==NULL)
        return 0;
    else
        return 1+countNode(root->left) + countNode(root->right);
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//dem so la
int BinaryTree::countLa(Node *root){
    if(root==NULL)
        return 0;
    else
        return countLa(root->left) + countLa(root->right);
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//dem so nut co gia tri lon hon x
int BinaryTree::countX(Node *root, int x){
    if(root==NULL)
        return 0;
    if(root->data>x)
        return 1+countX(root->left, x)+countX(root->right,x);
    else
        return countX(root->left, x)+countX(root->right, x);
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//nut lon nhat
int BinaryTree::MaxNode(Node *root){
    if(root->right==NULL)
        return root->data;
    else
        return MaxNode(root->right);
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//nut nho nhat
int BinaryTree::MinNode(Node *root){
    if(root->left==NULL)
        return root->data;
    else   
        return MinNode(root->left);
}


//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
//tim max
int MaxNode(Node *root){	
    if (root == NULL)		
    return INT_MIN;	
    int max = root->data;	
    int rightMax = MaxNode(root->right);	
    int leftMax = MaxNode(root->left);		
    if (leftMax > max)		
    max = leftMax;	
    if (rightMax > max)		
    max = rightMax;	
    return max;
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
//tim min
int MinNode(Node *root){	
    if (root == NULL)		
    return INT_MAX;	
    int min = root->data;	
    int rightMin = MinNode(root->right);	
    int leftMin = MinNode(root->left);		
    if (leftMin > min)		
    min = leftMin;	
    if (rightMin > min)		
    min = rightMin;	
    return min;
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int main(){

	BinaryTree *tree = new BinaryTree();
    Node *p;
    Item v;
    int x;
    int a[] = {6, 2, 1, 4, 3, 9, 8, 7, 13, 11, 18};
	BinaryTree bt = createFromArray(a, sizeof(a)/sizeof(int));
    cout << "Binary tree truoc:\n";
	bt.preOrder(bt.root);
	cout << endl;
    cout << "Binary tree giua:\n";
	bt.preOrder(bt.root);
	cout << endl;
    cout << "Binary tree sau:\n";
	bt.preOrder(bt.root);
	cout << endl;
    cout<<"Tim kiem: "<< endl;
    bt.search(p, v);
    cout<<"Chieu cao: "<<endl;
    bt.height(bt.root);
    cout<<"So nut tren cay: "<<bt.countNode(bt.root)<< endl;
    cout<<"So la tren cay: "<<bt.countLa(bt.root)<< endl;
    cout << "Nhap x: ";
    cin >> x;
    cout << endl;
    cout<<"So nut co gia tri lon hon X: "<< bt.countX(bt.root, x)<<endl;
    cout<<"Nut co gia tri nho nhat: "<< bt.MinNode(bt.root)<<endl;
    cout<<"Nut co gia tri lon nhat: "<< bt.MaxNode(bt.root)<<endl;
}