//function overloading

#include<iostream>
using namespace std;

//area of square
int area(int s){
    return s*s;
}

//area of rectangle
int area(int l,int b){
    return l*b;
}

//area of circle
float area(float r){
    return r*3.14;
}

//area of triangle
float area(float h,float p){
    return 0.5*h*p;
}

int main(){
    int s,l,b;
    float r,h,p;
    cout<<"enter square side : ";
    cin>>s;
    cout<<area(s)<<endl;
    cout<<"enter rectangle length and bredth : ";
    cin>>l>>b;
    cout<<area(l,b)<<endl;
    cout<<"enter circle radius : ";
    cin>>r;
    cout<<area(r)<<endl;
    cout<<"enter triangle height and bredth : ";
    cin>>h>>p;
    cout<<area( h, p)<<endl;
    return 0;
}