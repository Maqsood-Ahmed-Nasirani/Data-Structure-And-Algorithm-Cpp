#include <bits/stdc++.h>
using namespace std;

int main(void){
    int array[] = {3, 5, 7 , 5, 8, 9, 11, 17, 3, 19};
    int arrLength = sizeof(array)/sizeof(array[0]);
    int mx = -1, ans = 0;
    for(int i = 0; i < arrLength; i++){
        if(array[i] > mx && array[i] > array[i + 1]){
            ans++;
        }
        mx = max(mx, array[i]);
    }
    cout<<"Total record breaking days: "<<ans<<endl;
}