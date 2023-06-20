#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;

bool go(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '(')
            stk.push(s[i]);
        else if (s[i] == ']')
        {
            if (!stk.empty())
            {
                if (stk.top() == '[')
                    stk.pop();
                else
                    return false;
            }
            else
                return false;
        }
        else if (s[i] == ')')
        {
            if (!stk.empty())
            {
                if (stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    return (stk.empty());
}

int main()
{
    while (true)
    {
        getline(cin, s);
        if (s == ".")
            break;
        if (go(s))
            v.push_back("yes");
        else
            v.push_back("no");
    }
    for (string it : v)
        cout << it << '\n';
}