#include<iostream>
using namespace std;

class demo{
    int x;
    public:
    demo(int x){
        this->x=x+1;
    }
    void show(){
        cout<<"Value of x,x : "<<this->x<<","<<x<<endl; // both give same results
    }
};
int main(){
    demo d(5);
    d.show();
    return 0;
}