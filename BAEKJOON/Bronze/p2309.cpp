#include <bits/stdc++.h>
using namespace std;
int n = 9;
int input[9];
int sum;
pair<int, int> p;

void solve(vector<int> v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(sum - input[i] - input[j] == 100){
                p = make_pair(i,j);
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += input[i];
    }
    solve(v);
    for(int i = 0; i < n; i++){
        if(p.first != i && p.second != i){
            v.push_back(input[i]);
        }
    }
    sort(v.begin(), v.end());
    for(int i : v){
        cout << i << '\n';
    }
    return 0;
}