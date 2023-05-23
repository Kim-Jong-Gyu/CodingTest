// 1. 정규식 표현을 이용
// #include <bits/stdc++.h>
// using namespace std;
// string s[100], pat;
// int num;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> num;
//     cin >> pat;
//     pat.replace(pat.find('*'), 1, "\\w*");
//     regex re(pat);
//     for(int i = 0; i < num; i++){
//         cin >> s[i];
//     }
//     for(int i = 0; i < num; i++){
//         if(regex_match(s[i], re)){
//             cout << "DA" << '\n';
//         }
//         else{
//             cout << "NE" << '\n';
//         }
//     }
//     return 0;
// }
// 2. substr 방식
#include <bits/stdc++.h>
using namespace std;
int num;
string pat;
string s[100];
string pre, suf;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num;
    cin >> pat;
    long long pos = pat.find('*');
    pre = pat.substr(0, pos);
    suf = pat.substr(pos + 1);
    for (int i = 0; i < num; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < num; i++)
    {
        if (pre.size() + suf.size() > s[i].size())
        {
            cout << "NE" << '\n';
        }
        else
        {
            if (s[i].substr(0, pre.size()) == pre && s[i].substr(s[i].size() - suf.size()) == suf)
            {
                cout << "DA" << '\n';
            }
            else
            {
                cout << "NE" << '\n';
            }
        }
    }
    return 0;
}