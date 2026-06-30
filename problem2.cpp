#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string process(string s)
{
    stack<char> st;

    for(char ch : s)
    {
        if(ch == '#')
        {
            if(!st.empty())
                st.pop();
        }
        else
        {
            st.push(ch);
        }
    }

    string ans = "";

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

bool backspaceCompare(string s, string t)
{
    return process(s) == process(t);
}

int main()
{
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if(backspaceCompare(s, t))
        cout << "Both strings are same after applying backspace.";
    else
        cout << "Both strings are different after applying backspace.";

    return 0;
}
