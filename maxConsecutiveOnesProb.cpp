#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    for(auto &i: a){
        cin >> i;
    }

    int zrcnt = 0, i = 0, ans = 0;

    for(int j = 0; j < a.size(); j++){
        if(a[j] == 0)
            zrcnt++;

        while(zrcnt > k){
            if(a[i] == 0)
                zrcnt--;
            
            i++;
        }
        ans = max(ans, j - i + 1);
    }

    cout << ans;
}