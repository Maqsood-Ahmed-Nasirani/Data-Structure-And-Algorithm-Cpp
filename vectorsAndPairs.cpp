#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    v.push_back(9);

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl; // 3 5 6 9

    vector<int> :: iterator it;
    for(it = v.begin(); it != v.end(); it++)
        cout << *it << endl; // 3 5 6 9
    
    
    for(auto i: v)
        cout << i << endl; // 3 5 6 9


    v.pop_back(); // 3 5 6

    vector<int> v2 (3, 50);// (size, value of x size)
    // 50 50 50 

    swap(v, v2); // all the elements have been swaped

    sort(v2.begin(), v2.end());

    pair<int, char> p;
    p.first = 123;
    p.second = 'm';

}