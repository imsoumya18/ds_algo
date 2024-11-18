// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

string postfix_to_infix(string postfix)
{
    string infix = "";
    stack<string> st;

    for (auto it : postfix)
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z') || (it >= '0' && it <= '9'))
            st.push("" + it);
        else
        {
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();

            st.push("(" + a + it + b + ")");
        }

    return st.top();
}

int main()
{
    string postfix = "ab+ef*-";

    cout << postfix_to_infix(postfix) << endl;

    return 0;
}