#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){

    // string str(5, 'M');//(times, character x times)
    // cout << str;

    // string s1 = "fam";
    // string s2 = "ily";

    // // s1.append(s2);
    // // cout<<s1 + s2<<endl;
    // s1 = s1 + s2;
    // cout<<s1<<endl;

    // string abc = "abcdsaf dfasfjslfjlsk sfasfd";
    // abc.clear();
    // cout << abc <<endl;

    string s3 = "abcde";
    // string s4 = "abc";
    cout << s3.find("cd");
    s3.erase(1, 2);//(index, character x times to delete)

    s3.insert(1, "bc"); //(index, what to insert)
    string s = s3.substr(1, 3);
    cout << s <<endl;


    string n = "600";
    int x = stoi(n);
    cout << to_string(x) + "12" << endl;

    string unstr = "bcdfsafh";

    sort(unstr.begin(), unstr.end());

    cout << unstr << endl;

    // s3.empty();

    // if(!(s3.compare(s4)))
    //     cout << "Equal\n";

    // if(s3.compare(s4) == 0){
    //     cout << "Equal\n";
    // }

}