#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, maxV, minV;
int mp[104][104];
int visited[104][104];
vector<int> v;

void dfs(int y, int x, int h)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny > n || nx > n)
            continue;
        if (visited[ny][nx] == 0 && mp[ny][nx] > h)
        {
            dfs(ny, nx, h);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
        }
    }
    maxV = *max_element(&mp[0][0], &mp[n][n]);
    for (int i = 0; i <= maxV; i++)
    {
        int ret = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (visited[j][k] == 0 && mp[j][k] > i)
                {
                    dfs(j, k, i);
                    ret++;
                }
            }
        }
        v.push_back(ret);
        memset(visited, 0, sizeof(visited));
    }
    int result = *max_element(v.begin(), v.end());
    cout << result << '\n';
}