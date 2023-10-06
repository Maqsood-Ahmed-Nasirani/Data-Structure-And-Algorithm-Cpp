#include <iostream>
#include <cmath>
using namespace std;

void sievePrime(int n);
void primeFactor(int n);

int main() {
    int n;
    cin >> n;
    primeFactor(n);
    sievePrime(n);

    cout << "Sieve\n";
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }

    return 0;
}

void sievePrime(int n)
{
    bool prime[100] = {0};
    for(int i = 2; i <= n; i++)
    {
        if(prime[i] == 0)
        {
            for(int j = i*i; j <= n; j+=i)
            {
                prime[j] = 1;
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
        if(prime[i] == 0)
        cout << i << " ";
    } cout << endl;
}

void primeFactor(int n)
{
    int spf[100] = {0};
    for(int i = 2; i <= n; i++){
        spf[i] = i;
    }

    for(int i = 2; i <= n; i++){
        if(spf[i] == i){
            for(int j = i*i; j <= n; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    while(n != 1){
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}

