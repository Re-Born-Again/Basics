#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    set<int> s1;
    for(int i=0;i<=5;i++){
        s1.insert(i*10);
    }
    s1.insert(10);
    s1.insert(20);
    s1.insert(30); // does not insert 10, 20, 30 as set does not allow duplicate values
    for(auto it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    int val_to_find = 30;
    if(s1.find(val_to_find)==s1.end()){
        cout<<"Value not found"<<endl;
    }
    else{
        cout<<"Value found"<<endl;
    }
    /*auto val = s1.find(val_to_find);
    cout<<*val;
    this prints the val_to_find value
    */

    // converting vector to set
    // takes only unique values
    vector<int> v = {1,2,3,2,1};
    set<int> s(v.begin(),v.end());
    cout<<"Converted set values : ";
    for(auto val:s){
     cout<<val<<" ";
    }
    cout<<endl;
}