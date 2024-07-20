#include <iostream>
#include <string.h>
#include <set>
using namespace std;
#define n 9

struct edges{
    int val, st, end;
} e[n * n];
edges t;

int w[n][n];
int mincost = 0;
int k;
set<int> sets[n * n];

void creset(){
    for (int i = 0; i < n; i++){
        sets[i].insert(i);
    }
}

void dispset(int i){
    cout << "Set values of " << i << " : ";
    for (set<int>::iterator it = sets[i].begin(); it != sets[i].end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void sortedge(){
    for (int j = 0; j < k; j++){
        for (int i = 1; i < k; i++){
            if (e[i].val < e[i - 1].val){
                t = e[i];
                e[i] = e[i - 1];
                e[i - 1] = t;
            }
        }
    }
}

int checkset(int num){
    for (int i = 0; i < n; i++){
        if (sets[i].find(num) != sets[i].end()){
            return i;
        }
    }
    return -1;
}
// bool checks(int s1,int s2){
//     int a=checkset(s1);
//     if(sets[a].find(s2)!=sets[a].end()){
//         return true;
//     }
//     return false;
// }

void mergeset(int s1, int s2){
    int a = checkset(s1);
    int b = checkset(s2);
    for (set<int>::iterator it = sets[b].begin(); it != sets[b].end(); it++){
        sets[a].insert(*it);
    }
    cout << s1 << "--" << s2 << " : Cost " << w[s1][s2] << endl;
    mincost += w[s1][s2];
    sets[b].clear();
}

void kruskal(){
    for (int i = 0; i < k; i++){
        if (checkset(e[i].st) != checkset(e[i].end)){ 
            // !checks(e[i].st,e[i].end)
            mergeset(e[i].st, e[i].end);
        }
    }
}

int main(){
    //  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8
    int weight[n][n] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},   // 0
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},  // 1
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},   // 2
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},  // 3
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},  // 4
                        {0, 0, 4, 14, 10, 0, 2, 0, 0}, // 5
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},   // 6
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},  // 7
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}};  // 8

    memcpy(w, weight, sizeof(weight));

    k = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (w[i][j] != 0){
                e[k].val = w[i][j];
                e[k].st = i;
                e[k].end = j;
                k++;
            }
        }
    }

    sortedge();
    cout << "Sorted edges : ";
    for (int i = 0; i < k; i++){
        cout << e[i].val << " ";
    }
    cout << endl;

    creset();
    // for(int i=0;i<n;i++)
    //     dispset(i);
    cout << "Kruskal's result : " << endl
         << "Minimum Spanning Tree Edges : " << endl;
    kruskal();
    cout << "Min cost : " << mincost << endl;
    dispset(0);
}