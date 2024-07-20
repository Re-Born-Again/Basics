#include<iostream>
#include<cstring>
using namespace std;

class part{
public:
    char name[20];
    int number,cost;
    void setpart(){
        cout<<"Enter Part name, Part number, cost : "<<endl;
        cin>>name>>number>>cost;
    }
    void showpart(){
        cout<<"Part name : "<<name<<endl<<"Part number : "<<number<<endl<<"Cost : "<<cost<<endl;
    }
    void checkname(char n[20]){
        if(strcmp(n,name)==0)
            showpart();
        else
            cout<<"not found";
    }
    
    
};


int main(){
    char name[20];
    part p ;
    p.setpart();
    p.showpart();

    cout<<"Enter name : ";
    cin>>name;
    p.checkname(name);


    return 0;
}