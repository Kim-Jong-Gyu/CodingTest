// #include<bits/stdc++.h>
// using namespace std;
// 1. map을 이용한 counting
// int num;
// map<char, int> mp;
// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> num;
//     string name;
//     int count = 0;
//     for(int i = 0; i < num; i++){
//         cin >> name;
//         mp[name[0]] += 1;
//     }
//     for(auto it = mp.begin(); it != mp.end(); it++){
//         if((*it).second >= 5){
//             cout << (*it).first;
//             count++;
//         }
//     }
//     if(count == 0){
//         cout << "PREDAJA";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int num;
string name, str;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> name;
        cnt[name[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] >= 5)
            str += (i + 'a');
    }
    if (str.size())
        cout << str << '\n';
    else
        cout << "PREDAJA" << '\n';
}