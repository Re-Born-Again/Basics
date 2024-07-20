#include <iostream>
using namespace std;

int rc(int p[], int n){
    int r[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++){
        int q = -999;
        for (int i = 0; i < j; i++){
            int r1 = r[j - i - 1];
            if (p[i] + r1 > q){
                q = p[i] + r1;
            }
        }
        r[j] = q;
    }
    return r[n];
}

int main(){
    // int p[]={3,5,8,9,10,17,17,20}; // max : 24
    // int p[]={1,5,8,9,10,17,17,20}; // 22
    int p[] = {1, 5, 8, 9}; // max : 10
    int n = sizeof(p) / sizeof(p[0]);
    int max;
    max = rc(p, n);
    cout << "Maximum revenue : " << max;
}