#include <iostream>
using namespace std;

struct item{
    int no;   // no. obj
    float p;  // profit
    int w;    // weight
    float pw; // profit per weight
};

int m;       // no. selected obj
item so[20]; // selected obj

void DesSortPW(item obj[], int n){
    for (int j = 1; j < n; j++){
        item key = obj[j];
        int i = j - 1;
        while (i > -1 && obj[i].pw < key.pw){
            obj[i + 1] = obj[i];
            i--;
        }
        obj[i + 1] = key;
    }
}

int fks(item obj[], int c, int n){
    for (int i = 0; i < n; i++){
        obj[i].pw = obj[i].p / obj[i].w;
    }
    DesSortPW(obj, n);
    cout << "Profit descending order : ";
    for (int i = 0; i < n; i++){
        cout << obj[i].p << " ";
    }
    cout << endl;
    m = 0;

    for (int i = 0; i < n; i++){
        if (c == 0){
            cout << "Chosen profit descending order : ";
            for (int i = 0; i < n; i++){
                cout << so[i].p << " ";
            }
            cout << endl;
            return m;
        }
        else if (obj[i].w <= c){
            c -= obj[i].w;
            so[m] = obj[i];
            m++;
        }
        else{
            item o = obj[i];
            o.w = c;
            o.p = (o.p * o.w) / obj[i].w;
            c = 0;
            so[m] = o;
            m++;
        }
    }
    return m;
}

int main(){
    int c = 15;
    item obj[7] = {{1, 10, 2},
                   {2, 5, 3}, 
                   {3, 15, 5}, 
                   {4, 7, 7}, 
                   {5, 6, 1}, 
                   {6, 18, 4}, 
                   {7, 3, 1}}; // no,p,w

    /*obj[0].p=10;
    obj[1].p=5;
    obj[2].p=15;
    obj[3].p=7;
    obj[4].p=6;
    obj[5].p=18;
    obj[6].p=3;

    obj[0].w=2;
    obj[1].w=3;
    obj[2].w=5;
    obj[3].w=7;
    obj[4].w=1;
    obj[5].w=4;
    obj[6].w=1;

    obj[0].no=1;
    obj[1].no=2;
    obj[2].no=3;
    obj[3].no=4;
    obj[4].no=5;
    obj[5].no=6;
    obj[6].no=7; */

    int n = sizeof(obj) / sizeof(obj[0]);
    int m;
    m = fks(obj, c, n);

    float maxp = 0;
    for (int i = 0; i < m; i++){
        maxp += so[i].p;
    }

    cout << "No. objects selected : " << m << endl;
    cout << "Objects selected are : ";

    for (int i = 0; i < m; i++){
        cout << so[i].no << " ";
    }
    
    cout << endl;
    cout << "Total max profit : " << maxp << endl;
}