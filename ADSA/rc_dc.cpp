#include <iostream>
using namespace std;

int rc_dc(int p[], int n){
    if (n == 0){
        return 0;
    }
    int q = -999;
    for (int i = 0; i < n; i++){
        int r1 = rc_dc(p, n - i - 1);
        if (p[i] + r1 > q){
            q = p[i] + r1;
        }
    }
    return q;
}

int main(){
    int p[] = {1, 5, 8, 9}; // max : 10
    // int p[]={1,5,8,9,10,17,17,20}; // 22
    // int p[]={3,5,8,9,10,17,17,20}; // max : 24

    int n = sizeof(p) / sizeof(p[0]);
    int max;
    max = rc_dc(p, n);
    cout << "Maximum revenue : " << max;
}