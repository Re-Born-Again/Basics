#include <iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

void func1 () {
    string str="aa bb cc dd";
    string temp;
    istringstream iss(str);
    getline(iss,temp,' '); // cant use cin coz it uses terminal but iss is fron the string
    cout<<temp<<endl;
    getline(iss,temp,' ');
    cout<<temp<<endl;
    getline(iss,temp,' ');
    cout<<temp<<endl;
    getline(iss,temp,' ');
    cout<<temp<<endl;
    getline(iss,temp,' ');
    cout<<temp<<endl;
}

void func2 () {
    string s1="()[]{}";
    string str1;
    for(int i=0;i<s1.length();i++){
        str1+=s1[i];
        cout<<"str1 value : "<<str1<<endl;
    }
    cout<<"str1 value : ";
    for(int i=0;i<s1.length();i++){
        cout<<str1[i]<<" ";
    }
    cout<<endl;
    cout<<"str1.size() : "<<str1.size()<<endl;
    cout<<"str1.length() : "<<str1.length();

    cout<<endl<<endl;

    // another way to initialize

    string s2="()[]{}";
    string str2(s2.length(),' ');
    for(int i=0;i<s2.length();i++){
        str2[i]=s2[i];
        cout<<"str2 value : "<<str2<<endl;
    }
}

void func3 () {
    string str = "ab:cd";
    string sub1;
    sub1=str.substr(0,str.size()-2); // position, length (default : till end)
    cout<<"sub1 : "<<sub1<<endl;

    string sub2;
    int pos = str.find(":c"); // str.find("val") returns index of val in str
    // .find() returns -1 for not found
    sub2=str.substr(pos+1);
    cout<<"sub2 : "<<sub2<<endl;
}

void func4() {
    string str;
    str+=1;
    cout<<str;
    //  string str = "abc"+'d'; adding char to string literal is invalid
}

void func5(){
    // erasing substring/string
    string str="abcdefgh";
    str.erase();
    cout<<str<<endl;

    string str2="abcdefgh";
    str2.erase(4); // from index to end of string
    cout<<str2<<endl;

    string str3="abcdefgh";
    str3.erase(4,2); // from index, length
    cout<<str3<<endl;
}

int main () {
    func3();
}