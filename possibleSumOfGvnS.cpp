#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n;
    cout<<"Enter n: ";
    cin>>n;

    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int S;
    cout << "Enter the value of S: ";
    cin >> S;

    int sum = 0, st = -1, en = -1;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum += A[j];
            st = i;
            en = j; 
            if(sum == S){
                cout<<st + 1<<" "<<en + 1<<endl;
                return 0;
            }
        }
        sum = 0;
    }
    if(sum != S){
        cout<<"Not possible\n";
    }

    return 0;

}