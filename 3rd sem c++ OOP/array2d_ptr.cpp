#include<iostream>
using namespace std;

int main(){

    int arr[3][3];
    for(int i=0;i<3;i++){
        cout<<"Enter value for "<<i+1<<" player : ";
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    }

    int *ptr=&arr[0][0];

    for(int i=0;i<9;i++){
        cout<<*(ptr+i)<<" ";
    }

    int sum[3]={0,0,0};
    for(int i=0;i<3;i++){
        sum[0]+=*(ptr+i);
        sum[1]+=*(ptr+3+i);
        sum[2]+=*(ptr+6+i);
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<sum[i]<<endl;
    }
    int *sptr=&sum[0];

    int max=*sptr;
    int min=*sptr;

    for(int i=0;i<3;i++){
        if(max<*(sptr+i)){
            max=*(sptr+i);
        }
        if(min>*(sptr+i)){
            min=*(sptr+i);
        }
    }

    cout<<"Greatest score,player : "<<max<<" "<<endl<<"Lowest scorer,player : "<<min<<" "<<endl;
   
}
