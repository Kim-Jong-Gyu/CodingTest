#include <bits/stdc++.h>
using namespace std;

int n, m, p, j;
vector<int> v;
queue<int> q;
int ret;


void add()
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] += 1;
    }
}

void sub()
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] -= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> j;
    for (int i = 0; i < j; i++)
    {
        cin >> p;
        q.push(p);
    }
    for (int i = 1; i <= m; i++)
    {
        v.push_back(i);
    }

    int cnt = 0;
    while (q.size())
    {
        int pos = q.front();
        if (*find(v.begin(), v.end(), pos))
        {
            q.pop();
            ret += cnt;
            cnt = 0;
        }
        else
        {
            if (pos < v.front())
            {
                sub();
                cnt++;
            }
            else
            {
                add();
                cnt++;
            }
        }
    }
    cout << ret << '\n';
}