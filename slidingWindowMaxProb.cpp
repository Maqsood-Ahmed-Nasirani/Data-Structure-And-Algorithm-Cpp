#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> slidingWindowProbM1(vector<int> &a, int n, int k) {
    multiset<int, greater<int>> s;
    vector<int> ans;

    for (int i = 0; i < k; i++)
        s.insert(a[i]);

    ans.push_back(*s.begin());
    for (int i = k; i < n; i++) {
        s.erase(s.lower_bound(a[i - k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }

    return ans;
}

vector<int> slidingWindowProbM2(vector<int> &a, int n, int k){
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i < k; i++){
        while(!dq.empty() && a[q.back()] < a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);
    for(int i = k; i < n; i++){
        if(dq.front() == i - k){
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()] < a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[q.front()]);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto &i : a)
        cin >> i;

    vector<int> ans = slidingWindowProbM1(a, n, k);

    for (auto i : ans)
        cout << i << " ";

    
    vector<int> res = slidingWindowProbM2(a, n, k);
    for(auto i: res)
        cout << i << " ";
    return 0;
}
