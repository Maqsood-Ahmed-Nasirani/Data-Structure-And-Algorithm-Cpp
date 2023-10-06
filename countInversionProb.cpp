#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
int mergeSortAndCount(vector<int> &a, int left, int right);
int merge(vector<int> &a, int left, int mid, int right);

int main(void)
{
    vector<int> v = {3, 5, 6, 9, 1, 2, 7, 8};

    cout << mergeSortAndCount(v, 0, v.size() - 1) << endl; 
}

int mergeSortAndCount(vector<int> &a, int left, int right)
{
    int inv = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv += mergeSortAndCount(a, left, mid);
        inv += mergeSortAndCount(a, mid + 1, right);
        inv += merge(a, left, mid, right);
    }
    return inv;
}

int merge(vector<int> &a, int left, int mid, int right)
{
    int inv = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
            inv += (n1 - i);
        }
    }

    while (i < n1) {
        a[k++] = L[i++];
    }

    while (j < n2) {
        a[k++] = R[j++];
    }

    return inv;
}
