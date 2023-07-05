#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<char> ch;
vector<int> num;
int ret = INT_MIN;

int calculate(int a, char ch, int b){
    if(ch == '+')
        return a + b;
    if(ch == '-')
        return a - b;
    if(ch == '*')
        return a * b;
}

void go(int here, int result){
    if(here == num.size() - 1){
        ret = max(ret, result);
        return;
    }
    go(here + 1, calculate(result, ch[here], num[here + 1]));

    if(here + 2 <= num.size() - 1){
        int tmp = calculate(num[here + 1], ch[here + 1], num[here + 2]);
        go(here + 2, calculate(result, ch[here],tmp));
    }
    return;
}

int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '*' || s[i] == '+' || s[i] == '-')
            ch.push_back(s[i]);
        else
            num.push_back(s[i] - '0');
    }
    go(0, num[0]);
    cout << ret << '\n';
}