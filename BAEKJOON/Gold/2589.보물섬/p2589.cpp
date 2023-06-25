#include<bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, y, x;
char a[54][54];
int visited[54][54];
int ret;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            cin >> a[i][j];
        }
    }
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L' && visited[i][j] == 0){
                q.push({i,j});
                visited[i][j] = 1;
                while(q.size()){
                    tie(y,x) = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                        if(a[ny][nx] == 'L' && visited[ny][nx] == 0){
                            q.push({ny, nx});
                            visited[ny][nx] = visited[y][x] + 1;
                        }
                    }
                }
                ret = max(ret, visited[y][x] - 1);
                fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
            }
        }
    }
    cout << ret << '\n';
}