// @author Soumya
#include <iostream>
#include <stack>
using namespace std;

// Time: O(n^2) worst case - each "(" + a + it + b + ")" allocates and copies a
// new string, and these strings can grow to O(n) length, so the total copying
// work is quadratic (same trap as building a string with += in a loop)
// Space: O(n) for the stack of partial expressions
string postfix_to_infix(string postfix)
{
    string infix = "";
    stack<string> st;

    for (auto it : postfix)
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z') || (it >= '0' && it <= '9'))
            st.push(string(1, it));
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