#include <bits/stdc++.h>
using namespace std;

int kadanesAlgorithm(int *arr, int size){
    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < size; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int32_t main(void){
    int n;
    cout<<"Enter n: ";
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int wrapsum = 0, nonwrapsum = 0;
    nonwrapsum = kadanesAlgorithm(A, n);
    int totalsum = 0;
    for(int i = 0; i < n; i++){
        totalsum += A[i];
        A[i] = -A[i];
    }

    wrapsum = totalsum + kadanesAlgorithm(A, n);

    cout<<max(wrapsum, nonwrapsum)<<endl;
}