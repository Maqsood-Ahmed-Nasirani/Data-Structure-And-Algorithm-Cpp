#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **A, int x, int y, int n);
bool nQueen(int **A, int x, int n);

int main(void)
{
    int n;
    cin >> n;

    int** A = new int*[n];//allocating memory
    for(int i = 0; i < n; i++){
        A[i] = new int[n];
        for(int j = 0; j < n; j++){
            A[i][j] = 0;
        }
    }

    //nQueen function
    if(nQueen(A, 0, n)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    //deallocating memory
    for(int i = 0; i < n; i++){
        delete[] A[i]; 
    }
}

bool isSafe(int **A, int x, int y, int n)
{
    for(int row = 0; row < x; row++)
    {
        if(A[row][y] == 1)
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    while(row >= 0 && col >= 0)
    {
        if(A[row][col] == 1)
        {
            return false;
        }

        row--;
        col--;
    }

    row = x;
    col = y;

    while(row >= 0 && col < n)
    {
        if(A[row][col] == 1)
        {
            return false;
        }

        row--;
        col++;
    }

    return true;
}

bool nQueen(int **A, int x, int n)
{
    if(x >= n){
        return true;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(A, x, col, n)){
            A[x][col] = 1;
            if(nQueen(A, x + 1, n)){
                return true;
            }
            A[x][col] = 0; //backtracking
        }
    }
    return false;
}