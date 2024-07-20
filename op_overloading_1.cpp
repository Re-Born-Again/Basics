#include<iostream>
using namespace std;
// operator overloading unary
class timer{
    int hrs,mins;
    public:
    void get(){
        cout<<"Enter hours and minutes : "<<endl;
        cin>>hrs>>mins;
    }
    void operator ++(){ // for ++c
        mins++;
        if(mins>60){
            hrs++;
            mins-=60;
        }
    }
    void operator ++(int){ // for c++
        mins++;
        if(mins>60){
            hrs++;
            mins-=60;
        }
    }
    void put(){
        cout<<"hrs : "<<hrs<<" : "<<mins<<endl;
    }
};

int main(){
    timer t;
    t.get();
    t.put();
    ++t;
    t.put();
    t++;
    t.put();
    return 0;
}