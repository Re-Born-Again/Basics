#include<iostream>
using namespace std;

class demo{
    public:
    int x;
    demo(){
        x=1;
    }
    void show() const{
        cout<<"Value is x : "<<x<<endl;
    }
    void operator ++(){
        x++;
    }
};

int main(){
    const demo d;
    d.show(); // cannot use for non-const functions
    //d.x=2;
    //d.show();
    //++d.x;
    //d.show(); ERRORS!  
    return 0;
}