#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int c;

void InsertionSort(int arr[], int n){
    c = 0;
    int j, key, i;
    for (j = 1; j < n; j++){
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key){
            c++;
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}
void Descending(int a[], int n){
    int temp;
    for (int i = 0; i < n / 2; i++){
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - i - 1] = temp;
    }
}

int main(){
    int n;
    cout << "Enter no. of numbers : ";
    cin >> n;
    int a[n];
    ofstream outf;
    ifstream inf;

    outf.open("iinput.txt");
    srand((long int)clock());
    for (int i = 0; i < n; i++){
        outf << rand() % n << "\t";
    }
    outf.close();

    inf.open("iinput.txt");
    for (int i = 0; i < n; i++){
        inf >> a[i];
    }
    inf.close();

    InsertionSort(a, n);

    outf.open("ioutput.txt");
    outf << "count for random : " << c << endl;
    for (int i = 0; i < n; i++){
        outf << a[i] << "\t";
    }
    outf << endl;
    outf.close();

    InsertionSort(a, n);

    outf.open("ioutput.txt", ios::app);
    outf << "count for ordered : " << c << endl;
    for (int i = 0; i < n; i++){
        outf << a[i] << "\t";
    }
    outf << endl;
    outf.close();

    Descending(a, n);

    InsertionSort(a, n);

    outf.open("ioutput.txt", ios::app);
    outf << "count for descending ordered : " << c << endl;
    for (int i = 0; i < n; i++){
        outf << a[i] << "\t";
    }
    outf << endl;
    outf.close();
}