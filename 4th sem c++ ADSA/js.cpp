#include <iostream>
using namespace std;

struct jobs{
    int no; // job number
    int p;  // profit
    int d;  // deadline
};
int m;

int maxD(jobs j[], int n){
    int max = j[0].d;
    for (int i = 1; i < n; i++)
    {
        if (max < j[i].d)
            max = j[i].d;
    }
    return max;
}

void DescSortProf(jobs j[], int n){
    for (int k = 0; k < n; k++){
        jobs key = j[k];
        int i = k - 1;
        while (i > -1 && j[i].p < key.p){
            j[i + 1] = j[i];
            i--;
        }
        j[i + 1] = key;
    }
}

int *js(jobs j[], int n){
    m = maxD(j, n);
    cout << "Max deadline : " << m << endl;
    DescSortProf(j, n);
    cout << "Descending profit order : ";
    for (int i = 0; i < n; i++){
        cout << j[i].p << " ";
    }

    int *slot = new int[m];
    for (int i = 0; i < m; i++){
        slot[i] = -1;
    }

    for (int i = 0; i < n; i++){
        for (int k = j[i].d - 1; k >= 0; k--){
            if (slot[k] == -1){
                slot[k] = j[i].no;
                break;
            }
        }
    }
    cout << endl;
    return slot;
}

int main(){
    jobs j[] = {{1, 20, 2}, {2, 15, 2}, {3, 10, 1}, {4, 5, 3}, {5, 1, 3}}; // no,p,d
    // jobs j[]={{1,20,4},{2,10,1},{3,40,1},{4,30,1}}; // ans 3 -1 -1 1
    int n = sizeof(j) / sizeof(j[0]);
    int *result;
    result = js(j, n);
    cout << "Jobs scheduled order : ";
    for (int i = 0; i < m; i++){
        cout << result[i] << " ";
    }
    delete[] result;
}