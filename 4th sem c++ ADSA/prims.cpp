#include <iostream>
#include <string.h>
using namespace std;
#define n 9

struct Graph{
    int cost[10], adj[10][5];
    char c[10], val[10], p[10];
} G;
int Q[10];

int w[n][n];

void minc(Graph &G){
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        min += G.cost[i];
    }
    cout << "Min cost : " << min << endl;
}

int dequeue(int *Q){
    if (Q[0] == -1){
        return -1;
    }
    else{
        int temp = Q[0];
        for (int i = 0; i < n; i++){
            Q[i] = Q[i + 1];
        }
        return temp;
    }
}

void disp(Graph G){
    cout << "-------------------------------" << endl;
    cout << "| Value\t| Parent| Color | Cost|" << endl;
    cout << "-------------------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << "| " << G.val[i] << "\t| " << G.p[i] << "\t| " << G.c[i] << "\t| " << G.cost[i] << "   |" << endl;
    }
    cout << "-------------------------------" << endl
         << endl;
}

void prims(Graph &G, int s){
    cout << "Minimum spanning tree edges : " << endl;
    G.cost[s] = 0;
    while (1){
        int u = dequeue(Q); // may use queue or just a for loop with for(int u=0;u<n;u++)
        if (u == -1){
            break;
        }
        else{
            for (int i = 0; i < 5; i++){
                int v = G.adj[u][i];
                if (G.c[v] == 'W'){
                    if (w[u][v] < G.cost[v]){
                        G.cost[v] = w[u][v];
                        G.p[v] = u + 97;
                    }
                }
            }
            cout << G.p[u] << " -- " << char(u + 97) << " | Cost : " << G.cost[u] << endl;
            G.c[u] = 'B';
        }
    }
    cout << endl;
}

int main(){
    for (int i = 0; i < 10; i++){
        if (i < n){
            G.val[i] = i + 97;
            G.c[i] = 'W';
            G.p[i] = 'N';
            G.cost[i] = 999;
            Q[i] = i;
        }
        else{
            G.c[i] = 'X';
            Q[i] = -1;
        }
    }
    int start = 0;
    int arr[][5] = {{1, 7},
                    {0, 2, 7},
                    {1, 3, 5, 8},
                    {2, 4, 5},
                    {3, 5},
                    {2, 3, 4, 6},
                    {5, 7, 8},
                    {0, 1, 6, 8},
                    {2, 6, 7}};
    memcpy(G.adj, arr, sizeof(arr));

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

    cout << "Prim's result : " << endl
         << endl;

    prims(G, start);

    cout << "Prim's table : " << endl;

    disp(G);

    minc(G);
}