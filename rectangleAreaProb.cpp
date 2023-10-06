#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int get_max_area(vector<int> a);

int main(void)
{
    vector<int> a = {2, 1, 5, 6, 2, 3};
    cout << get_max_area(a);
}


int get_max_area(vector<int> a)
{
    stack<int> st;
    int ans = 0, i = 0;
    a.push_back(0);
    while(i < a.size()){
        while(!st.empty() && a[st.top()] > a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if(st.empty()){
                ans = max(ans, h * i);
            }
            else{
                int len = i - st.top() - 1;
                ans = max(ans, h * len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}