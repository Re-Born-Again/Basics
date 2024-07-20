#include<stdio.h>

int main(){
    int n,temp;
    int ct[10],bt[10],p[10],pr[10];
    // assuming all process arrive at 0

    printf("Enter no. of process : ");
    scanf("%d",&n);
    printf("Enter %d process numbers : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    
    printf("Enter %d burst time : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Enter %d priorities : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&pr[i]);
    }

    // sorting p,bt by pr
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i-1);j++){
            if(pr[j]>pr[j+1]){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                temp=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=temp;

            }
        }
    }

    ct[0]=bt[0];

    for(int i=1;i<n;i++){
        temp=0;
        if(ct[i-1]<0){
            temp=-ct[i-1];
        }
        ct[i]=ct[i-1]+bt[i]+temp;
    }
    printf("Process\tpri\tBT\tCT\tTT\n");

    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],pr[i],bt[i],ct[i],ct[i]);
    }
}