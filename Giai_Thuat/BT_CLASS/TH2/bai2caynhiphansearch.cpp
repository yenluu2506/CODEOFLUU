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
class BST {
public:	
	// methods
	BST();
	BST(Item v);
	Node* createNode(Item v);
	bool isEmpty();	
	void LNR(Node* root);
    void RNL(Node* root);	
	void deleteTree(Node* &root);
	Node* search(Node* p, Item v);
	void insert(Node* &root, Item v);
	Node* minValueNode(Node* p);
	Item leftMostValue(Node* root);
	Node* remove(Node* &root, int v);
	int Sum(Node* root);
    int MaxNode(Node *root);
    int MinNode(Node *root);
	// variable
	Node* root;	
};
BST::BST() {
	root = NULL;
}
BST::BST(Item v) {
	root = createNode(v);
}
bool BST::isEmpty() {
	return (root == NULL);
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

// traversal in LNR tang dan
void LNR(Node* root)
{
	if (root != NULL)
	{
		LNR(root->left);
		cout<< root->data << "\t";
		LNR(root->right);
	}
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

// traversal in RNL giam dan
void RNL(Node* root)
{
	if (root != NULL)
	{
		RNL(root->right);
		cout<< root->data << "\t";
		RNL(root->left);
	}
}
// create a new node with data v
Node* BST::createNode(Item v) {	
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}

// insert a new node
void BST::insert(Node* &root, Item v) {
    if (root == NULL){
        root = createNode(v);
    }
    else {
        if (v < root->data)
            insert(root->left,v);
        else if (v > root->data)
            insert(root->right,v);
    }	
}
Node* BST::minValueNode(Node* p) 
{ 
    if(p->left == NULL){
        return p;
    }
    return minValueNode(p->left);
} 

Item BST::leftMostValue(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root->data;
}
Node* BST::remove(Node* &root, int v)
{
    if (root == NULL)
        return root;
    if (v < root->data)
        root->left = remove(root->left, v);
    else if (v > root->data)
        root->right = remove(root->right, v);
    else{
        if(root->left == NULL){
            Node* newRoot=root->right;
            delete root;
            return newRoot;
        }
        if(root->right == NULL){
            Node* newRoot = root->left;
            delete root;
            return newRoot;
        }
        root->data = leftMostValue(root->right);
        root->right = remove(root->right, root->data);
    }
    return root;
}

////Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

// create a BST with keys from an array
BST createFromArray(Item a[], int length) {
    BST b;
    for(int i = 0; i<length; i++){
        b.insert(b.root, a[i]);
    }
    return b;
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//nut lon nhat
int BST::MaxNode(Node *root){
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
int BST::MinNode(Node *root){
    if(root->left==NULL)
        return root->data;
    else   
        return MinNode(root->left);
}


//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//tinh tong
int BST::Sum(Node*root){
	if(root!=NULL){
		int a=Sum(root->left);
		int b=Sum(root->right);
		return root->data + a + b;
	}
	return 0;
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int main(){
    int a[] = {6, 2, 1, 4, 3, 9, 8, 7, 13, 11, 18};
	BST bst = createFromArray(a, sizeof(a)/sizeof(int));	
			
	cout << "Tang dan:\n";
	bst.LNR(bst.root);
	cout << endl;

    cout << "Giam dan:\n";
	bst.RNL(bst.root);
	cout << endl;
	
	cout << "Delete node 3:\n";
	bst.root = bst.remove(bst.root, 3);		
	bst.LNR(bst.root);
	cout << endl;

    cout<<"Max node: "<<bst.MaxNode(bst.root)<<endl;
    cout<<"Min node: "<<bst.MinNode(bst.root)<<endl;

    cout << "Sum: "<< bst.Sum(bst.root) <<endl;
}