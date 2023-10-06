#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n1 = 2, n2 = 3, n3 = 2;
    int arr1[n1][n2] = { {1,2,3}, {4,5,6} };
    int arr2[n2][n3] = { {10, 11}, {20,21}, {30, 31} };
 
    //checking if multiplication is possible or not

    if(n2 == n2){
        cout<<"Multiplication is possible!\n";
    }
    else{
        cout<<"Multiplication is not possible!\n";
        return 0;
    }

    int result[n1][n3], sum = 0;
    //initializing the whole to zero
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n3; j++){
            result[i][j] = 0;
        }
    }
    //multiplying the matrices
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n3; j++){
            for(int k = 0; k < n2; k++){
                result[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }

    //print result matrix
    for(int row = 0; row < n1; row++){
        for(int col = 0; col < n3; col++){
            cout<<result[row][col]<<" ";
        }
        cout<<endl;
    }

}