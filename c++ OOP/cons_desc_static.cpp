#include<iostream>
using namespace std;

class objc{
    public:
    static int ct;

    objc(){
        ct++;
        cout<<"object "<<ct<<" created "<<endl;
    }
    ~objc(){
        cout<<"object "<<ct<<" destroyed "<<endl;
        ct--;

    }
    static int getcount(){
        return ct;
    }
};

int objc::ct=0;

int main(){
    {objc o1;
    objc o2;} //creating scope for the objects
    //they get desroyed if the scope finishes
    objc o3; //this gets destroyed only after main func finishes
    cout<<"number of objects : "<<objc::getcount()<<endl;
    cout<<"number of objects : "<<o3.ct<<endl; // does not work for o1,o2 as they are destroyed but o3 gets destroyed at end
    return 0;
}