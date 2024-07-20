#include<iostream>
using namespace std;

class A{
    int x=10;
    friend class B;
};

class B{
    public:
    B(A obj){
        cout<<"Value of x(private variable in A class) : "<<obj.x<<endl;
    }
};

int main(){
    A a;
    B b(a);
    return 0;
}