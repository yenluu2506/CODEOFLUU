//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include <iostream>
using namespace std;
struct AnVi
{
	string Anh;
	string viet;
};
typedef AnVi Item;
struct Node {
	Item data;
	Node* left;
	Node* right;	
};
class BST {
public:	
	BST();
	BST(Item v);
	Node* createNode(Item v);	
	Node* search(Node* p, string v);
	void insert(Node* &root, Item v);
	Node* minValueNode(Node* p);
	void LNR(Node* root);
	Node* remove(Node* &root, Item v);
	Node* root;	
};
BST::BST() {
	root = NULL;
}
BST::BST(Item v) {
	root = createNode(v);
}
Node* BST::createNode(Item v) {	
   Node *p = new Node;
    p->data = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void BST::LNR(Node* root) {
	if (root != NULL) {
		LNR(root->left);
		cout << root->data.Anh << " : "<<root->data.viet<<endl;
		LNR(root->right);
	}
}
//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//them mot nut
void BST::insert(Node* &root, Item v) {
    	if(root== NULL)
        {
            root = createNode(v);
        }
        else
        {
           if(root->data.Anh.compare(v.Anh)>0 )
            insert(root->left,v);
           else if(root->data.Anh.compare(v.Anh)<0)
            insert(root->right,v);
        }
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//tim kiem theo mot tu khoa
Node* BST::minValueNode(Node* p) 
{ 
     Node* Temp= p;
    while(Temp->left != NULL)
      Temp=Temp->left;
    return Temp; 
} 
Node* BST::search(Node* root, string v)
{
    while(root !=NULL)
	{
	   if(root->data.Anh.compare(v)==0)
	    return root;
	   if(root->data.Anh.compare(v)>0)
	   {
	     root=root->left;	
	   }
	   else
	   {
	   	 root=root->right;
		}		
	}
	return NULL;    
}

//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//xoa mot nut
Node* BST::remove(Node* &root, Item v)
{
    if(root== NULL)
     return root;
    if(root->data.Anh.compare(v.Anh)>0)
          root->left= remove(root->left,v);
    else if(root->data.Anh.compare(v.Anh)<0)
          root->right=remove(root->right,v);
   else
   {
       if(root->left == NULL)
       {
           Node* temp = root->right;
           delete root;
           return temp;
       }
       else if(root->right == NULL)
       {
           Node* temp = root->left;
           delete root;
           return temp;
       }
        Node* temp = minValueNode(root->right);
       root->data = temp->data;
       root->right = remove(root->right, temp->data);
   }
   return root;
}


//Ho ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int main()
{
	BST b;
	int n;
	cout<<"\nNhap so luong node can them: ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		AnVi T;
		cout<<"\nNhap node thu "<<i+1;
		cout<<"\nNhap khoa tieng anh: ";
		fflush(stdin);
		cin>>T.Anh;
		cout<<"\nNhap nghia tieng viet: ";
		fflush(stdin);
		cin>>T.viet;
		b.insert(b.root,T);
	}
	b.LNR(b.root);
	string Tk;
	cout<<"\nNhap tu khoa can tim: ";
	fflush(stdin);
	cin>>Tk;
	if(b.search(b.root,Tk) == NULL)
	  cout<<"\nKhong tim duoc tu khoa !";
	else
	{
		cout<<"\nThong tin tu khoa can tim:"<<endl;
		cout<<"\n"<<b.search(b.root,Tk)->data.Anh<<" : "<<b.search(b.root,Tk)->data.viet;
	}
	AnVi G;
	cout<<"\nNhap khoa can xoa: ";
	fflush(stdin);
	cin>>G.Anh;
	b.root=b.remove(b.root,G);
	cout<<"\nCay vua xoa"<<endl;
	b.LNR(b.root);	    
}