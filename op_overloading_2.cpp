#include<iostream>
using namespace std;

class sum{
    int a;
    public:
    void get(){
        cout<<"enter a integer : "<<endl;
        cin>>a;
    }
    void put(){
        cout<<"a : "<<a<<endl;
    }
    sum operator + (sum c){
        sum t;
        t.a=a+c.a;
        return t;
    }
};

int main(){
    sum s1,s2,s3,s4;
    s1.get();
    s2.get();
    s3=s1+s2;
    cout<<"s3, ";
    s3.put();
    return 0;
}