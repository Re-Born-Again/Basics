// primitive to user defined

#include<iostream>
using namespace std;

class Time{
    int hrs,mins;
    public:
    Time(){hrs=mins=0;}
    Time(int t){
        hrs=t/60;
        mins=t%60;
    }
    void disp(){
        cout<<"Time = "<<hrs<<"hrs & "<<mins<<"mins"<<endl;
    }
};
int main(){
    Time t;
    int dur=95;
    t=dur;
    t.disp();
    return 0;
}