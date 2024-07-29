#include <iostream>
using namespace std;

void display(int mat[][6], int n){
    for (int j = n - 1; j >= 0; j--){
        for (int i = 0; i < n; i++){
            if (j < i){
                std::cout << "\t ";
            }
            else{
                std::cout << mat[i][j] << "\t";
            }
        }
        std::cout << endl;
    }
}

void obst(int p[], int q[], int n){
    int c[6][6], w[6][6], r[6][6];

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (i == j){
                w[i][j] = q[i];
            }
            else{
                w[i][j] = w[i][j - 1] + p[j] + q[j];
            }
        }
    }

    for (int l = 0; l < n; l++){
        for (int i = 0; i < n - l; i++){
            // for (int j = n - 1; j >= i; j--)
            int j = i + l;
            if (i == j){
                c[i][j] = 0;
                r[i][j] = 0;
            }
            else{
                int min = 999;
                int min_k = -1;
                for (int k = i + 1; k < j + 1; k++){
                    int m = c[i][k - 1] + c[k][j];
                    if (m < min){
                        min = m;
                        min_k = k;
                    }
                }
                c[i][j] = min + w[i][j];
                r[i][j] = min_k;
            }
        }
    }

    std::cout << "Matrix - W " << endl;
    display(w, n);
    std::cout << "Matrix - C " << endl;
    display(c, n);
    std::cout << "Matrix - R " << endl;
    display(r, n);
}

int main()
{
    int p[] = {0, 5, 2, 6, 3, 5};
    int q[] = {4, 8, 11, 2, 9, 3};
    int n = sizeof(q) / sizeof(q[0]);
    obst(p, q, n);
}