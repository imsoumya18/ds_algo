// @author Soumya
#include <iostream>
#include <stack>
#include <algorithm>
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

string infix_to_prefix(string infix)
{
    string prefix = "";
    stack<char> st;

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++)
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';

    for (auto it : infix)
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z') || (it >= '0' && it <= '9'))
            prefix += it;
        else if (it == '(')
            st.push(it);
        else if (it == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }

            st.pop();
        }
        else
        {
            if (it == '^')
                while (!st.empty() && priority(st.top()) >= priority(it))
                {
                    prefix += st.top();
                    st.pop();
                }
            else
                while (!st.empty() && priority(st.top()) > priority(it))
                {
                    prefix += st.top();
                    st.pop();
                }

            st.push(it);
        }

    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infix_to_prefix(infix) << endl;

    return 0;
}