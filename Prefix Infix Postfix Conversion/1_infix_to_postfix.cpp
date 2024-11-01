// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;

    if (c == '*' || c == '/')
        return 2;

    if (c == '+' || c == '-')
        return 1;

    return -1;
}

string infix_to_postfix(string infix)
{
    string postfix = "";
    stack<char> st;

    for (auto it : infix)
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z') || (it >= '0' && it <= '9'))
            postfix += it;
        else if (it == '(')
            st.push(it);
        else if (it == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(st.top()) >= priority(it))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(it);
        }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infix_to_postfix(infix) << endl;

    return 0;
}