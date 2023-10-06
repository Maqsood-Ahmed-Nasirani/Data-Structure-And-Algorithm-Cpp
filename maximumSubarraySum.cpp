#include <bits/stdc++.h>
using namespace std;

int main(void){
    int array[] = {-1, 4, 7, 2};
    int sum = 0, length = sizeof(array)/sizeof(array[0]);
    int maxSum = INT_MIN;
    for(int i = 0; i < length; i++){
        for(int j = i; j < length; j++){
            for(int k = i; k <= j; k++){
                sum += array[k];
            }
            maxSum = max(maxSum, sum);
            sum = 0;
        }
    }
    cout<<"Sum of Subarray is: "<<maxSum<<endl;
}