#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;

vector<int> resultList;
vector<int> v[10004];
int visited[10004];

int dfs(int here){
    visited[here] = 1;
    int chk = 1;
    for(int there : v[here]){
        if(visited[there] == 1) continue;
        chk+=dfs(there);
    }
    return chk;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 0; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        resultList.push_back(dfs(i));
    }
    int max = *max_element(resultList.begin(), resultList.end());
    for(int i = 0; i <= n; i++){
        if(max == resultList[i]){
            cout << i << " ";
        }
    }
    cout << '\n';
    return 0;
}