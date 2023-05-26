#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int a[15004];
int ret;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i]+a[j] == m){
                ret++;        
            }
        }
    }
    cout << ret << '\n';
}