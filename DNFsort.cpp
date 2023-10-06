#include <iostream>
#include <vector>
using namespace std;

//function prototypes
void DNFsort(vector<int> &a); //Dutch National Flag(DNF)
void swap(vector<int> &a, int, int);

int main(void)
{
    vector<int> v = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    DNFsort(v);
    for(auto &i: v)
        cout << i << " ";
    
    return 0;
}

void DNFsort(vector<int> &a)
{
    int low = 0, mid = 0, high = (a.size() - 1);

    while(mid <= high)
    {
        if(a[mid] == 0){
            swap(a, low, mid);
            low++; mid++;
        }
        else if(a[mid] == 1)
        {
            mid++;
        }
        else{
            swap(a, mid, high);
            high--;
        }
    }
}

void swap(vector<int> &a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}