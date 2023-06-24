#include <bits/stdc++.h>
using namespace std;

int tmpy, tmpx, n, m;
vector<pair<int, int>> posCh;
vector<pair<int, int>> posH;
int a[54][54];
int ret = INT_MAX;

int check(vector<pair<int, int>> v){
    int chk = 0;
    for(int i = 0; i < posH.size(); i++){
        int minDis = INT_MAX;
        for(int j = 0; j < v.size(); j++){
            int absR = abs(posH[i].first - v[j].first);
            int absC = abs(posH[i].second - v[j].second);
            int dis = absR + absC;
            minDis = min(minDis, dis);
        }
        chk += minDis;
    }
    return chk;
}

void combi(int start, vector<pair<int,int>> v){
    if(v.size() == m){
        ret = min(ret, check(v));
        return;
    }
    for(int i = start + 1; i < posCh.size(); i++){
        v.push_back({posCh[i].first, posCh[i].second});
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                posCh.push_back({i,j});
            }
            if(a[i][j] == 1){
                posH.push_back({i,j});
            }
        }
    }
    vector<pair<int, int>> v;
    combi(-1, v);
    cout << ret << '\n';
}