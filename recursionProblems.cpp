#include <iostream>
#include <string>
using namespace std;

//function prototypes
string reversStr(string, int);
string replacePi(string);
void towerOfHanoi(int, char, char, char);
string removeDuplicates(string);
string moveAllx(string);
void subseq(string, string);
void subseqASCII(string, string);
void keypad(string, string);

const string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main(void){
    keypad("23", "");
    subseqASCII("AB", "");
    subseq("ABC", "");
    cout << moveAllx("xIamThexmanAndYou") << endl;
    cout << removeDuplicates("maqsooodAhhmmmed") << endl;
    towerOfHanoi(3, 's', 'd', 'h');
    string s = "MaqsPIood";
    cout << replacePi(s) << endl;
    cout << reversStr(s, 0) << endl;
}

string reversStr(string s, int i)
{
    if(s.length() == i){
        return "";
    }

    char currChar = s[i];
    string rs = reversStr(s, i + 1);
    return rs + currChar;
}

string replacePi(string s){
    if(s.length() == 0)
        return "";

    if(s[0] == 'P' && s[1] == 'I')
        return  "3.14" + replacePi(s.substr(2));
    else
        return s[0] + replacePi(s.substr(1)); 
}


void towerOfHanoi(int n, char src, char dest, char helper)
{
    if(n == 0)
        return; 

    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, src);
    cout << "Move from " << helper << " to " << src << endl;
      
}

string removeDuplicates(string s)
{
    if(s.length() == 0)
        return "";

    char ch = s[0];
    string ans = removeDuplicates(s.substr(1));

    if(ch == ans[0])
        return ans;

    return (ch + ans);
}

string moveAllx(string s){
    if(s.length() == 0)
        return "";

    char ch = s[0];

    string ans = moveAllx(s.substr(1));

    if(ch == 'x')
        return ans + ch;

    return ch + ans;
}

void subseq(string s, string ans){
    if(s.length() == 0){
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string rs = s.substr(1);

    subseq(rs, ans);
    subseq(rs, ans + ch);
}

void subseqASCII(string s, string ans)
{
    if(s.length() == 0){
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int ascii = ch;
    string rs = s.substr(1);

    subseqASCII(rs, ans);
    subseqASCII(rs, ans + ch);
    subseqASCII(rs, ans + to_string(ascii));

}

void keypad(string s, string ans){
    if(s.length() == 0){
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string code = keypadArr[ch - '0'];
    string rs = s.substr(1);

    for(int i = 0; i < code.length(); i++)
    {
        keypad(rs, ans + code[i]);
    }
}