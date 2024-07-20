#include<iostream>
using namespace std;

#define a 10
int main(){
    #ifdef a
        #if a==10
            cout<<a<<endl;
        #else
            cout<<"not 10"<<endl;
        #endif
    #ifndef a
        cout<<"Not declared";
    #endif
}