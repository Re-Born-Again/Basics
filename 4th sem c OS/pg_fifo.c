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

int main(){
    
    int pn, fn;
    int pg[20], fr[20];
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
            fr[k]=pg[i];
            k=(k+1)%fn;
        }
        disp(fr,fn);
    }
    printf("Total age faults : %d",pgf);
}