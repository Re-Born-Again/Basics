// user defined to primitive data type

#include<iostream>
using namespace std;
class Time{
    int hrs,mins;
    public:
    Time(int a,int b):hrs(a),mins(b){}
    operator int(){
        cout<<"Conversion of class type to primitive "<<endl;
        return (hrs*60+mins);
    }
};
int main(){
    int dur;
    Time t(2,20);
    dur=t;
    cout<<"tot mins : "<<dur<<endl;
    cout<<"2nd method op over loading : "<<endl;
    dur=t.operator int();
    cout<<"tot mins are : "<<dur<<endl;
    return 0;
}