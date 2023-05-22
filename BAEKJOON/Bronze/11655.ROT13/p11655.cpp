#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    getline(cin,s);
    int tmp;
    for(int i = 0; i < s.size(); i++){
        tmp = s[i];
        if(tmp >= 'A' && tmp <= 'Z'){
            if((tmp + 13) > 'Z'){
                s[i] = tmp  + 13 - 26;
            }
            else{
                s[i] = tmp + 13;
            }
        }
        if(tmp >= 'a' && tmp <= 'z'){
            if((tmp + 13) > 'z'){
                s[i] = tmp + 13 - 26;
            }
            else{
                s[i] = tmp + 13; 
            }
        }
    }
    cout << s << '\n';
}