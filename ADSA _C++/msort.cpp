#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void Merge(int[], int, int, int);
void MergeSort(int a[], int p, int r){

    if (p >= r)
        return;
    else{
        int q = (p + r) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}

void Merge(int a[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int i = 0, j = 0;
    int le[n1 + 1], ri[n2 + 1];
    cout << "n1 value : " << n1 << endl
         << "q value : " << q << endl
         << endl;
    for (int k = p; k <= r; k++){
        if (k <= q){
            le[i] = a[k];
            i++;
        }
        else{
            ri[j] = a[k];
            j++;
        }
    }
    ri[j] = le[i] = INT_MAX;
    i = j = 0;
    for (int k = p; k <= r; k++){
        if (ri[j] >= le[i]){
            a[k] = le[i];
            i++;
        }
        else{
            a[k] = ri[j];
            j++;
        }
    }
}

void Descending(int a[], int n){
    for (int i = 0; i < n / 2; i++){
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

int main(){
    ifstream inf;
    ofstream outf;

    int n;
    cout << "Enter no. of numbers : ";
    cin >> n;

    outf.open("minput.txt");
    srand((long int)clock());
    for (int i = 0; i < n; i++){
        outf << rand() % n << "\t";
    }
    outf.close();

    inf.open("minput.txt");
    int a[n];
    for (int i = 0; i < n; i++){
        inf >> a[i];
    }
    inf.close();

    MergeSort(a, 0, n - 1);

    outf.open("moutput.txt");
    outf << "Random : " << endl;
    for (int i = 0; i < n; i++){
        outf << a[i] << "\t";
    }
    outf.close();

    MergeSort(a, 0, n - 1);

    outf.open("moutput.txt", ios::app);
    outf << endl
         << "Ordered : " << endl;
    for (int i = 0; i < n; i++){
        outf << a[i] << "\t";
    }
    outf.close();

    Descending(a, n);
    MergeSort(a, 0, n - 1);

    outf.open("moutput.txt", ios::app);
    outf << endl
         << "Descending : " << endl;
    for (int i = 0; i < n; i++){
        outf << a[i] << "\t";
    }
    outf.close();
}