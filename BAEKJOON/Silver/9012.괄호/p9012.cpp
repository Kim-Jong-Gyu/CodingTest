#include <bits/stdc++.h>
using namespace std;
// 1. 첫번째 접근
// int n;
// string s;
// vector<string> v;

// int main(){
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> s;
//         int cnt = 0;
//         for(int j = 0; j < s.size(); j++){
//             if(s[j] == '('){
//                 cnt++;
//             }
//             if(s[j] == ')'){
//                 cnt--;
//             }
//             if(cnt < 0){
//                 break;
//             }
//         }
//         if(cnt != 0){
//             v.push_back("NO");
//         }
//         else{
//             v.push_back("YES");
//         }
//     }
//     for(string it : v){
//         cout << it << '\n';
//     }
// }


int n;
string s;
vector<string> v;

bool check(string s){
    stack<char> stk;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') stk.push(s[i]);
        else{
            if(!stk.empty()) stk.pop();
            else{
                return false;
            }
        }
    }
    return stk.empty();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(check(s)) v.push_back("YES");
        else v.push_back("NO"); 
    }
    for(string it: v){
        cout << it << '\n';
    }
}