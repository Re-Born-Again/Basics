#include<stdio.h>
#include<stdlib.h>

int present(int val,int req[],int rn,int flag[]){
    for(int i=0;i<rn;i++){
        if(val==req[i] && flag[i]==0){
            return i;
        }
    }
    return -1;
}

int min(int req[],int rn){
    int min=99999;
    for(int i=0;i<rn;i++){
        if(min>req[i]){
            min=req[i];
        }
    }
    return min;
}

int main(){
    int cp,rn,req[100],i,j;
    int flag[100]={0};
    int dm=0;
    int end;

    printf("Enter current position : ");
    scanf("%d",&cp);
    printf("Enter request no. : ");
    scanf("%d",&rn);
    printf("Enter request sequence : ");
    for(i=0;i<rn;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter end addr. : ");
    scanf("%d",&end);

    printf("Disk movements : %d",cp);
    for(i=cp;i>=0;i--){
        int idx=present(i,req,rn,flag);
        if(idx!=-1){
            flag[idx]=1;
            dm+=abs(cp-req[idx]);
            cp=req[idx];
            printf(" -> %d",cp);
        }
    }

    int abc=min(req,rn);
    if(abc!=0){
        cp=0;
        printf(" -> 0");
        dm+=abc;
    }

    for(i=0;i<=end;i++){
        int idx=present(i,req,rn,flag);
        if(idx!=-1){
            flag[idx]=1;
            dm+=abs(cp-req[idx]);
            cp=req[idx];
            printf(" -> %d",cp);
        }
    }
    printf("\nTotal disk movement : %d\n",dm);
}