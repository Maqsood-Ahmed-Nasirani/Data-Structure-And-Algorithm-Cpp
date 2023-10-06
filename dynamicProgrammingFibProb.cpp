#include <iostream>
#include <cstring> 
#include <vector>
using namespace std;

const int N = 1e5 + 2;
long long dp[N];


//memoization
long long fib(int n) {
    if (n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1) + fib(n - 2);

    return dp[n];
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    // Initialize the dp array to -1 using memset
    memdyset(dp, -1, sizeof(dp));
    for(int i = 0; i <= n; ++i)
        cout << fib(i) << '\n';


    //tabulative approach
    vector<long long> Dp(N + 1, -1);
    Dp[0] = 0, Dp[1] = 1, Dp[2] = 1;
    for(auto i = 3; i <= n; i++) {
        Dp[i] = Dp[i - 1] + Dp[i - 2];
    }

    cout << Dp[n] << '\n';

    return 0;
}
