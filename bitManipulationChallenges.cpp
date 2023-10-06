#include <iostream>
using namespace std;

bool isPowerOfTwo(int n);
int numberOfOnes(int n);
void subSet(char *, int);

int main(void)
{
    char arr[] = {'a', 'b', 'c'};
    subSet(arr, 3);
    cout << numberOfOnes(7) << endl;
    cout << isPowerOfTwo(18) << endl;   
    return 0;
}

int numberOfOnes(int n){

    int ones = 0;
    while(n)
    {
        n = n & n - 1;
        ones++;
    }

    return ones;
}


bool isPowerOfTwo(int n)
{
    return (n && !(n & n - 1));
}

void subSet(char * arr, int size){
    for(int i  = 0; i < (1<<size); i++)
    {
        for(int j = 0; j < size; j++)
        {              
            if(i & (1 << j)){
                cout << arr[j] << " ";
            }
        }cout << endl;
    }
}
