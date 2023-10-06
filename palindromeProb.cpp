#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    char object[n + 1];
    cout<<"Enter object name: ";
    cin>> object;

    bool check = true;

    for(int index = 0; index < n; index++){
        if(object[index] != object[n - 1 - index]){
            check = false;
            break;
        }
    }

    if(check){
        cout<<"Given object is palindrome\n";
    }
    else{
        cout<<"Given object is not palindrome\n";
    }

}