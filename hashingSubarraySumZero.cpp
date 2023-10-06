#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i: a)
        cin >> i;

    map<int, int> cnt;
    int prefSum = 0;

    for(int i = 0; i < n; i++) {
        prefSum += a[i];
        cnt[prefSum]++;
    }

    int ans = 0;

    map<int, int> :: iterator it;
    for(it = cnt.begin(); it != cnt.end(); ++it) {

        int c = it->second;

        ans += (c*(c-1))/2;

        if(it->first == 0)
            ans += it->second;
    }

    cout << ans << '\n';

    return 0;
}