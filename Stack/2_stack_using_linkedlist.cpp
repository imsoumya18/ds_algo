// @author Soumya
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// push, pop, peek, empty: Time O(1) each | Space: O(1) each (grows/shrinks with the list)
class stack
{
    node *head;

public:
    stack()
    {
        head = NULL;
    }

    void push(int x)
    {
        node *nd = new node(x);

        nd->next = head;
        head = nd;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty!!" << endl;
            return;
        }

        head = head->next;
    }

    int peek()
    {
        if (head == NULL)
        {
            cout << "Stack is empty!!" << endl;
            return -1;
        }

        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    /* stack (top to bottom):
         | 5 | <- top
         | 4 |
         | 3 |
         | 2 |
         | 1 |
         -----
    */

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    st.pop(); // underflow: prints "Stack is empty!!"

    cout << st.empty() << endl;

    return 0;
}
