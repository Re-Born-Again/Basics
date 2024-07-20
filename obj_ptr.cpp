#include<iostream>
using namespace std;

class dist{
    int x;
    public:
    dist(){
        cout<<"object created "<<endl;}
    void show(){
        cout<<"HI"<<endl;
    }
};

int main(){
    dist d;
    dist *dptr; // dist *dptr=&d; this is not created as an object, so constructor run only 1 time in this prgm
    dptr=new dist; // now constructor will run
    // also can be given as
    //dist *dptr=new dist;
    d.show();
    dptr->show();
    return 0;
}