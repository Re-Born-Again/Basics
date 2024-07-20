#include<fstream>
#include<iostream>
#include<string>
using namespace std;

template<typename t>
class calc{
  t a,b;
  public:
  calc(t aa,t bb){
    a=aa;
    b=bb;
  }
  
  void show(){
    addition( a, b);
    subtract( a, b);
    multiply( a, b);
    division( a, b);
  }
    void addition(t a,t b){
      cout<<a+b<<endl;
    }
    void subtract(t a,t b){
      cout<<a-b<<endl;
    }
    void multiply(t a,t b){
      cout<<a*b<<endl;
    }
    void division(t a,t b){
      cout<<a/b<<endl;
    }
};

int main(){
calc <int> c1(6,3);
c1.show();
}