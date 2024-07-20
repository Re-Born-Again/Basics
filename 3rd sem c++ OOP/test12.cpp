#include<iostream>
using namespace std;
class Distance{
    public:
    float feet[10],inch[10];
    Distance(){
    cout<<"Enter feet,inch : "<<endl;
    for(int i=0;i<10;i++){
    cin>>feet[i]>>inch[i];}
            }
    void avgDist(){
    float af = 0,ai = 0;
    for(int i=0;i<10;i++){
        af+=feet[i];
        ai+=inch[i];
    }
    af/=10;
    ai/=10;
    if(ai>=12){
        af++;
        ai-=12;
        }
     cout<<"Feet,Inch : "<<af<<" "<<ai<<endl;
    }
};
int main(){
    Distance d;
    d.avgDist();
    return 0;
}