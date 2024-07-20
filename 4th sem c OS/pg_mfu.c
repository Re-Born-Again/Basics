#include <stdio.h>
#include <stdbool.h>

bool present(int val,int fr[],int fn){
    for(int i=0;i<fn;i++){
        if(fr[i]==val){
            return false;
        }
    }
    return true;
}

void disp(int fr[],int fn){
    for(int i=0;i<fn;i++){
        printf("%d\t",fr[i]);
    }
    printf("\n");
}

int freq(int pg[],int pn,int val,int upto,int fr[]){
    int f=0;
    if(val==-1){
        return 999;
    }
    for(int i=0;i<=upto;i++){
        if(pg[i]==val){
            f++;
        }
    }
    return f;
}

int maxfreq(int pg[],int pn,int val,int upto,int fr[],int fn){
    int max=freq(pg,pn,fr[0],upto,fr);
    int maxid=0;
    for(int i=0;i<fn;i++){
        int f=freq(pg,pn,fr[i],upto,fr);
        if(max<f){
            max=f;
            maxid=i;
        }
    }
    return maxid;
}

void mfu(int pg[],int pn,int val,int fr[],int fn,int freqar[],int upto){
    int idx=maxfreq(pg,pn,val,upto,fr,fn);
    fr[idx]=val;
    int f=freq(pg,pn,val,upto,fr);
    freqar[idx]=f;
}

int main(){
    
    int pn, fn;
    int pg[20], fr[20], freqar[20];
    int i,k=0;
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
    }

    printf("Page\t\tFrame\n");
    for(i=0;i<pn;i++){
        printf("%d\t\t",pg[i]);
        rep=present(pg[i],fr,fn);
        if(rep){
            pgf++;
            mfu(pg,pn,pg[i],fr,fn,freqar,i);
        }
        
        disp(fr,fn);
    }
    printf("Total age faults : %d",pgf);
}