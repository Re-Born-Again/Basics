
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class rupee;
class dollar{
    int d;
    public:
    void get(){
        cout<<"Enter dollar : ";
        cin>>d;
    }
    friend int convert(dollar);
};

class rupee{
    int r;
    public:
    rupee(){}
    rupee(dollar dd){
        r=convert(dd);
    }
    void put(){
        cout<<r<<endl;
    }
};

int convert(dollar dd){
    return dd.d*100;
}

int main(){
    dollar dd;
    dd.get();
    rupee rr(dd);
    rr.put();
}