#include <iostream>
using namespace std;

int main(void){
    string sentence;
    cout<<"Enter your sentence below:\n";
    getline(cin, sentence);
    
    int i = 0, currLen = 0, maxLen = 0, maxst = 0, st = 0;

    while(1)
    {
        if(sentence[i] == ' ' || sentence[i] == '\0'){
            if(currLen > maxLen){
                maxLen = currLen;
                maxst = st;
            }
            currLen = 0;
            st = i + 1;
        }
        else
            currLen++;
        

        if(sentence[i] == '\0'){
            break;
        }
        i++;
    }

    //printing max word
    for(int i = 0; i < maxLen; i++){
        cout<<sentence[maxst + i];
    }
    cout <<endl<< maxLen << endl;
}