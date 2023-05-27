#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> n)
    {
        ll a = 1;
        int ret = 1;
        while (true)
        {
            if (a % n == 0)
            {
                cout << ret << '\n';
                break;
            }
            else
            {
                a = (a * 10) + 1;
                a %= n;
                ret++;
            }
        }
    }
    return 0;
}