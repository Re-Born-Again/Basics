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

int max(int req[],int rn){
    int max=-99999;
    for(int i=0;i<rn;i++){
        if(max<req[i]){
            max=req[i];
        }
    }
    return max;
}

int main(){
    int cp,cpp,rn,req[100],i,j;
    int flag[100]={0};
    int dm=0;
    int end;

    printf("Enter current position : ");
    scanf("%d",&cpp);
    cp=cpp;
    printf("Enter request no. : ");
    scanf("%d",&rn);
    printf("Enter request sequence : ");
    for(i=0;i<rn;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter end addr. : ");
    scanf("%d",&end);

    printf("Disk movements : %d",cp);
    for(i=cp;i<=end;i++){
        int idx=present(i,req,rn,flag);
        if(idx!=-1){
            flag[idx]=1;
            dm+=abs(cp-req[idx]);
            cp=req[idx];
            printf(" -> %d",cp);
        }
    }

    int abc=max(req,rn);
    if(abc!=end){
        printf(" -> %d",end);
        dm+=abs(abc-end);
    }
    dm+=end;
    
    printf(" -> 0");    
    cp=0;

    for(i=0;i<cpp;i++){
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