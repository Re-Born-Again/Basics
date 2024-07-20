#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int path[100];

int tsp(int **cost, int n, int s){

    int vertex[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++){
        if (i != s)
        {
            vertex[j] = i;
            j++;
        }
    }
    cout << "Elements in vertex matrix : ";
    for (int i = 0; i < n - 1; i++){
        cout << vertex[i] << " ";
    }
    cout << endl;

    int minpath = INT_MAX;

    while (next_permutation(vertex, vertex + n - 1)){
        int k = s;
        int cpw = 0;
        for (int i = 0; i < n - 1; i++){
            cpw += cost[k][vertex[i]];
            k = vertex[i];
        }
        cpw += cost[k][s];
        if (minpath > cpw){
            minpath = cpw;
            for (int i = 0; i < n - 1; i++)
            {
                path[i] = vertex[i];
            }
        }
        minpath = min(minpath, cpw);
    }
    return minpath;
}

int main(){
    int n = 5;
    /*
    instead of int a[n]; should do,
    int *a;
    a=new int[n]; then,
    delete a;

    for 2d arrays,
    int **a;
    a=new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int[n];
    }then,
    for(int i=0;i<n;i++){
        delete[] a[i];
    }
    delete[] a;
    */
    int **cost;
    cost = new int *[n];

    for (int i = 0; i < n; i++){
        cost[i] = new int[n];
    }

    int temp[5][5] = {{999, 20, 30, 10, 11},
                      {15, 999, 16, 4, 2},
                      {3, 5, 999, 2, 4},
                      {19, 6, 18, 999, 3},
                      {16, 4, 7, 16, 999}};

    // int n=4;int temp[4][4]={{999,10,15,20},{10,999,35,25},{15,35,999,30},{20,25,30,999}}; just an another example should also change n=4, ans : 80

    // int n=sizeof(cost[0])/sizeof(cost[0][0]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cost[i][j] = temp[i][j];
        }
    int s;
    cout << "Indices start from 0 to " << n - 1 << endl;
    cout << "Enter starting vertex : ";
    cin >> s;
    int ans;
    ans = tsp(cost, n, s);
    for (int i = 0; i < n; i++){
        delete[] cost[i];
    }
    delete[] cost;
    cout << "Shortest path : " << ans << endl;
    
    cout << "Path : " << s << "-";
    for (int i = 0; i < n - 1; i++)
    {
        cout << path[i] << "-";
    }
    cout << s << endl;
}