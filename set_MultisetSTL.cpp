#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    //print the set. method #01
    for(auto i: s)
        cout << i << " ";
    cout << '\n';

    //print the set. method #02
    for(auto i = s.begin(); i != s.end(); i++)
        cout << *i << ' ';
    cout << '\n';

    set<int, greater<int>> s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(20);
    s2.insert(30);

    s2.erase(20);
    s2.erase(s2.begin());

    for(auto i: s2)
        cout << i << ' ';

    cout << '\n' << "size: " << s2.size() << '\n';

    multiset<int> s3;
    s3.insert(7);
    s3.insert(1);
    s3.insert(1);
    s3.insert(5);
    s3.insert(2);

    for(auto i: s3)
        cout << i << ' ';
    
    cout << '\n';
    s3.erase(1);
    s3.erase(s3.find(1));
    for(auto i: s3)
        cout << i << ' ';
    
    cout << '\n';

    unordered_set<int> s4;
    s4.insert(5);
    s4.insert(2);
    s4.insert(7);
    s4.insert(7);
    s4.insert(1);

    for(auto i: s4)
        cout << i << ' ';

    cout << '\n';
    s4.erase(s4.find(1));
    for(auto i: s4)
        cout << i << ' ';

    cout << '\n';



    return 0;
}
