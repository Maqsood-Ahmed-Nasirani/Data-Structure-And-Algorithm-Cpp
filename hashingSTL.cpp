#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


int main(void) {

    ios_base::sync_with_stdio(false);

    int n; 
    cin >> n;
    vector<int> a(n);

    for(auto &i: a)
        cin >> i;
    
    map<int, int> freq;

    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    map<int, int> :: iterator it;
    for(it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << ' ' << it->second << '\n';
    }
    
    return 0;   
}