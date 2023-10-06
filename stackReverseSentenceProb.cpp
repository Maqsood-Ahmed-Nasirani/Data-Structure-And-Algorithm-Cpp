#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string s)
{
    stack<string> st;
    for(int i = 0; i < s.length(); i++)
    {
        string word = "";
        while(s[i] != ' ' && i < s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(void)
{
    string s = "Hey, how are you doing?";
    reverseSentence(s);

//     stack<int> st;
//     st.push(3);
//     cout << st.top();
}