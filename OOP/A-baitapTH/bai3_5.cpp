#include <iostream>
#include <string>
using namespace std;
class Media
{
    protected:
        string name;
        float cost;
    public:
        Media();
        virtual void input(){}
        virtual void output(){}
};
Media::Media()
{
    this->name = "";
    this->cost = 0;
}
class Book : public Media
{
    private:
        int page;
        string author;
    public: 
        Book();
        void input();
        void output();
};
Book::Book()
{
    this->page = 0;
    this->author = "";
}
void Book::input()
{
    cout<<"Nhap ten phuong tien: "<<endl;
    getline(cin, name);
    cout<<"Nhap gia ban phuong tien: "<<endl;
    cin>>cost;
    cout<<"Nhap so trang: "<<endl;
    cin>>page;
    cout<<"Nhap tac gia: "<<endl;
    cin.ignore(1);
    getline(cin, author);
}
void Book::output()
{
    cout<<"Ten phuong tien: "<<name<<endl;
    cout<<"Gia phuong tien: "<<cost<<endl;
    cout<<"So trang: "<<page<<endl;
    cout<<"Tac gia: "<<author<<endl;
}
class Video : public Media
{
    private:
        int runtime;
        float price;
    public:
        Video();
        void input();
        void output();
};
Video::Video()
{
    this->runtime = 0;
    this->price = 0;
}
void Video::input()
{
    cout<<"Nhap ten phuong tien: "<<endl;
    cin.ignore(0);
    getline(cin, name);
    cout<<"Nhap gia ban phuong tien: "<<endl;
    cin>>cost;
    cout<<"Nhap thoi gian chay: "<<endl;
    cin>>runtime;
    cout<<"Nhap gia ban video: "<<endl;
    cin>>price;
}
void Video::output()
{
    cout<<"Ten phuong tien: "<<name<<endl;
    cout<<"Gia phuong tien: "<<cost<<endl;
    cout<<"Thoi gian chay: "<<runtime<<endl;
    cout<<"Gia video: "<<price<<endl;
}
int main()
{
    Media *book = new Book;
    Media *video = new Video;
    book->input();
    book->output();
    video->input();
    video->output();
}