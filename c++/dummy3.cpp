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



int main(){
    string s="dvdf";

    vector<int> vec(256,0);
    char key;
    int val;
        int ans=0;
        int l=0;
        int n=s.size();
        char ch;

        int i=0;
        while(i<n){
            ch=s[i];
            cout<<ch<<" ";
            if(vec[ch]>0){ // if exist
            cout<<"exist \t";
                l=vec[ch]+1;
                fill(vec.begin(),vec.end(),0);
                
            }
            else{ // if not exist
            cout<<"not exist\t";
                vec[ch]=i+1;
                if(i-l+1>ans){
                    ans=i-l+1;
                }
            }
            cout<<"i : "<<i<<" l : "<<l<<endl;
            i++;
        }
        
    cout<<ans<<endl;
}