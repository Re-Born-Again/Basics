#include<iostream>
#include<stdlib.h>
#include<string>
#include<map>
#include<stack>
using namespace std;

int main(){
    string s="({[})]";

    map<char,char> dict;
        dict['(']=')';
        dict['[']=']';
        dict['{']='}';

        stack<char> mystack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                mystack.push(s[i]);
            }
            else{
                if((mystack.empty()==0)&&dict[mystack.top()]==s[i]){
                    mystack.pop();
                }
                else{
                    cout<<"false"<<endl;
                }
            }
        }
        if(mystack.empty()==1){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
}