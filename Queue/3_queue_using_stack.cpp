// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> st, st_help;

    MyQueue() {}

    void push(int x)
    {
        while (!st.empty())
        {
            st_help.push(st.top());
            st.pop();
        }

        st.push(x);

        while (!st_help.empty())
        {
            st.push(st_help.top());
            st_help.pop();
        }
    }

    int pop()
    {
        if (st.empty())
            return -1;

        int ele = st.top();
        st.pop();
        return ele;
    }

    int peek()
    {
        if (st.empty())
            return -1;

        return st.top();
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    MyQueue *q = new MyQueue();
    q->push(1);
    q->push(2);
    q->push(3);
    cout << q->peek() << endl;
    q->pop();
    cout << q->peek() << endl;
    q->pop();
    q->pop();
    cout << q->empty() << endl;

    return 0;
}