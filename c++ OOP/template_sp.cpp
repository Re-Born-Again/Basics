#include<iostream>
using namespace std;

template<typename t> void dummy(t a,t b){
    cout<<"value is either int/float"<<endl;
}

template<> void dummy(char* a,char* b){
    cout<<"value is char"<<endl;
}

int main(){
    int c=5,d=10;
    float e=2.3,f=3.5;
    char g[10]="Hello",h[5]="Hi";
    dummy(c,d);
    dummy(e,f);
    dummy(g,h);
    return 0;
}