#include<iostream>
using namespace std;
class clk{
    public:
    int hr,min,sec;
    clk(){
        hr=0;min=0;sec=0;
    }
    clk(int h,int m,int s){
        hr=h;min=m;sec=s;
    }
    void disp(){
        cout<<"Time = "<<hr<<":"<<min<<":"<<sec<<endl;
    }
    clk add(clk i,clk j){
    return i + j;
    }
};
int main(){
    clk t1(1,2,3);
    clk t2(2,3,4);
    clk t3;
    t1.disp();
    t2.disp();
    t3.disp();
 // NOT FINISHED   
    return 0;
}