#include <iostream>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    scanf("%d", &n);
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d\n", a[n/2]);
    for(int i = 0; i < n/2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    for(auto i: a)
        printf("%d ", i);

    return 0;
}