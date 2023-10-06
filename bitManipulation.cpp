#include <iostream>
using namespace std;

#define bits 0b0101

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    int mask = ~(1<<pos);
    return n & mask;
}

int updateBit(int n, int pos, int value)
{
    int mask = ~(1 <<pos);
    n = n & mask;

    return(n | (value<<pos));
}

int main(void)
{
    cout << getBit(5, 2);
    // cout << updateBit(5, 1, 1);
}