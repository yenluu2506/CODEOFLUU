//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include<iostream>
using namespace std;

struct node{
	int data;  
	node *next; 
};

struct SList{
	node *head; 
	node *tail; 
}; 

void init(SList &list){
	list.head =NULL;
	list.tail =NULL;
}

node *CreateNODE(int x){
	node *p =new node; 
	if (p ==NULL){
		return NULL;
	}
	p->data =x; 
	p->next =NULL; 
	return p; 
}

void addHead(SList &list, node *p){
	if (list.head ==NULL){
		list.head = list.tail = p; 
	}
	else{
		p->next =list.head; 
		list.head =p; 
	}
}

void addLast(SList &list, node *p){
	if (list.head ==NULL){
		list.head = list.tail = p; 
	}
	else{
		list.tail->next=p; 
		list.tail =p; 
	}
}

void NhapDSSN(SList &list){
	init(list);
	int n;
	cout << "\nNhap so luong phan tu: ";
	cin >> n;
    int x;
	for (int i = 1; i <= n; i++){
		cout << "\nNhap gia tri: ";
		cin >> x;
		node *p = CreateNODE(x); 
		addLast(list, p); 
	}
}
//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
void input2(SList &list){
	init(list);
	int n;
	cout << "\nNhap so luong phan tu: ";
	cin >> n;
	int x;
    do{
        for (int i = 1; i <= n; i++){
		cout << "\nNhap gia tri: ";
		cin >> x;
		node *p = CreateNODE(x); 
		addLast(list, p); 
	    }
    }while(x!=0);
}
//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
void output(SList list){
	for (node *p = list.head; p!= NULL;p =p->next){
		cout << p->data << " ";
	}
}
//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
int TBC(SList list){
 	int s = 0;
 	for (node *p =list.head;p != NULL ;p =p->next){
  		s += p->data;
 	}
    int tbc = (float)s/Dem(list);
}
//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
int Dem(SList list){   
    int dem=0;
	for (node *p = list.head;p != NULL;p = p->next){
		if (p->data != NULL){
			dem++;
		}
	}
	return dem;
}
//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn
int Max(SList list){
	int max = list.head->data; 
	for (node *p = list.head->next;p != NULL; p =p ->next){
		if (max < p->data){
			max = p->data;
		}
	}
	return max;
}

/*void ChenSau(list &l,int x, int y){
	cout<<"\nNhap data can tim: ";
	cin>>x;
	cout<<"\nNhap gia tri can them sau: ";
	cin>>y;
	for(node *p=l.pHead;p!=NULL;p =p->pNext){
		if(p->data=x){
			node*k = KhoiTaoNode(y);
			k->pNext=p->pNext;
			k->pNext=p;
		}
}*/

int main(){
	SList list;
	int n;
	cout<<"\nNhap danh sach so nguyen cho truoc so luong phan tu"<<endl;
	NhapDSSN(list);
    // cout<<"\nNhap danh sach so nguyen cho truoc so luong phan tu"<<endl;
	// input2(list);
	cout<<"\nDanh sach so nguyen vua nhap la: ";
	output(list);
	cout<<"\nSo nguyen lon nhat trong dslk don: " <<Max(list);

	cout<<"\nTrung binh cong cua cac phan tu trong dslk don: "<<endl;
    TBC(list);
	cout<<"\nDem so phan tu co trong dslk don: " <<Dem(list)<<endl;
}