#include<iostream>
using namespace std;

class A{
    public:
    A(){cout<<"Inside class A"<<endl;}
    A(int x){cout<<"Value of x inside A : "<<x<<endl;}
};

class B:public A{
    public:
    B():A(){cout<<"Inside class B"<<endl;}
    //B():A(20){cout<<"Inside class B"<<endl;}      can also be given
    B(int x):A(x){cout<<"Value of x inside B : "<<x<<endl;}
    //B(int x):A(){cout<<"Value of x inside B : "<<x<<endl;}        can also be given
};

int main(){
    A a;
    A aa(10);
    B b;
    B bb(5);
    return 0;
}