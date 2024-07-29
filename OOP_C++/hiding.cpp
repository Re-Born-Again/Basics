#include<iostream>
using namespace std;

class base{
    public:
    void show(){cout<<"Inside base class"<<endl;}
};
class derived:public base{
    public:
    void show(){cout<<"Inside derived class"<<endl;}
};

int main(){
    base b;
    derived d;
    
    b.show();
    d.show();

    base *bptr=&d;
    bptr->show();

    return 0;
}