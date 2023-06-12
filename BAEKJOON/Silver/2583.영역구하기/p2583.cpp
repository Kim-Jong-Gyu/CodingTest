#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int mp[104][104];
int visited[104][104];
int ldx, ldy, rux, ruy;
int m, n, k, ny, nx, ret, cnt;


vector<int> v;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (!visited[ny][nx] && mp[ny][nx] == 1)
        {
            ret++;
            dfs(ny, nx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    fill(&mp[0][0], &mp[0][0] + 104 * 104, 1);
    for (int i = 0; i < k; i++)
    {
        cin >> ldx >> ldy >> rux >> ruy;
        for (int j = ldy; j < ruy; j++)
        {
            for (int l = ldx; l < rux; l++)
            {
                mp[j][l] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && mp[i][j] == 1)
            {
                dfs(i, j);
                cnt++;
                v.push_back(ret + 1);
                ret = 0;
            }
        }
    }
    cout << cnt << '\n';
    sort(v.begin(),v.end());
    for (int e : v)
    {
        cout << e << " ";
    }
}