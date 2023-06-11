#include <bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[104][104];
int mp[104][104];
string s;
int n, m, y, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s; 
        for (int j = 0; j < s.size(); j++)
        {
            mp[i][j] = s[j] - '0';
        }
    }
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny > n || nx > m)
                continue;
            if (visited[ny][nx])
                continue;
            if (mp[ny][nx] == 0)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n - 1][m - 1] << '\n';
}
