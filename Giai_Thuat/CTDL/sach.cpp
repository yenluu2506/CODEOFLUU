#include <iostream>
using namespace std;
class Book{
    private:
        string name;
        int page;
    public:
        Book();
        void input();
        void output();
        string getName(){
            return name;
        }
        int getPage(){
            return page;
        }
};
Book::Book(){
    name = " ";
    page = 0;
}
void Book::input(){
    fflush(stdin);
    cout << "Book name: ";
    getline(cin, name);
    cout << "Number of page: " ;
    cin >> page;
}
void Book::output(){
    cout <<" Name: "<<name<< ", Page: "<<page<<endl;
}
void swap(Book &a, Book &b){
    Book temp;
    temp = a;
    a = b; 
    b = temp;
}
void SortBook(Book *a, int left, int right){//quick sort
    Book x = *(a+((left + right)/2));
    int i = left, j = right;
    do{
        while((a+i)->getName() < x.getName()) 
            i++;
        while ((a+j)->getName() > x.getName())
            j--;
        if(i <= j){
            swap(*(a+i),*(a+j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j)
        SortBook(a,left,j);
    if(right > i)
        SortBook(a,i,right);
}
void SortPage(Book *a, int left, int right){//quick sort
    Book x = *(a+((left + right)/2));
    int i = left, j = right;
    do{
        while((a+i)->getPage() > x.getPage()) 
            i++;
        while ((a+j)->getPage() < x.getPage())
            j--;
        if(i <= j){
            swap(*(a+i),*(a+j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j)
        SortPage(a,left,j);
    if(right > i)
        SortPage(a,i,right);
}
Book findBook(Book *a, int n, string name){//binary search
    int left = 0, right = n-1, mid;
    while (left <= right){
        mid = (left + right)/ 2;
        if ((a+mid)->getName() == name)
            return a[mid];
        if ((a+mid)->getName() < name)
            left = mid+1;
        else
            right = mid-1;
    }
    Book notthing;
    return notthing;
}
void statistics(Book *a, int n, int p){
    int count = 0;
    for(int i=0; i < n; i++){
        if((a+i)->getPage() < p){
            (a+i)->output();
            count++;
        }
    }
    if(count == 0){
        cout<<"Not found"<<endl;
    }
}
int main(){
    Book *list;
    int n;
    cout<<"Enter number of book: "; cin>>n;
    list = new Book[n];
    cout <<endl<<"Book infomation"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Book "<<i+1<<endl;
        (list+i)->input();
    }
    for (int i=0; i < n; i++){
        cout <<"Number: "<<i+1;
        (list+i)->output();
    }
    SortBook(list, 0, n-1);
    cout <<endl<<"Sort by name"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Number: "<<i+1;
        (list+i)->output();
    }
    SortPage(list, 0, n-1);
    cout <<endl<<"Sort by page"<<endl;
    for (int i=0; i < n; i++){
        cout <<"Number: "<<i+1;
        (list+i)->output();
    }
    string name;
    cout<<"Enter book name to find: ";
    fflush(stdin);
    getline(cin, name);
    if(findBook(list, n, name).getName() == " "){
        cout<<"Not Found"<<endl;
    }else findBook(list, n, name).output();
    int p;
    cout<<"Enter page need to statistic: "; cin>>p;
    statistics(list, n, p);
    delete [] list;
    return 0;
}