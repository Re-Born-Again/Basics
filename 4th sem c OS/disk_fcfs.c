#include<stdio.h>

#include<stdlib.h>

int main(){
    int req[50],rn,cp,i;
    int dm;
    printf("Enter current position : ");
    scanf("%d",&cp);
    printf("Enter request no. : ");
    scanf("%d",&rn);
    printf("Enter request sequence : ");
    for(i=0;i<rn;i++){
        scanf("%d",&req[i]);
    }

    printf("Sequence order : ");
    dm=abs(cp-req[0]);
    printf("%d -> %d",cp,req[0]);
    for(i=0;i<rn-1;i++){
        dm+=abs(req[i]-req[i+1]);
        printf(" -> %d",req[i+1]);
    }
    printf("\nTotal disk movement : %d\n",dm);
}