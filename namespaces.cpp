#include<iostream>
using namespace std;
namespace n1{
    int x=1;
    void func(){
        cout<<"inside n1";
    }
}
namespace n2{
    int x=2;
    void func(){
        cout<<"inside n2";
    }
}
int main(){
    cout<<n1::x<<endl;
    n1::func();
    cout<<endl;
    cout<<n2::x<<endl;
    n2::func();
    cout<<endl;
    return 0;
}