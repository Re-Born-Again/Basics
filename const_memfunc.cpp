#include<iostream>
using namespace std;
class demo{
    public:
    int x;
    demo(){
        x=0;
    }
    void upd(){
        x++;
    }
    /* void upd() const {  //ERROR! coz no mem data cannot be updated
        x++;
    }*/
};

int main(){
    demo d;
    cout<<d.x<<endl;
    d.upd();
    cout<<d.x<<endl;
    return 0;
}