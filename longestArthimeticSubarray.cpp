#include <bits/stdc++.h>
using namespace std;

int main(void){
    int array[] = {3, 5, 7 , 5, 8, 9, 11, 17, 3, 19};
    int arrLength = sizeof(array)/sizeof(array[0]);
    int j = 2;
    int pd = array[1] - array[0];
    int curr = 2, ans = 2;

    while(j < arrLength){
        if(pd == array[j] - array[j - 1]){
            curr++;
        }
        else{
            pd = array[j] - array[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
    }

    cout<<ans<<endl;

}