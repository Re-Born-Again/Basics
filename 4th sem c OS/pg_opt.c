#include <stdio.h>
#include <stdbool.h>

int k;

bool present(int val,int fr[],int fn){
    for(int i=0;i<fn;i++){
        if(fr[i]==val){
            return false;
        }
    }
    return true;
}

void disp(int fr[],int fn,int furank[]){
    for(int i=0;i<fn;i++){
        printf("%d\t",fr[i]);
    }
    for(int i=0;i<fn;i++){
        printf("\t%d",furank[i]);
    }
    printf("\n");
}

int maxarr(int furank[],int fn){
    int max=furank[0];
    int maxidx=0;
    for(int i=1;i<fn;i++){
        if(max<furank[i]){
            max=furank[i];
            maxidx=i;
        }
    }
    return maxidx;
}

int pgrv(int pg[],int pn,int val,int from){
    for(int i=from+1;i<pn;i++){
        if(pg[i]==val){
            return i;
        }
    }
    return 99;
}

void opt(int pg[],int pn,int fr[],int fn,int val,int furank[],int from){
    int idx=maxarr(furank,fn);
    fr[idx]=val;
    k=pgrv(pg,pn,val,from);
    furank[idx]=k;
}

int main(){
    
    int pn, fn;
    int pg[20], fr[20], furank[50], pgrank[50];
    int i;
    bool rep;
    int pgf=0;

    printf("Enter no. pages in queue : ");
    scanf("%d", &pn);
    printf("Enter pgs : ");
    for (i = 0; i < pn; i++)
    {
        scanf("%d", &pg[i]);
    }
    for(i=0;i<pn;i++)
    {
        pgrank[i]=i;
    }

    printf("Enter no. frames : ");
    scanf("%d", &fn);
    for (i = 0; i < fn; i++)
    {
        fr[i] = -1;
        furank[i]=999;
    }

    printf("Page\t\tFrame\t\t\t\tFuture Rank\n");
    for(i=0;i<pn;i++){
        printf("%d\t\t",pg[i]);
        rep=present(pg[i],fr,fn);
        if(rep){
            pgf++;
            opt(pg,pn,fr,fn,pg[i],furank,i);
        }
        else{
            int idx;
            for(int j=0;j<fn;j++){
                if(pg[i]==fr[j]){
                    idx=j;
                }
            }
            k=pgrv(pg,pn,pg[i],i);
            furank[idx]=k;
        }
        disp(fr,fn,furank);
    }
    printf("Total age faults : %d",pgf);
}