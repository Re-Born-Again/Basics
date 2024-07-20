#include <iostream>
#include <vector>
#include <algorithm> // for std::remove
#include <cstdlib>
#include <map>
#include <string>
#include <cmath>
#include <unordered_map>
#include <sstream>

using namespace std;

int main(){
    string s="aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha";
    int x=1926;
    int y=4320;

    vector<char> vec;
    int score=0;
    int t;
    int a=0;
    int b=0;
    char ch;
    char str1='a';
    char str2='b';


    if(x<y){
        t=x;
        x=y;
        y=t;
        str1='b';
        str2='a';
    }

    for(int i=0;i<s.size();i++){
        ch=s[i];
        if(ch==str1){
            a++;
            vec.push_back(ch);
        }
        else if(ch==str2){
            if(a>0){
                a--;
                score+=x;
                vec.pop_back();
            }
            else{
                vec.push_back(ch);
            }
        }
        else{
            vec.push_back(ch);
            a=0;
        }
    }
    a=0;
    while(!vec.empty()){
        ch=vec.back();
        if(ch==str1){
            a++;
        }
        else if(ch==str2){
            if(a>0){
                a--;
                score+=y;
            }
        }
        else{
            a=0;
        }
        vec.pop_back();
    }

    cout<<score<<endl;
}