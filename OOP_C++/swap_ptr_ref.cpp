#include<iostream>
using namespace std;

void swap(int*a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swap(int&a,int&b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main(){
    int x=5,y=10;
    cout<<"x : "<<x<<" "<<"y: "<<y<<endl;
    swap(&x,&y);
    cout<<"after ptr swap : "<<endl;
    cout<<"x : "<<x<<" "<<"y: "<<y<<endl;
    swap(x,y);
    cout<<"after ref swap : "<<endl;
    cout<<"x : "<<x<<" "<<"y: "<<y<<endl;
    return 0;

}