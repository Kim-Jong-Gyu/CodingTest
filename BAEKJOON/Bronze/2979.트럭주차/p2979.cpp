#include <bits/stdc++.h>
using namespace std;

int f[3];
int result[100];
pair<int, int> p1;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> f[0] >> f[1] >> f[2];
    for(int i = 0; i < 3; i++){
         cin >> p1.first >> p1.second;
         for(int j = p1.first; j < p1.second; j++){
            result[j]++;
         }
    }
    int sum = 0;
    for(int i = 0; i < 100; i++){
        sum+=result[i] * f[result[i] - 1]; 
    }
    cout << sum;
}