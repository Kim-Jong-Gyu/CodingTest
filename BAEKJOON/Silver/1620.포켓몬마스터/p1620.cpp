#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string ret2[1000004];
int n , m, pos;
string q[1000004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    string name;
    for(int i = 0; i < n; i++){
        cin >> name;
        mp[name] = i + 1;
        ret2[i + 1] = name;
    }
    for(int i = 0; i < m; i++){
        cin >> q[i];
    }
    for(int i = 0; i < m; i++){
        pos = atoi(q[i].c_str());
        if(pos == 0){
            cout << mp[q[i]] << '\n';
        }
        else{
            cout << ret2[pos] << '\n';
        }
    }
}