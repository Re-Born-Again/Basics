#include <iostream>
using namespace std;
#define mrow 100
#define mcol 100

int n;
int c;

void sortpw(int w[],int p[]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (w[j] > w[j + 1]){
                int t1 = w[j];
                int t2 = p[j];
                w[j] = w[j + 1];
                p[j] = p[j + 1];
                w[j + 1] = t1;
                p[j + 1] = t2;
            }
        }
    }
}

void disparr(int arr[]){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}

void dispmat(int m[mrow][mcol]){
    cout << "Profit Matrix : " << endl;

    cout << "  | ";
    for (int i = 0; i < c + 1; i++){
        cout << i << " ";
    }
    cout << endl;

    cout << "--|--------------------" << endl;

    for (int i = 0; i < n + 1; i++){
        cout << i << " | ";
        for (int j = 0; j < c + 1; j++){
            cout << m[i][j] << " ";
        }
        cout << endl
             << "  |" << endl;
    }
}

void pmat(int m[mrow][mcol],int w[],int p[]){
    for (int i = 0; i < c + 1; i++){
        m[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++){
        m[i][0] = 0;
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < c + 1; j++){
            if (w[i - 1] > j){
                m[i][j] = m[i - 1][j];
            }
            else if (w[i - 1] <= j){
                m[i][j] = max(m[i - 1][j], p[i - 1] + m[i - 1][j - w[i - 1]]);
            }
        }
    }
}

int main()
{
    c = 8;
    n = 4;
    int w[] = {3, 4, 6, 5};
    int p[] = {2, 3, 1, 4};
    int m[mrow][mcol];

    sortpw(w,p);
    
    cout << "Sorted weight and its profit : " << endl;
    cout << "w : ";
    disparr(w);
    cout << "p : ";
    disparr(p);

    pmat(m,w,p);

    dispmat(m);    
    cout << "Result : " << endl;
    cout << "For capacity " << c << " max profit obtained : " << m[n][c] << endl;
}