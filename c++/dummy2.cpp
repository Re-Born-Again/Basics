#include <iostream>
#include <vector>
#include <algorithm> // for std::remove
#include <cstdlib>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>
#include <sstream>
#include <stack>

using namespace std;

int n;

string chk(string s){
    n=s.size();
    string ans;
    int a,b;
    string temp;
    if(n%2==0){
        b=n/2;
        a=b-1;
        while(s[a]==s[b] && a>-1&&b<n){
            temp=ans;
            ans=s[a];
            ans+=temp;
            ans+=s[b];
            a--;
            b++;
        }
    }
    else{
        a=(n/2)-1;
        b=a+2;
        ans+=s[n/2];
        while(s[a]==s[b] && a>-1&&b<n){
            temp=ans;
            ans=s[a];
            ans+=temp;
            ans+=s[b];
            a--;
            b++;
        }
    }
    return ans;
}

string pal(string s){
    cout<<"pal received : "<<s<<endl;
    if(s==""){
        return "";
    }
    if(s.size()==1){
        return s;
    }
    int mid=(s.size()/2);
    string s1;
    if(s.size()%2==0)
    s1=pal(s.substr(0,mid));
    else
    s1=pal(s.substr(0,mid+1));
    cout<<"\""<<s.substr(0,mid)<<"\" is passed, \""<<s1<<"\" received s1"<<endl;
    string s2= pal(s.substr(mid+1));
    cout<<"\""<<s.substr(mid+1)<<"\" is passed, \""<<s2<<"\" received s2"<<endl;
    string s3= chk(s);
    cout<<"\""<<s<<"\" is passed, \""<<s3<<"\" received s3"<<endl;

    if(s1.size()>=s2.size() && s1.size()>=s3.size()){
        return s1;
    }
    if(s2.size()>=s1.size() && s2.size()>=s3.size()){
        return s2;
    }
    if(s3.size()>=s1.size() && s3.size()>=s2.size()){
        return s3;
    }
    return "";
}

int main(){
    string s="ccc";
    string ans;
    ans = pal(s);
    cout<<"Longest sub palindrome : "<<ans<<endl;
}
