#include<bits/stdc++.h>
using namespace std;


int ret[104][104];
int h, w;
string s;

int main(){
    cin >> h >> w;
    fill(&ret[0][0], &ret[0][0] + 104 * 104, -1);
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'c'){
                for(int k = j; k < s.size(); k++){
                    ret[i][k] = k - j;
                }
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }
}