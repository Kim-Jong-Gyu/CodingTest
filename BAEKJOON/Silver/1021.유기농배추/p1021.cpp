#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t, m, n, k, tmpy, tmpx;
int mp[54][54];
int visited[54][54];

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny > n || nx > m || ny < 0 || nx < 0)
            continue;
        if (!visited[ny][nx] && mp[ny][nx] == 1)
            dfs(ny, nx);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    vector<int> v;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> tmpy >> tmpx;
            mp[tmpy][tmpx] = 1;
        }
        int ret = 0;
        for (int l = 0; l < n; l++)
        {
            for (int p = 0; p < m; p++)
            {
                if (visited[l][p] == 0 && mp[l][p] == 1)
                {
                    dfs(l, p);
                    ret++;
                }
            }
        }
        memset(mp, 0, sizeof(mp));
        memset(visited, 0, sizeof(visited));
        v.push_back(ret);
    }
    for(int result: v){
        cout << result << '\n';
    }
}