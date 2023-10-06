#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void) {

    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    priority_queue<int, vector<int>> pq;
    for(auto i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    int sum = 0;
    int cnt = 0;

    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();

        cnt++;

        if(sum >= k)
            break;
    }

    if(sum < k)
        cout << "-1\n";
    else    
        cout << cnt << '\n';

    return 0;
}