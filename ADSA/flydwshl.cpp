#include <iostream>
#include <cstring>
using namespace std;

void disp(int mat[5][5], int n, string type, int t){
    cout << "Matrix " << type << t << " : " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int d[5][5] = {{0, 3, 8, 999, -4},
                   {999, 0, 999, 1, 7},
                   {999, 4, 0, 999, 999},
                   {2, 999, -5, 0, 999},
                   {999, 999, 999, 6, 0}};
    int p[5][5];
    int n = 5, i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (d[i][j] == 0 || d[i][j] == 999){
                p[i][j] = 0;
            }
            else{
                p[i][j] = i + 1;
            }
        }
    }

    disp(d, n, "d", 0);
    disp(p, n, "p", 0);

    for (int k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
                else{
                    d[i][j] = d[i][j];
                    p[i][j] = p[i][j];
                }
            }
        }
        disp(d, n, "d", k + 1);
        disp(p, n, "p", k + 1);
    }
}