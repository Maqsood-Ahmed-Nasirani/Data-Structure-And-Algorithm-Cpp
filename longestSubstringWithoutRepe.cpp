#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define BUFFER_SIZE 255

int main(void)
{
    string s; cin >> s;
    vector<int> a(BUFFER_SIZE, -1);
    int maxLen = 0, start = -1;
    for(int i = 0; i < s.size(); i++){
        if(a[s[i]] > start)
            start = a[s[i]];

        a[s[i]] = i;

        maxLen = max(maxLen, i - start);
    }

    cout << maxLen << endl;

    return 0;
}