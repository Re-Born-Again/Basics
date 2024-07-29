#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,int> dict;
    dict["a"]=1;
    dict["aa"]=2;
    dict["abcd"]=1234;

    cout<<"dict[\"a\"] : "<<dict["a"]<<endl;
    cout<<"dict[\"aa\"] : "<<dict["aa"]<<endl;
    cout<<"dict[\"abcd\"] : "<<dict["abcd"]<<endl;
    cout<<"dict[\"a\"]+dict[\"aa\"] : "<<dict["a"]+dict["aa"]<<endl;
    dict["a"]++;
    cout<<"dict[\"a\"]++ : "<<dict["a"]<<endl;
    dict["a"]=3;
    cout<<"dict[\"a\"] : "<<dict["a"]<<endl;
    cout<<"dict[\"b\"] : "<<dict["b"]<<endl;

    cout<<"using dict.count()"<<endl;
    cout<<"dict.count(\"a\") : "<<dict.count("a")<<endl;
    cout<<"dict.count(\"b\") : "<<dict.count("b")<<endl;
    cout<<"dict.count(\"z\") : "<<dict.count("z")<<endl;
    cout<<"dict.count(\"z\") : "<<dict.count("z")<<endl;

    int val_to_find=1234;
    string key_present;
    bool found=false;
    for(auto pair:dict){
        if(pair.second==val_to_find){
            found=true;
            key_present=pair.first;
            break;
        }
    }
    if(found){
        cout<<"value set for key : "<<key_present<<endl;
    }
    else{
        cout<<"Not present in dictionary"<<endl;
    }

    map<int,char> dict2;
    dict2[0]='a';
    dict2[1]='b';
    auto it=dict2.find(1); // .find(key)
    cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
}