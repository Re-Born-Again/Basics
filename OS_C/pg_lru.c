#include <stdio.h>
#include <stdbool.h>

int k=1;

bool present(int val,int fr[],int fn){
    for(int i=0;i<fn;i++){
        if(fr[i]==val){
            return false;
        }
    }
    return true;
}

void disp(int fr[],int fn,int arrank[]){
    for(int i=0;i<fn;i++){
        printf("%d\t",fr[i]);
    }
    for(int i=0;i<fn;i++){
        printf("\t%d",arrank[i]);
    }
    printf("\n");
}

int minarr(int arrank[],int fn){
    int min=arrank[0];
    int minidx=0;
    for(int i=1;i<fn;i++){
        if(min>arrank[i]){
            min=arrank[i];
            minidx=i;
        }
    }
    return minidx;
}

void lru(int fr[],int fn,int val,int arrank[]){
    int idx=minarr(arrank,fn);
    fr[idx]=val;
    arrank[idx]=k;
    k++;
}

int main(){
    
    int pn, fn;
    int pg[20], fr[20], arrank[50];
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

    printf("Enter no. frames : ");
    scanf("%d", &fn);
    for (i = 0; i < fn; i++)
    {
        fr[i] = -1;
        arrank[i]=0;
    }

    printf("Page\t\tFrame\t\t\t\tArrival Rank\n");
    for(i=0;i<pn;i++){
        printf("%d\t\t",pg[i]);
        rep=present(pg[i],fr,fn);
        if(rep){
            pgf++;
            lru(fr,fn,pg[i],arrank);
        }
        else{
            int idx;
            for(int j=0;j<fn;j++){
                if(pg[i]==fr[j]){
                    idx=j;
                }
            }
            arrank[idx]=k;
            k++;
        }
        disp(fr,fn,arrank);
    }
    printf("Total age faults : %d",pgf);
}