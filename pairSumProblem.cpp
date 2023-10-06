#include <bits/stdc++.h>
using namespace std;

//function prototypes
bool pairSum(int *, int, int);

int main(void){
    int A[] = {1, 2, 3, 6, 7, 12, 22};
    int target = 13;
    bool check = pairSum(A, 7, target);
    if(check){
        cout<<"Pair is present\n";
    }
    else{
        cout<<"Pair is not present\n";
    }

}

bool pairSum(int *arr, int size, int key){
    int sum = 0;
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            sum = arr[i] + arr[j];
        
            if(sum == key){
                cout<<i<<" "<<i + 1<<endl;
                return true;
            }
            else{
                sum = 0;
            }
        }
    }
    return false;
}