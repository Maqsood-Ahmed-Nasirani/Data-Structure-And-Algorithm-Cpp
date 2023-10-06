#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;
    vector<vector<int>> a(k);
    for(int i = 0; i < k; i++) {
        int size;
        cin >> size;
        a[i] = vector<int>(size);
        for(int j = 0; j < size; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

    for(int i = 0; i < k; ++i) {
        pq.push({a[i][0], i});
    }

    vector<int> ans;

    while(!pq.empty()) {
        pair<int, int> x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(idx[x.second] + 1 < a[x.second].size()) {
            pq.push({a[x.second][idx[x.second] + 1], x.second});
        }

        idx[x.second] += 1;
    }

    for(const auto &i: ans) {
        cout << i << ' ';
    } cout << '\n';

    return 0;
}