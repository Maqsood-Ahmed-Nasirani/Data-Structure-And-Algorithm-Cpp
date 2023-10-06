#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int wc = 0, i = s.size() - 1;
    while(i >= 0 && s[i] == ' ')
            i--;
    
        while(i >= 0 && s[i] != ' '){
            wc++;
            i--;
        }
            
    return wc;
}

int main(void){
    
    cout << lengthOfLastWord("Hello, World") << endl;
    
    return 0;
}