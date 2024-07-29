#include<iostream>
#include<iomanip>
using namespace std;

class emp{
    int id;
    char name[20];
    public:
    emp(){
        cout<<"enter emp no., name : "<<endl;
        cin>>id>>name;
    }
    void putdata(){
        cout<<setw(10)<<id<<name<<"\n"<<setiosflags(ios::left)<<setw(20)<<setiosflags(ios::left);
    }
};

int main(){
    emp e[3];
    for(int i=0;i<3;i++)
      e[i].putdata();
    return 0;
}