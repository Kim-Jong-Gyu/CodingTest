#include<bits/stdc++.h>
using namespace std;

int n;
int start = 666;
int cnt;

int main(){
    cin >> n;
    while(true){
        string tmp = to_string(start);
        auto it = tmp.find("666");
        if(it != string::npos){
            cnt++;
        }
        if(cnt == n)
            break;
        start++;
    }
    cout << start << '\n';
}