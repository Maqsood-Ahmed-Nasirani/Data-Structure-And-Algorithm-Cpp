#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int maxSum(int arr[], int n, int k) {
    if(n < k) {
        cout << "Invalid values\n";
        return -1;
    }
    int res = 0;

    for(int i = 0; i < n; i++) {
        res += arr[i];
    }

    int sum = res;

    for(int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        res = max(res, sum);
    }
    
    return res;
}


bool isNumberPerfect(int n) {
    int sum = 1;

    for(int i = 0; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(i == n / i) {
                sum += i;
            }
            else {
                sum += i + n / i;
            }
        }
    }

    if(sum == n && n != 1)
        return true;


    return false;
}


int maxNumbersOfPerfect(int arr[], int n, int k) {
    for(int i = 0; i < n; i++) {
        if(isNumberPerfect(arr[i])) 
            arr[i] = 1;
        else   
            arr[i] = 0;
    }

    return maxSum(arr, n, k);
}


int findPeakElement(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;

    if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
    else if(mid > 0 && arr[mid - 1] > arr[mid]) 
        return findPeakElement(arr, low, mid - 1, n);
    else    
        return findPeakElement(arr, mid + 1, high, n);
}


int main(void) {
    ios_base::sync_with_stdio(false);

    // int Array[] = {28, 2, 3, 6, 496, 99, 8128, 24};

    // cout << maxNumbersOfPerfect(Array, 8, 4) << '\n';

    int arr[] = {0, 6, 8, 5, 7, 9};

    cout << findPeakElement(arr, 0, 5, 6);
    return 0;
}