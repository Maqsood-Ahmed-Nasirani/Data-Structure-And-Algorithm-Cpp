#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans
//function prototypes
void permutation(string, string);
int countPath(int, int);
int countPathMaze(int, int, int);
int tilingWays(int);
int friendsPairing(int n);
int knapsack(int value[], int wt[], int n, int w);
void permute(vector<int> &A, int idx);


int main(void)
{
    vector<int> A = {10, 20, 30};

    permute(A, 0);

    // int value[] = {100, 50, 150};
    // int w = 50;
    // cout << knapsack(value, wt, 3, w) << endl;
    // cout << friendsPairing(4) << endl;
    // cout << tilingWays(4) << endl;
    // cout << countPathMaze(3, 0, 0) << endl;
    // cout << countPath(1, 1) << endl;
    // permutation("ABC", "");
    // return 0;
}

void permutation(string s, string ans)
{
    if(s.length() == 0){
        cout << ans << endl;
        return;
    }

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        string rs = s.substr(0, i) + s.substr(i + 1);
        permutation(rs, ans + ch);
    }        
}

int countPath(int s, int e){
    if(s == e)
        return 1;

    if(s > e)
        return 0;

    int count = 0;
    for(int i = 1; i <= 6; i++)
    {
        count += countPath(s + i, e);
    }

    return count;
}

int countPathMaze(int n, int i, int j)
{
    if(i == n - 1 && j == n - 1)
        return 1;

    if(i >= n || j >= n)
        return 0;

    return (countPathMaze(n, i + 1, j) + countPathMaze(n, i, j + 1));
}

int tilingWays(int n){
    if(n == 0 || n == 1)
        return n;

    return (tilingWays(n - 1) + tilingWays(n - 2));   
}

int friendsPairing(int n){
    if(n == 0 || n == 1 || n == 2)
        return n;

    return (friendsPairing(n - 1) + (friendsPairing(n - 2) * (n - 1)));
}

int knapsack(int value[], int wt[], int n, int w)
{
    if(n == 0 || w == 0)
        return 0;

    if(wt[n - 1] > w)
        return knapsack(value, wt, n - 1, w);

    return max(knapsack(value, wt, n - 1, w - wt[n - 1]) + value[n - 1],
    knapsack(value, wt, n - 1, w));
}

void permute(vector<int> &A, int idx)
{
    if(idx == A.size()){
        ans.push_back(A);
        return;
    }

    for(int i = idx; i < A.size(); i++)
    {
        swap(A[i], A[idx]);
        permute(A, idx + 1);
        swap(A[i], A[idx]);
    }

    return;
}