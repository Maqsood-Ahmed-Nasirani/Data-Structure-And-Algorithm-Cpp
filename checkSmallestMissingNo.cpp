#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    const int N = 1e6 + 2;
    bool check[N];

    for(int i = 0; i < n; i++){
        if(A[i] >= 0){
            check[A[i]] = true;
        }
        else{
            check[A[i]] = false;
        }
    }

    int ans = -1;

    for(int i = 0; i < n; i++){
        if(!check[i]){
            ans = i;
            break;
        }
    }

    cout<<ans<<endl;
}