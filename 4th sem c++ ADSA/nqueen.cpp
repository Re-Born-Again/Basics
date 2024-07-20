#include <iostream>
using namespace std;

#define maxr 100
#define maxc 100

int n;
int k = 0;

void disp(int board[][maxc]){
    k++;
    cout << k << ". [ ";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (board[i][j] == 1){
                cout << j + 1 << " ";
            }
        }
    }
    cout << "]" << endl;
}

bool safe(int board[][maxc], int row, int col){
    if (row == 0){
        return true;
    }
    for (int i = 0; i < row; i++){
        if (board[i][col] == 1){
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 1){
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n ; i--, j++){
        if (board[i][j] == 1){
            return false;
        }
    }
    if (row == n - 1){
        disp(board);
    }
    return true;
}

void nqueen(int board[][maxc], int row){
    for (int i = 0; i < n; i++){
        board[row][i] = 1;
        if (safe(board, row, i)){
            nqueen(board, row + 1);
        }
        board[row][i] = 0;
    }
}

int main(){
    cout << "Enter the no. queen : ";
    cin >> n;
    int board[maxr][maxc];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    int row = 0;
    cout << "Positions of queens : " << endl;
    nqueen(board, row);
    cout << "No. solutions found : " << k << endl;
}