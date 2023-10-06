#include <iostream>
using namespace std;

bool isSafe(int** A, int x, int y, int n);
bool ratInMaze(int** A, int x, int y, int n, int** S);

/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/


int main(void)
{
    int n;
    cin >> n;

    int** A = new int*[n]; // allocating memory for 2d array
    for(int i = 0; i < n; i++){
        A[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    int** S = new int*[n]; // allocating memory for 2d array
    for(int i = 0; i < n; i++){
        S[i] = new int[n];
        for(int j = 0; j < n; j++){
            S[i][j] = 0;
        }
    }

    if(ratInMaze(A, 0, 0, n, S)){
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << S[i][j] << " ";
            } 
            cout << endl;
        }
    }

    //deallocating memory
    for(int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] S[i];
    }
}

bool isSafe(int** A, int x, int y, int n)
{
    if(x < n && y < n && A[x][y] == 1){
        return true;
    }
    return false;
}

bool ratInMaze(int** A, int x, int y, int n, int** S)
{
    if(x == n - 1 && y == n - 1)
    {
        S[x][y] = 1;
        return true;
    }

    if(isSafe(A, x, y, n))
    {
        S[x][y] = 1;

        if(ratInMaze(A, x + 1, y, n, S))
            return true;

        if(ratInMaze(A, x, y + 1, n, S))
            return true;

        S[x][y] = 0;
        return false;   
    }

    return false;
}
