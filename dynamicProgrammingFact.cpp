#include <iostream>
#include <vector>
using namespace std;

// Function to calculate factorial using dynamic programming
unsigned long long factorial(int n) {
    vector<unsigned long long> dp(n + 1);

    // Base case: 0! = 1
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        unsigned long long result = factorial(n);
        cout << "Factorial of " << n << " is: " << result << endl;
    }

    return 0;
}
