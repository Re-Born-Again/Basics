#include <iostream>
using namespace std;

int main(){
    int a=10;
    float b=1;

    string aa,bb,cc,dd;
    aa=typeid(a).name();
    bb=typeid(b).name();
    cc=typeid(2).name();
    dd=typeid(2.1).name();

    cout<<"a type : "<<aa<<endl;
    cout<<"b type : "<<bb<<endl;
    cout<<"cc type : "<<cc<<endl;
    cout<<"dd type : "<<dd<<endl;
}