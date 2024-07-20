#include<iostream>
using namespace std;

class number{
    const int x;
    public:
    number():x(10){} // can be declared by this way only
    void show(){
        cout<<"Value of x : "<<x<<endl;
    }
};

int main(){
    number n;
    n.show();
    return 0;
}