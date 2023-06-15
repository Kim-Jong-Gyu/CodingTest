#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int t;
ll num;
vector<int> result;
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> num;
        int ret2 = 0;
        int ret5 = 0;
        for (int j = 2; j <= num; j *= 2)
        {
            ret2 += num / j;
        }
        for (int j = 5; j <= num; j *= 5)
        {
            ret5 += num / j;
        }
        result.push_back(min(ret2, ret5));
    }
    for(int a : result){
        cout << a << '\n';
    }
}