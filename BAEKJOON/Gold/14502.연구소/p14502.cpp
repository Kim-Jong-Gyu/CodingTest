#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, r;
int mp[10][10];
int visited[10][10];
int ret;
vector<pair<int, int>> wallList, virusList;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (visited[ny][nx] == 1 || mp[ny][nx] == 1)
            continue;
        dfs(ny, nx);
    }
}

int solve()
{
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (pair<int, int> b : virusList)
    {
        dfs(b.first, b.second);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 0 && visited[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 0)
                wallList.push_back({i, j});
            if (mp[i][j] == 2)
                virusList.push_back({i, j});
        }
    }
    for (int i = 0; i < wallList.size(); i++)
    {
        for (int j = i + 1; j < wallList.size(); j++)
        {
            for (int k = j + 1; k < wallList.size(); k++)
            {
                mp[wallList[i].first][wallList[i].second] = 1;
                mp[wallList[j].first][wallList[j].second] = 1;
                mp[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                mp[wallList[i].first][wallList[i].second] = 0;
                mp[wallList[j].first][wallList[j].second] = 0;
                mp[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << '\n';
}
