#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function prototypes
void insert(int x);
double findMedian();

priority_queue<int, vector<int>, greater<int>> pqmin; // min heap
priority_queue<int, vector<int>> pqmax; // max heap

int main(void) {
    ios_base::sync_with_stdio(false);

    insert(10);
    cout << findMedian() << ' ';
    insert(15);
    cout << findMedian() << ' ';
    insert(11);
    cout << findMedian() << ' ';
    insert(20);
    cout << findMedian() << ' ';

    return 0;
}

void insert(int x) {
    if (pqmin.size() == pqmax.size()) {
        if (pqmax.empty()) {
            pqmax.push(x);
            return;
        }

        if (x < pqmax.top())
            pqmax.push(x);
        else
            pqmin.push(x);
    } else {
        if (pqmax.size() > pqmin.size()) {
            if (x >= pqmax.top()) {
                pqmin.push(x);
            } else {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        } else {
            if (x <= pqmin.top()) {
                pqmax.push(x);
            } else {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian() {

    if (pqmin.size() == pqmax.size())
        return static_cast<double>(pqmin.top() + pqmax.top()) / 2.0;
    else if (pqmax.size() > pqmin.size())
        return pqmax.top();
    else
        return pqmin.top();
}
