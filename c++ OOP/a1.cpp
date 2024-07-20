
#include<iostream>
#include<cstring>
using namespace std;

class book{
    public:
    int id,price;
    char name[10];
    book(){
        cout<<"-";
    }
   
    void getdata(){
        cout<<"Enter book name,ID,price : "<<endl;
        cin>>name>>id>>price;
    }
    void putdata(){
        cout<<"Book ID : "<<id<<", Book name : "<<name<<", Price : "<<price<<endl<<endl;
    }
    int searchbook(int bid){
        if(bid==id){
          putdata();
          return 0;
        }
    }

};

int main(){
    
    book b[100];
    cout<<endl;

    int n,bid,y=1;
    cout<<"Enter number of books : ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Book "<<i+1<<endl;
        b[i].getdata();
    }
  
    cout<<endl<<"Enter book id to get data : ";
    cin>>bid;
    for(int i=0;i<n;i++){
            y=b[i].searchbook(bid);
    }
    if(y!=0)
    cout<<"Book not found"<<endl;
    
    return 0;
}