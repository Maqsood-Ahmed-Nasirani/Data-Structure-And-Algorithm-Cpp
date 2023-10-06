#include <iostream>
using namespace std;


void countSort(int a[], int size);

int main(void)
{
    int a[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int len = sizeof(a)/sizeof(a[0]);
    cout << "Before\n";
    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    countSort(a, len);

    cout << "After\n";
    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout << endl;

}

void countSort(int a[], int size)
{
    int mx = a[0];

    for(int i = 0; i < size; i++)
    {
        mx = max(mx, a[i]);
    }

    int count[size] = {0};

    for(int i = 0; i < size; i++){
        count[a[i]]++;
    }
    
    for(int i = 1; i <= mx; i++)
    {
        count[i] += count[i - 1];
    }

    int output[size];

   for(int i = size - 1; i >= 0; i--)
   {
        output[--count[a[i]]] = a[i]; 
   }

   for(int i = 0; i < size; i++)
   {
        a[i] = output[i];
   }
}