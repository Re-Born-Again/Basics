#include <iostream>
#include <string.h>
using namespace std;

int a[] = {5, 2, 1, 4, 3};
const int n = sizeof(a) / sizeof(a[0]);
int x[n] = {0};
int tsum = 9;

void disp(){
    for (int i = 0; i < n; i++){
        if (x[i] == 1){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

void ss(int k, int m){
    if (m == 0){
        disp();
        return;
    }
    else if (m < 0 || n == k){
        return;
    }
    else if (m > 0){
        x[k] = 1;
        ss(k + 1, m - a[k]);
        x[k] = 0;
        ss(k + 1, m);
        return;
    }
}

int main(){
    int m = tsum;
    int k = 0;
    cout << "Subsets of array ";
    for (int i = 0; i < n; i++){
        cout << a[i] << ",";
    }
    cout << " that make the sum " << tsum << " are : " << endl;
    ss(k, m);
}