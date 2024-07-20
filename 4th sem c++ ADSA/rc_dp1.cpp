#include <iostream>
using namespace std;

int rc(int p[], int n, int r[]){
    if (r[n] >= 0){
        return r[n];
    }
    if (n == 0){
        r[n] = 0;
        return r[n];
    }
    int q = -999;
    for (int i = 0; i < n; i++){
        int rev = rc(p, n - i - 1, r);
        if (rev + p[i] > q){
            q = p[i] + rev;
        }
    }
    r[n] = q;
    return r[n - 1];
}

int main(){
    int p[] = {1, 5, 8, 9};
    int n = sizeof(p) / sizeof(p[0]);
    int r[n + 1];
    cout << "Profit per piece : ";
    for (int i = 0; i < n; i++){
        cout << p[i] << " ";
        r[i] = -999;
    }
    r[n] = -999;
    cout << endl;

    rc(p, n, r);
    for (int i = 0; i <= n; i++){
        cout << r[i] << " ";
    }
    cout << endl;
}