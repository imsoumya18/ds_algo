// @author Soumya
#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q, q_help;

    MyStack() {}

    void push(int x)
    {
        q_help.push(x);

        while (!q.empty())
        {
            q_help.push(q.front());
            q.pop();
        }

        swap(q, q_help);
    }

    int pop()
    {
        if (q.empty())
            return -1;

        int ele = q.front();
        q.pop();
        return ele;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

int main()
{
    MyStack *st = new MyStack();
    st->push(1);
    st->push(2);
    st->push(3);
    cout << st->top() << endl;
    st->pop();
    cout << st->top() << endl;
    st->pop();
    st->pop();
    st->pop();
    cout << st->empty() << endl;

    return 0;
}