#include <iostream>
#include <deque>

using std::cin; using std::cout; using std::endl; using std::string;

int main(void)
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    
    for(auto i: dq)
        cout << i << " ";

    cout << endl;
    
    dq.pop_front();
    dq.pop_back();

    for(int i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";


    return 0;
}