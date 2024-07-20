#include<iostream>
using namespace std;

class aaa{
    public:
    int a;
    void get(){
        cout<<"enter a value : ";
        cin>>a;
    }
    void put(){
        cout<<"value of a : "<<a<<endl;
    }
    aaa(char x[]){
        cout<<x<<endl;
    }
};

int main(){
    aaa a("Constructor working !");
    a.get();
    a.put();
    return 0;
}