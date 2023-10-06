#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    bool ans = true;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == ']'){
            if(st.top() == '['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == '}'){
            if(st.top() == '{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }
    
    return ans;
}

int main(void)
{
    string s = "{([])}";

    if(isValid(s))
        cout << "Valid String\n";
    else    
        cout << "Invalid String\n";
    
    return 0;
}