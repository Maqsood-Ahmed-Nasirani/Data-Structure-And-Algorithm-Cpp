#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n = 4, m = 3;
    int arr[n][m] = {{1,2,3},{4,5,6},{7,8,9},{10, 11, 12}};
    //giving values to matrix and printing

    // cout<<"Transpose by First Method\n";

    // for(int row = 0; row < 3; row++){
    //     for(int col = 0; col < 3; col++){
    //         cout<<arr[col][row]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<"Transpose by Second Method\n";

    for(int row = 0; row < n; row++){
        for(int col = row; col < m; col++){
            //swap
            int temp = arr[row][col];
            arr[row][col] = arr[col][row];
            arr[col][row] = temp;

        }
    }

    //printing the matrix
     for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

}