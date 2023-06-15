#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string s;
int n;

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

string eraseZ(string s)
{
    string tmp = s;
    while(true){
        if(tmp.size() && tmp.front() == '0'){
            tmp.erase(tmp.begin());
        }
        else break;
    }
    if(tmp.size() == 0) tmp = "0";
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        string tmp = "";
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] < 97)
            {
                tmp+= s[j];
            }
            else if(tmp.size()){
                tmp = eraseZ(tmp);
                v.push_back(tmp);
                tmp = "";
            }
        }
        if(tmp.size()){
            tmp = eraseZ(tmp);
            v.push_back(tmp);
            tmp = "";
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (string e : v)
    {
        cout << e << '\n';
    }
}
