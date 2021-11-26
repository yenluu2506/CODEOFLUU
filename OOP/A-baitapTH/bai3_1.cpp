#include<iostream>
using namespace std;
#define Pi 3.14
class Shape{
    public:
        virtual void input(){

        }
        virtual void output(){

        }
        virtual float acreage(){
            return 0;
        }
};

class Circle : public Shape{
    private:
        float radius;
    public:
        Circle();
        void input();
        void output();
        float acreage(); 
};
Circle::Circle(){
    this->radius = 1;
}
void Circle::input(){
    cout<<"Nhap ban kinh hinh tron: "<<endl;
    cin>>radius;
}
void Circle::output(){
    float radiuss = acreage();
    cout<<"Dien tich hinh tron la: "<<radiuss<<endl;
}
float Circle::acreage(){
    return (radius*radius)*Pi;
}
class Rectangle : public Shape{
    private:
        float length;
        float width;
    public:
        Rectangle();
        void input();
        void output();
        float acreage();
};
Rectangle::Rectangle(){
    this->length = 1;
}
void Rectangle::input(){
    cout<<"Nhap chieu dai hinh chu nhat: "<<endl;
    cin>>length;
    cout<<"Nhap chieu rong hinh chu nhat: "<< endl;
    cin>>width;
}
void Rectangle::output(){
    float lengths = acreage();
    cout<<"Dien tich hinh chu nhat la: "<<lengths<<endl;
}
float Rectangle::acreage(){
    return length*width;
}
int main(){
    Shape *circle = new Circle;
    Shape *rectangle = new Rectangle;
    circle->input();
    circle->output();
    rectangle->input();
    rectangle->output();
}