#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cout<<"Enter n: ";
    cin >> n;
    int A[n];

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int currentSum = 0, maxSum = INT_MIN;

    for(int i = 0; i < n; i++){
        currentSum += A[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        maxSum = max(currentSum, maxSum);
    }

    cout<<"maxSum: "<<maxSum<<endl;
}