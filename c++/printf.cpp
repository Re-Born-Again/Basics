#include<iostream>
using namespace std;

// the printf padding is to print minimum given length

int main(){
    float x=12345.6789;
    int y=12;

    printf("%d \n",y);
    printf("%3d \n",y);
    printf("%-3d \n",y); // fills after the number
    printf("%03d \n",y);
    printf("%3.2d \n",y);
    // error for printf("%.3f \n",y);

    printf("%f \n",x);
    printf("%3d \n",y);
    printf("%03d \n",y);
    printf("%3.2f \n",x); // should give both length before and after decimal in float
    printf("%.3f \n",x); // round off automatically
}