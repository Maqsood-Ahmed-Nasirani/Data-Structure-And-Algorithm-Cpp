#include <iostream>
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right) {
    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(arr[mid] == key)
        return mid;

    if(arr[mid] <= arr[mid]) {
        if(key >= arr[left] && key <= arr[mid]) {
            return searchInRotatedArray(arr, key, left, mid - 1);
        }
        return searchInRotatedArray(arr, key, mid + 1, right);

    }

    if(key >= arr[mid] && key <= arr[right]) {
        return searchInRotatedArray(arr, key, mid + 1, right);
    }

    return searchInRotatedArray(arr, key, left, mid - 1);
    
}

int main(void) {

    ios_base::sync_with_stdio(false);
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int idx = searchInRotatedArray(arr, 8, 0, 7);
    
    if(idx == -1)
        cout << "Key doesn't exist\n";
    else    
        cout << "Key exist at index: " << idx << '\n';

    return 0;
}