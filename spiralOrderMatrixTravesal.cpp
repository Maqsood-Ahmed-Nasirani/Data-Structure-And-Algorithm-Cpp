#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m;
    cout<<"Enter n & m: ";
    cin >> n >> m;

    int Arr[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            Arr[i][j] = (i + j)*5;
        }
    }

    //printing the matrix
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cout<<Arr[row][col]<<" ";
        }
        cout<<endl;
    }
    //spiral order print
    int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = m - 1;

    while(rowStart <= rowEnd && colStart <= colEnd){
        //for rowstart
        for(int col = colStart; col < colEnd; col++){
            cout<<Arr[rowStart][col]<<" ";
        }
        rowStart++;

        //for column end
        for(int row = rowStart; row < rowEnd; row++){
            cout<<Arr[row][colEnd]<<" ";
        }
        colEnd--;

        //for row end
        for(int col = colEnd; col >= colStart; col--){
            cout<<Arr[rowEnd][col]<<" ";
        }
        rowEnd--;

        //for column start
        for(int row = rowEnd; row >= rowStart; row--){
            cout<<Arr[row][colEnd]<<" ";
        }
    } 

}