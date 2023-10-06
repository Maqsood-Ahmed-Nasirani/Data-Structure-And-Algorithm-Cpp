#include <iostream>

using namespace std;

// Function prototypes
void mergeSort(int A[], int l, int r);
void merge(int A[], int l, int mid, int r);

int main()
{
    int A[] = {3, 2, 1, 9, 5};
    int n = sizeof(A) / sizeof(A[0]); // Calculate the size of the array
    mergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2; // Calculate the middle index to prevent integer overflow
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);
        merge(A, l, mid, r);
    }
}

void merge(int A[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = A[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = A[mid + 1 + i];
    }

    int i = 0, j = 0, k = l; // Initialize k with l

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j]) // Use <= to make it stable
        {
            A[k] = a[i];
            i++;
        }
        else
        {
            A[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = a[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = b[j];
        j++;
        k++;
    }
}
