#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void maxSubarraySum(int arr[], int n, int k, int x) {

    int sum = 0, ans = 0;
    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }

    if(sum < x)
        ans = sum;

    for(int i = k; i < n; i++) {
        sum -= arr[i - k];
        sum += arr[i];
        if(sum < x) {
            ans = max(ans, sum);
        }
    }   

    cout << "Maximum subarray sum is: " << ans << '\n';
}

int smallestSubarraySum(int arr[], int n, int x) {

    int sum = 0, minLen = n + 1, start = 0, end = 0;
    while(end < n) {

        while(sum <= x && end  < n) {
            sum += arr[end++];
        }

        while(sum > x && start < n) {
            if(end - start < minLen) {
                minLen = end - start;
            }
            sum -= arr[start++];
        }
    }

    return minLen;
}


void computeNumberFromSubarray(vector<int> arr, int k) {
    pair<int, int> ans;
    int sum = 0;

    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }

    bool found = false;

    if(sum % 3 == 0) {
        ans = make_pair(0, k - 1);
        found = true;
    }

    for(auto j = k; j < arr.size(); ++j) {
        if(found)
            break;
        
        sum += arr[j] - arr[j - k];

        if(sum % 3 == 0) {
            ans = make_pair(j - k + 1, j);
            found = true;
        }
    }

    if(!found) {
        ans = make_pair(-1, 0);
    }

    if(ans.first == -1) {
        cout << "No such subarray exist\n";
    } else {
        for(int i = ans.first; i <= ans.second; i++)
            cout << arr[i] << ' ';

        cout << '\n';
    }
    
}

bool isPalindrome(int n) {
    int org = n, res = 0;
    while(n != 0) {
        int rem = n % 10;
        res *= 10 + rem;
        n /= 10;
    }

    if(org != res) 
        return false;
    
    return true;
}

int findPalindromicSubarray(vector<int> arr, int k) {
    int num = 0;

    for(int i = 0; i < k; i++) {
        num *= 10 + arr[i];
    }

    if(isPalindrome(num))
        return 0;
    
    for(int i = k; i < arr.size(); i++) {
        num = (num % (int)pow(10, k - 1));

        if(isPalindrome(num)) {
            return i - k + 1;
        }
    }

    return -1;
}


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

    for(int i = 0; i < sqrt(n); i++) {
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


int main(void) {
    ios_base::sync_with_stdio(false);

    int arr[] = {7, 5, 4, 6, 8, 9};
    maxSubarraySum(arr, 6, 3, 20);

    int a[] = {1, 4, 45, 6, 10, 19};
    int n = 6;

    if(smallestSubarraySum(a, n, 51) == n + 1){
        cout << "Subarray sum doesn't exist\n";
    }
    else{
        cout << "It's exist: " << smallestSubarraySum(a, n, 51) << '\n';
    }

    vector<int> A = {84, 23, 45, 12, 56, 82};
    computeNumberFromSubarray(A, 3);


    vector<int> nums = {2, 3, 5, 1, 1, 5};

    if(findPalindromicSubarray(nums, 3) == -1)
        cout << "Palindromic subarray doesn't exist\n";
    else 
        cout << "It's exist\n";


    int Array[] = {28, 2, 3, 6, 496, 99, 8128, 24};

    cout << maxNumbersOfPerfect(Array, 8, 4) << '\n';
    return 0;
}