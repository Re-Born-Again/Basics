#include<stdio.h>
#include<stdlib.h>

int main(){
    int cp,rn,req[100],i,j;
    int flag[100]={0};
    int dm=0;

    printf("Enter current position : ");
    scanf("%d",&cp);
    printf("Enter request no. : ");
    scanf("%d",&rn);
    printf("Enter request sequence : ");
    for(i=0;i<rn;i++){
        scanf("%d",&req[i]);
    }

    printf("Disk movements : %d",cp);
    for(i=0;i<rn;i++){
        int min=99999,k;
        for(j=0;j<rn;j++){
            int diff=abs(cp-req[j]);
            if(flag[j]==0 && diff<min){
                min=diff;
                k=j;
            }
        }
        flag[k]=1;
        dm+=min;
        cp=req[k];
        printf(" -> %d",cp);
    }
    printf("\nTotal disk movement : %d\n",dm);
}