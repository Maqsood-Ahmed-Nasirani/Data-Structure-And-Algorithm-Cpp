#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string to_upper_string(string);
string to_lower_string(string);

int main(void){
    //problem 1
    string sr = "jfasklfjsiodfjsdnflsd";
    int freq[26];

    for(int i = 0; i < 26; i++)
        freq[i] = 0;

    for(int i = 0; i < sr.length(); i++)
        freq[sr[i] - 'a']++;
    
    int mx = -1;
    char ans;
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > mx)
        {
            mx = freq[i];
            ans = i + 'a';
        }

    }
    
    cout << mx << " " << ans << endl;

    //problem 2
    string str;
    cout << "Enter your string: ";
    cin >> str;

    //problem 3
    string s = "247298472947";
    sort(s.begin(), s.end());
    cout << s << endl;
    
    
    int choice = 0; 
    while(!(choice > 0 && choice < 3))
    {
        cout << "Enter a number to convert string to:\n1: to_lower\n2: to_upper\n(1/2): ";
        cin >> choice;
    }
    
    if(choice == 1)
        cout << to_lower_string(str) << endl;

    else    
        cout << to_upper_string(str) << endl; 

}

string to_upper_string(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 65 && str[i] <= 90){
            str[i] = str[i];
        }
        
        else if(str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
        }
        else{
            cout<<"Not a valid string\n";
            exit(0);
        } 
    }
    return str;
}

string to_lower_string(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 65 && str[i] <= 90){
            str[i] += 32;
        }
        
        else if(str[i] >= 97 && str[i] <= 122){
            str[i] = str[i];
        }
        else{
            cout<<"Not a valid string\n";
            exit(0);
        } 
    }
    return str;
}