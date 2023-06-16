#include <bits/stdc++.h>
using namespace std;

struct Team
{
    int teamN;
    int teamH;
    int teamS;
};

int n, tn;
vector<Team> v;
string ts;
int score[2];
Team t1;
Team t2;
pair<Team, Team> ret;
Team prev;

Team timeSub(int comH1, int comS1, int comH2, int comS2)
{
    Team tmpT;
    if (comH1 > comH2)
    {
        tmpT.teamH = comH1 - comH2;
        if (comS1 < comS2)
        {
            tmpT.teamH--;
            tmpT.teamS = 60 + comS1 - comS2;
        }
        else
        {
            tmpT.teamS = comS1 - comS2;
        }
    }
    else
    {
        tmpT.teamH = comH2 - comH1;
        if (comS1 > comS2)
        {
            tmpT.teamH--;
            tmpT.teamS = 60 + comS2 - comS1;
        }
        else
        {
            tmpT.teamS = comS2 - comS1;
        }
    }
    return tmpT;
}

void printR()
{
    if (ret.first.teamH < 10)
    {
        cout << '0';
    }
    cout << ret.first.teamH << ":";
    if (ret.first.teamS < 10)
    {
        cout << '0';
    }
    cout << ret.first.teamS << '\n';
    if (ret.second.teamH < 10)
    {
        cout << '0';
    }
    cout << ret.second.teamH << ":";
    if (ret.second.teamS < 10)
    {
        cout << '0';
    }
    cout << ret.second.teamS << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tn >> ts;
        string tmph = "";
        string tmps = "";
        for (int i = 0; i < 2; i++)
        {
            tmph += ts[i];
        }

        for (int i = 0; i < 2; i++)
        {
            tmps += ts[i + 3];
        }
        v.push_back({tn, stoi(tmph), stoi(tmps)});
    }
    bool flag = 0;
    for (auto it : v)
    {
        if (it.teamN == 1)
            score[0]++;
        if (it.teamN == 2)
            score[1]++;
        if (score[0] > score[1] && flag == 0){
            t1.teamH = it.teamH;
            t1.teamS = it.teamS;
            flag = 1;
        }
        else if (score[0] < score[1] && flag == 0){
            t2.teamH = it.teamH;
            t2.teamS = it.teamS;
            flag = 1; 
        }
        if(score[0] == score[1]){
            flag = 0;
            if(it.teamN == 2){
                ret.first.teamH = it.teamH - t1.teamH;
                ret.first.teamS = it.teamS - t1.teamS;
            }
            if(it.teamN == 1){
                ret.second.teamH = it.teamH - t2.teamH;
                ret.second.teamS = it.teamS - t2.teamS;
            }
        }
    }

    if (score[0] > score[1])
    {
        ret.first = timeSub(48, 00, t1.teamH, t1.teamS);
    }
    else if (score[0] < score[1])
    {
        ret.second = timeSub(48, 00, t2.teamH, t2.teamS);
    }
    printR();
}