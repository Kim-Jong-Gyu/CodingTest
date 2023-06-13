#include <bits/stdc++.h>
using namespace std;

int n, c, tmp;
map<int, int> mp, pos_mp;
vector<pair<int, int>> v;

int cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p2.second > p1.second)
    {
        return 1;
    }
    if (p2.second == p1.second && pos_mp[p2.first] < pos_mp[p1.first])
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (mp[tmp] == 0)
        {
            pos_mp[tmp] = i;
        }
        mp[tmp] += 1;
    }

    for (auto it : mp)
    {
        v.push_back({(it).first, (it).second});
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (cmp(v[i], v[j]))
            {
                swap(v[i], v[j]);
            }
        }
    }
    for (auto it : v)
    {
        for (int i = 0; i < it.second; i++)
        {
            cout << it.first << " ";
        }
    }
}