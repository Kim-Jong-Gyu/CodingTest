#include <bits/stdc++.h>
using namespace std;
int n, c;
string cat, name;
vector<int> result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        map<string, int> mp;
        cin >> c;
        int ret = 1;
        for (int j = 0; j < c; j++)
        {
            cin >> name >> cat;
            mp[cat] += 1;
        }
        for (auto a : mp)
        {
            ret *= (a.second + 1);
        }
        ret-=1;
        result.push_back(ret);
    }
    for(auto i : result){
        cout << i << '\n';
    }
}