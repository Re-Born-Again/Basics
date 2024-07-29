#include<iostream>
#include<stdio.h>
using namespace std;
#define a 5
#define pf printf

int main(){

    #define a 7
    cout<<a<<endl;
    
    #undef a
    int a=0;
    if(a==0)
        cout<<a<<endl;

    #undef a
    #define a 1
    #if a==1
        cout<<a<<endl;
    #endif

    pf("pf is working\n");
    return 0;
}