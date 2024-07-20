#include<iostream>
using namespace std;

struct demo{
    int a;
    char b;
};

demo disp(demo z){
    return z;
}

int main(){
    demo d,x;
    d.a=5;
    d.b='a';
    x=disp(d);
    cout<<x.a<<" "<<x.b<<endl;
}