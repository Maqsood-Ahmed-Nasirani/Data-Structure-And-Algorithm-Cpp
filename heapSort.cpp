#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &a, int n, int i) {
    int maxIdx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[maxIdx]) {
        maxIdx = l;
    }

    if (r < n && a[r] > a[maxIdx]) {
        maxIdx = r;
    }

    if (maxIdx != i) {
        swap(a[i], a[maxIdx]);

        heapify(a, n, maxIdx);
    }
}

void heapSort(vector<int> &a) {
    int n = a.size();

    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);

    vector<int> a = {4, 5, 3, 2, 6, 1};
    heapSort(a);

    cout << "Sorted array: ";
    for (const auto &num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
