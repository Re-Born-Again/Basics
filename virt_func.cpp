#include<iostream>
using namespace std;
class parent{
    public:
    int x,y;
    parent(): x(1), y(2) {cout<<"Parent class"<<endl;}
};
class child1 : virtual public parent{
    public : 
    child1(){
        x = 2;
    cout<<"Child 1 created"<<endl;}};

class child2 : virtual public parent{
    public : 
    child2(){
        x = 2;
    cout<<"Child 2 created"<<endl;}};

class grandch : public child1,public child2{
    public:
    grandch(){
        x = 2;
        cout<<"Grandchild created"<<endl;
    }
};

int main(){
    parent p;
    child1 c1;
    child2 c2;
    grandch g;
    return 0;
}