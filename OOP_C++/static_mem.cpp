#include<iostream>
using namespace std;

class gamma{
    public:
    static int total;
    int ID;
    gamma(){
        total++;
        ID=total;
    }
    static int count(){
        return total;
    }
    int id(){
        return ID;
    }
};
int gamma::total=0;

int main(){
    gamma g1;
    cout<<"g1 count : "<<g1.count()<<endl;
    cout<<"g1 id : "<<g1.id()<<endl;
    gamma g2,g3;
    cout<<"g2 count : "<<g2.count()<<endl;
    cout<<"g1 id : "<<g2.id()<<endl;
    cout<<"g3 count : "<<g3.count()<<endl;
    cout<<"g1 id : "<<g3.id()<<endl;
    return 0;
}