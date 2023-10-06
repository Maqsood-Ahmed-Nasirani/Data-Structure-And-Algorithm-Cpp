#include <iostream>
#include <vector>
using namespace std;

//function prototypes
void waveSort(vector<int> &a);
void swap(vector<int> &a, int, int);

int main(void)
{
    vector<int> v = {1, 3, 4, 7, 5, 6, 2};
    waveSort(v);

    for(auto i: v)
    {
        cout << i << " ";
    }
}

void waveSort(vector<int> &a)
{
    for(int i = 1; i < a.size(); i += 2)
    {
        if(a[i] > a[i - 1])
        {
            swap(a, i, i - 1);
        }

        if(a[i] > a[i + 1] && i <= (a.size()) - 2)
        {
            swap(a, i, i + 1);
        }
             
    }
}

void swap(vector<int> &a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}