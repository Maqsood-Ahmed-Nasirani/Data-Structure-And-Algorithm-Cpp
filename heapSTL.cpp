#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>> maxpq; // max heap
    maxpq.push(2);
    maxpq.push(3);
    maxpq.push(1);

    cout << maxpq.top() << ' ';

    priority_queue<int, vector<int>, greater<int>> minpq; // min heap
    minpq.push(2);
    minpq.push(3);
    minpq.push(1);
    cout << minpq.top() << ' ';

    return 0;
}