// similar as over-loading but done in derived classes
#include<iostream>
using namespace std;

class A{
    public:
    void print(){
        cout<<"Inside A"<<endl;
    }
};

class B{ 
    public:
    void print(){
        cout<<"Inside B"<<endl;
    }
};

class C:public A{ // single level
    public:
    void print(){
        cout<<"Inside C"<<endl;
    }
};

class D:public C{ // multi level
    public:
    void print(){
        cout<<"Inside D"<<endl;
    }
};

class E:public A,public B{ // multiple level
    public:
    void print(){
        cout<<"Inside E"<<endl;
    }
};

int main(){
    A a;
    B b;
    C c;
    D d;
    E e;
    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
    return 0;
}