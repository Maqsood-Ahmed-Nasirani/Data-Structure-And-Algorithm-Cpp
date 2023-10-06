#include <bits/stdc++.h>
using namespace std;

//function prototypes
void quickSort(int A[], int l, int r);
int partition(int A[], int l, int r);
void swap(int A[], int i, int j);

int main(void)
{
    int a[] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}

void quickSort(int A[], int l, int r)
{
    if(l < r){
        int pi = partition(A, l, r);
        quickSort(A, l, pi - 1);
        quickSort(A, pi + 1, r); 
    }
}

int partition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = l - 1;

    for(int j = l; j < r; j++)
    {
        if(A[j] < pivot)
        {
            i++;
            swap(A,i, j);
        }
    }
    swap(A, i + 1, r);
    return i + 1;
}

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp; 
}