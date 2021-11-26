//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include <iostream>
using namespace std;
struct Book{
    string name;
    int page;
};
void input(Book *b){
    fflush(stdin);
    cout << "Book name: ";
    getline(cin, b->name);
    cout << "Number of page: " ;
    cin >> b->page;
}
void inputList(Book *b,int &n){
    for(int i=0;i<n;i++){
        cout<<"\nBook "<<i+1<<endl;
        input(&*(b+i));
    }
}
void output(Book *b){
    cout <<" Name: "<<b->name<< ", Page: "<<b->page<<endl;
}
void swap(Book &a, Book &b){
    Book temp;
    temp = a;
    a = b; 
    b = temp;
}

//quick sort
void SortBook(Book *b, int left, int right){
    Book x = *(b+((left + right)/2));
    int i = left, j = right;
    do{
        while((b+i)->name < x.name) 
            i++;
        while ((b+j)->name > x.name)
            j--;
        if(i <= j){
            swap(*(b+i),*(b+j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j)
        SortBook(b,left,j);
    if(right > i)
        SortBook(b,i,right);
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//quick sort
void SortPage(Book *b, int left, int right){
    Book x = *(b+((left + right)/2));
    int i = left, j = right;
    do{
        while((b+i)->page > x.page) 
            i++;
        while ((b+j)->page < x.page)
            j--;
        if(i <= j){
            swap(*(b+i),*(b+j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j)
        SortPage(b,left,j);
    if(right > i)
        SortPage(b,i,right);
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

//binary search
Book findBook(Book *b, int n, string name){
    int left = 0, right = n-1, mid;
    while (left <= right){
        mid = (left + right)/ 2;
        if ((b+mid)->name == name)
            return b[mid];
        if ((b+mid)->name < name)
            left = mid+1;
        else
            right = mid-1;
    }
    Book notthing;
    return notthing;
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

void statistics(Book *b, int n, int p){
    int count = 0;
    for(int i=0; i < n; i++){
        if((b+i)->page < p){
            output(b+i);
            count++;
        }
    }
    if(count == 0){
        cout<<"Not found"<<endl;
    }
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int main(){
    Book *b;
    int n;
    cout<<"Enter number of book: "; 
    cin>>n;
    b = new Book[n];
    cout <<endl<<"Book infomation"<<endl;
    inputList(b, n);
    SortBook(b, 0, n-1);
    cout <<endl<<"Sort by name"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Number: "<<i+1;
        output(b+i);
    }
    SortPage(b, 0, n-1);
    cout <<endl<<"Sort by page"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Number: "<<i+1;
        output(b+i);
    }
    string name;
    cout<<"Enter book name to find: ";
    fflush(stdin);
    getline(cin, name);
    if(findBook(b, n, name).name == " "){
        cout<<"Not Found"<<endl;
    }else output(b);
    int p;
    cout<<"Enter page need to statistic: "; 
    cin>>p;
    statistics(b, n, p);
    delete [] b;
    return 0;
}
