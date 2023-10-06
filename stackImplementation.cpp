#include <iostream>
using namespace std;

#define N 100

class stack{
private:
    int *arr;
    int top;
public:
    stack(){
        arr = new int[N];
        top = -1;
    }
    
    void push(int x)
    {
        if(top == N - 1){
            cout << "Stack overflow\n";
            return;
        }        
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "No element to pop\n";
            return;
        }

        top--;
    }

    int Top()
    {
        if(top == -1)
        {
            cout << "No element to pop\n";
            return -1;
        }

        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};

int main(void)
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    return 0;
}