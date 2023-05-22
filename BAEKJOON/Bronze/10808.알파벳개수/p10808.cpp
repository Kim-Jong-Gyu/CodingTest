#include <bits/stdc++.h>
using namespace std;
int result[26];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input;
    cin >> input;
    for (char a : input)
    {
        result[a - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << result[i];
        if (i != 25)
        {
            cout << " ";
        }
    }
    return 0;
}