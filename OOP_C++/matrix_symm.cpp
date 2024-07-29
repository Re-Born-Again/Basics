#include<iostream>
using namespace std;

    
int main(){
    int r,c;
    cout<<"enter row and column of matrix : ";
    cin>>r>>c;
    int a[r][c];
    cout<<"enter values of matrix : "<<endl;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<"enter value of a "<<i<<j<<" ";
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    int z=1;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(a[i][j]!=a[j][i])
               z=0;
        }
    }
    if(z==1)
       cout<<"the matrix is symmetric"<<endl;
    else
       cout<<"the matrix is not symmetric"<<endl;

    return 0;
}