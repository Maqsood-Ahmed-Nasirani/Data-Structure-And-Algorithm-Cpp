#include <bits/stdc++.h>
using namespace std;

int main(void){

    int array[] = {3, 5, 7, 7, 8, 9, 11, 17, 3, 19};
    int length = sizeof(array)/sizeof(array[0]);
    int minidx = INT_MAX - 1;
    const int N = 1e6+2;
    int idx[N];

    //initalizing all elements with -1;
    for(int i = 0; i < length; i++){
        idx[array[i]] = -1;
    }

    for(int i = 0; i < length; i++){
        if(idx[array[i]] != -1){
            minidx = min(minidx, idx[array[i]]);
        }
        else{
            idx[array[i]] = i;      
        }
    }

    if(minidx == INT_MAX - 1){
        cout<<"-1\n";
    }
    else{
        cout << minidx + 1 <<endl;
    }
}