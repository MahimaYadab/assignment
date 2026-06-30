//removing adjacent duplicates in string using stack
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string correctTyping(string s)
{
    stack<char> st;

    for(char ch : s)
    {
        if(!st.empty() && st.top() == ch)
            st.pop();
        else
            st.push(ch);
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

int main()
{
    string s;
    cin >> s;

    cout << "Corrected Text: " << correctTyping(s);

    return 0;
}
