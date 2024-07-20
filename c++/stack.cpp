#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> mystack;
    mystack.push(10);
    mystack.push(20);
    cout<<".size() : "<<mystack.size()<<endl;
    cout<<".top() : "<<mystack.top()<<endl;
    mystack.pop();
    cout<<".top() : "<<mystack.top()<<endl;
    cout<<".empty() : "<<mystack.empty()<<endl;
    mystack.pop();
    cout<<".empty() : "<<mystack.empty()<<endl;
    // error => cout<<".top() : "<<mystack.top()<<endl;
}