#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define pn 6
#define rn 4

int main(){
    bool safe,flag[pn]={0},sel;
    int i,j,k,l;
    int max[pn][rn]={{9,5,5,5},
                     {2,2,3,3},
                     {7,5,4,4},
                     {3,3,3,2},
                     {5,2,2,1},
                     {4,4,4,4}},
        alloc[pn][rn]={{2,0,2,1},
                       {0,1,1,1},
                       {4,1,0,2},
                       {1,0,0,1},
                       {1,1,0,0},
                       {1,0,1,1}},
        avail[rn]={6,3,5,4},
        need[pn][rn],
        res[pn];

    for(i=0;i<pn;i++){
        for(j=0;j<rn;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("Need matrix : \n");
    for(i=0;i<pn;i++){
        for(j=0;j<rn;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    k=0;
    for(l=0;l<pn;l++)
    for(i=0;i<pn;i++){
        sel=1;
        for(j=0;j<rn;j++){
            if(need[i][j]>avail[j]){
                sel=0;
                printf("Process rejected : %d\n",i);
            }
        }
        if(flag[i]==0 && sel==1){
            printf("Process accepted : %d\n",i);
            res[k]=i;
            k++;
            for(j=0;j<rn;j++){
                avail[j]+=need[i][j];
            }
            flag[i]=1;
        }
    }

    safe=1;
    for(i=0;i<pn;i++){
        if(flag[i]==0){
            safe=0;
            printf("%d not assigned\n",i);
            break;
        }
    }

    if(safe==0){
        printf("SYSTEM NOT SAFE !!!\n");
    }
    else if(safe==1){
        printf("%d ",res[0]);
        for(i=1;i<pn;i++){
            printf("-> %d ",res[i]);
        }
        printf("\n");
    }
}