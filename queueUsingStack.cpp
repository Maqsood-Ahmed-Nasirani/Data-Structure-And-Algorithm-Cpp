#include <iostream>
#include <stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    public:
    
    void enqueue(int val){
        s1.push(val);
    }

    int dequeue(){
        if(s1.empty() && s2.empty()){
            cout << "Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

int main(void)
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << endl;
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
  
    return 0;
}