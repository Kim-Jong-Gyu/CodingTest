#include <bits/stdc++.h>
using namespace std;

int a,b,c,n;
int scv[4];
int visited[64][64][64];
int attack[6][3]= {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};

struct A{
    int a, b, c;
};

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> scv[i];
    }
    queue<A> q;
    q.push({scv[0], scv[1], scv[2]});
    visited[scv[0]][scv[1]][scv[2]] = 1;
    while(q.size()){
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++){
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);
            if(visited[na][nb][nc]) continue;
            q.push({na,nb,nc});
            visited[na][nb][nc] = visited[a][b][c] + 1;
        }
    }
    cout << visited[0][0][0] - 1<< '\n';
}