#include <iostream>
#include <string.h>
using namespace std;
#define n 6 // #define n 8

struct Graph{
    char v[10];
    char c[10];
    char p[10];
    int s[10];
    int f[10];
    int adj[n][5];
};

void topo(Graph G){
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (G.f[i] < G.f[j]){
                int temp = G.v[i];
                G.v[i] = G.v[j];
                G.v[j] = temp;

                temp = G.f[i];
                G.f[i] = G.f[j];
                G.f[j] = temp;
            }
        }
    }
    cout << G.v[0];
    for (int i = 1; i < n; i++){
        cout << " -> " << G.v[i];
    }
    cout << endl;
}

void disp(Graph G){
    cout << "-----------------------------------------" << endl;
    cout << "| Value\t| Color\t| Parent| Start\t| Finish|" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << "| " << G.v[i] << "\t| " << G.c[i] << "\t| " << G.p[i] << "\t| " << G.s[i] << "\t| " << G.f[i] << "\t| " << endl;
    }
    cout << "-----------------------------------------" << endl;
}

void dfs_visit(Graph &G, int u, int &time){
    G.c[u] = 'G';
    time++;
    G.s[u] = time;
    for (int j = 0; j < 5; j++){
        int v = G.adj[u][j];
        if (G.c[v] == 'W'){
            G.p[v] = u + 97;
            dfs_visit(G, v, time);
        }
    }
    G.c[u] = 'B';
    time++;
    G.f[u] = time;
}

void dfs(Graph &G){
    for (int i = 0; i < 10; i++){
        if (i < n){
            G.p[i] = 'N';
            G.c[i] = 'W';
        }
        else{
            G.p[i] = 'N';
            G.c[i] = 'X';
        }
    }
    int time = 0;
    for (int i = 0; i < n; i++){
        if (G.c[i] == 'W'){
            dfs_visit(G, i, time);
        }
    }
}

int main(){
    Graph G;
    for (int i = 0; i < n; i++){
        G.v[i] = i + 97;
    }
    int arr[][5] = {{1, 3},
                    {4},
                    {4, 5},
                    {1},
                    {3},
                    {}};
    /*
        int arr[][5] = {{1, 3},
                    {2, 5},
                    {4, 6, 7},
                    {5},
                    {1, 5},
                    {0},
                    {4, 7},
                    {0}};
    */

    memcpy(G.adj, arr, sizeof(arr));
    dfs(G);
    cout << "DFS result : " << endl;
    disp(G);
    cout << "Topological Order : " << endl;
    topo(G);
}
