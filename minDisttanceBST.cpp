#include <iostream>
#include <algorithm>
using namespace std;


bool isFeasible(int mid, int a[], int n, int k) {
    int pos = a[0], elements = 1;

    for(int i = 1; i < n; ++i) {
        if(a[i] - pos >= mid) {
            pos = a[i];
            elements++;
            if(elements == k) {
                return true;
            }
        }
    }

    return false;
}


int largestMinDist(int a[], int n, int k) {
    sort(a, a + n);

    int res = -1;
    int left = 1, right = n - 1;

    while(left < right) {
        int mid = (left + right) / 2;
        if(isFeasible(mid, a, n, k)) {
            res = max(res, mid);
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return res;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    int a[] = {1, 2, 8, 4, 9};

    cout << "Largest min distance: " << largestMinDist(a, 5, 3) << '\n';
    return 0;
}