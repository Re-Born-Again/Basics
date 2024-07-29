#include<stdio.h>

#pragma warn - rvl
#pragma warn - par
#pragma warn - rch

int show(int x){
    printf("hi");
}
int main(){
    show(10);
    return 0;
}