#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int mp[104][104], visited[104][104];
int edge[104][104];
int n, m, y, x, ret;



int solve(){
    int cnt = 0;
    int cmp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == 1){
                cnt++;
            }
            if(mp[i][j] == 1 && edge[i][j] == 1){
                cmp++;
            }
        }
    }
    if(cmp == cnt)
        return cmp;
    return 0;
}

void deleteEdge(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(edge[i][j] == 1){
                mp[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }
    queue<pair<int, int>> q;
    int cnt = 0;
    while (true)
    {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        fill(&edge[0][0], &edge[0][0] + 104 * 104, 0);
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
                if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                    continue;
                if (mp[ny][nx] == 1 && visited[ny][nx] == 0)
                    edge[ny][nx] = 1;
                if(mp[ny][nx] == 1 || visited[ny][nx] == 1)
                    continue;
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
        cnt++;
        if(solve()){
            cout << cnt << '\n';
            cout << solve() << '\n';
            break;
        }
        else{
            deleteEdge();
        }
    }
}