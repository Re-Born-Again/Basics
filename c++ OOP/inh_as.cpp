#include<iostream>
using namespace std;

class A{
    int x;
    protected:
    int y;
    public:
    int z;
};

class B:public A{
    public:
    void func(){
        int a;
        // a=x;
        a=y;
        a=z;
    }
};

class C:private A{
    public:
    void fn(){
        int a;
        //a=x;
        a=y;
        a=z;
        
    }
};

int main(){
    int a;

    B b;
    //a=b.x;
    //a=b.y;
    a=b.z;

    C c;
    //a=c.x;
    //a=c.y;
    //a=c.z;


    return 0;
}