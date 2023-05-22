/*
1. 인덱스를 통한 방식
#include <bits/stdc++.h>
using namespace std;
string str;
int solve(int mid)
{
    int idx = 0;
    for (idx = 0; idx < mid; idx++)
    {
        if (str[idx] != str[str.size() - 1 - idx])
            break;
    }
    if (idx == mid)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin >> str;
    int mid = str.size() / 2;
    cout << solve(mid);
}
*/
// 2. reverse를 사용하는 방법
#include <bits/stdc++.h>
using namespace std;

string str, tmp;
int main(){
    cin >> str;
    tmp = str;
    reverse(tmp.begin(), tmp.end());
    if(tmp == str) cout << 1;
    else cout << 0;
    return 0;
}