#include <iostream>
using namespace std;

int sum(int n);
int raisedToPow(int n, int p);
int factorial(int n);
int fibonacci(int n);
bool sorted(int arr[], int s);
void inc(int n);
void dec(int n);
int firstOccurence(int arr[], int s, int i, int key);
int lastOccurence(int arr[], int s, int i, int key);

int main(void){
    int n, p;
    cin >> n >> p;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << firstOccurence(A, n, 0, p) << endl;
    cout << lastOccurence(A, n, 0, p) << endl;

    // inc(n);
    // cout << endl;
    // dec(n);
    // for(int i = 0; i < n; i++)
    // {
    //     cin >> A[i];
    // }

    // cout << sorted(A, n) << endl;
    // cout << fibonacci(n) << endl;
    // cout << factorial(n) << endl;
    // cin >> n >> p;
    // cout << raisedToPow(n, p) << endl;;
    //cout << sum(n) << endl;
}

int sum(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return n + sum(n - 1);
}

int raisedToPow(int n, int p)
{
    if(p == 0)
        return 1;

    int pre = raisedToPow(n, p-1);
    return n * pre;
}

int factorial(int n)
{
    if(n == 1 || n == 0){
        return 1;
    }

    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}


bool sorted(int arr[], int s)
{
    if(s == 1)
        return true;

    bool restArray = sorted(arr + 1, s - 1);
    return(arr[0] < arr[1] && restArray);
}

void inc(int n)
{
    if(n == 1){
        cout << "1 ";
        return;
    }

    inc(n - 1);
    cout << n << " ";
}

void dec(int n)
{
    if(n == 1){
        cout <<"1 ";
        return;
    }
    
    cout << n << " ";
    dec(n - 1);
}

int firstOccurence(int arr[], int s, int i, int key){
    if(i == s)
        return -1;

    if(arr[i] == key)
        return i;

    return firstOccurence(arr, s, i + 1, key);
}

int lastOccurence(int arr[], int s, int i, int key){
    if(i == s)
        return -1;

    int restArr = lastOccurence(arr, s, i + 1, key);

    if(restArr != -1)
        return restArr;

    if(arr[i] == key)
        return i;

    return -1;
}
