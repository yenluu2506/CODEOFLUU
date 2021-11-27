#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void talk(){
            cout <<"Don't talk";
        }
};

class Cat:public Animal{
    public:
        void talk(){
            cout << "Cat talk";
        }
};

class Dog:public Animal{
    public: 
        void talk(){
            cout << "Dog talk";
        }
};

void giveATalk(Animal *p){
    p->talk();
}
// int main(){
//     Cat c;
//     Dog d;

//     giveATalk(&c);
//     giveATalk(&d);
// }

int main(){
    Animal a;
    Cat c;
    Dog d;

    Animal *p;
    p = &a;
    p->talk();

    p = &c;
    p->talk();

    p = &d;
    p->talk();
}