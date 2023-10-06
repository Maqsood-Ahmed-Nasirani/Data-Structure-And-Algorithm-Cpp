#include <iostream>
using namespace std;

int euclid(int a, int b);

int main(void){
    int a, b;
    cin >> a >> b;
    cout << euclid(a, b) << endl;
}

int euclid(int a, int b)
{
    while(b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}