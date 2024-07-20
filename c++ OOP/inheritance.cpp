#include<iostream>
using namespace std;
class a{
    public:
    a(){
        cout<<"a created "<<endl;
    }
};
class b{
    public:
    b(){
        cout<<"b created "<<endl;
    }
};

class c:public a{ // Single Level
    public:
    c(){
    cout<<"c created "<<endl;}
};

class d:public c{ // Multi Level
    public:
    d(){
        cout<<"d created "<<endl;
    }
};

class e:public a,public b{ // Multiple level
    public:
    e(){
        cout<<"e created "<<endl;
    }
};

int main(){
    cout<<"Declaring class a"<<endl;
    a aa;
    cout<<"Declaring class b"<<endl;
    b bb;
    cout<<"Declaring class c (single level)"<<endl;
    c cc;
    cout<<"Declaring class d (multi level)"<<endl;
    d dd;
    cout<<"Declaring class e (multiple level)"<<endl;
    e ee;
    return 0;
}