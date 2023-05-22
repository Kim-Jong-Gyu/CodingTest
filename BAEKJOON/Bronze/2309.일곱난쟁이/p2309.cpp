// #include <bits/stdc++.h>
// using namespace std;

/*
// 1. 순열 방식으로 접근
int n = 9;
int input[9];
void solve()
{
    do
    {
        int sum = 0;
        for (int i = 0; i < 7; i++)
        {
            sum += input[i];
        }
        if (sum == 100)
            break;
    } while (next_permutation(input, input + 9));
    for (int i = 0; i < 7; i++)
    {
        cout << input[i] << '\n';
    }
    return;
}

int main()
{
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + 9);
    solve();
}
*/

// 2. 순열 (재귀함수 사용)
#include <cstdio> 
#include <vector> 
#include <algorithm> 
#include <iostream>
using namespace std; 

int input[9];
int n = 9, r= 7;
void solve()
{
    int sum = 0;
    for(int i = 0; i < r; i++){
        sum += input[i];
    }
    if(sum == 100){
        sort(input, input + 7);
        for(int i =0; i < r; i++){
            cout << input[i] << '\n';
        }
        exit(0);
    }
}

void makePermutation(int n, int r, int depth)
{
    if (r == depth)
    {
        solve();
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(input[i], input[depth]);
        makePermutation(n, r, depth + 1);
        swap(input[i], input[depth]);
    }
    return;
}
int main()
{
    for (int i = 0; i < 9; i++)
        cin >> input[i];
    makePermutation(9, 7, 0);
    return 0;
}
    /*
    3. 조합을 통한 접근방식
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
    */